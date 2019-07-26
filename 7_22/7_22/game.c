#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void show_board(char board[ROWS][COLS], int rows, int cols)
{
	int i;
	for (int i = 0; i < rows; i++)
	{
		printf("  %c | %c | %c  \n", board[i][0], board[i][1], board[i][2]);
		if (i != rows - 1)
			printf(" ---|---|--- \n");
	}
}

void init_board(char board[ROWS][COLS], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void computer_move(char board[ROWS][COLS], int rows, int cols)
{
	int x, y, i;
	printf("电脑落子:\n");
	while (1)
	{
		x = rand() % rows;
		y = rand() % cols;
		for (i = 0; i < rows; i++)
		{
			if (board[i][0] == board[i][1] && board[i][0] == '#' && board[i][2] == ' ')
			{
				board[i][2] = '#';
				goto flag1;
			}
			else if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')
			{
				board[i][0] = '#';
				goto flag1;
			}
			else if (board[i][0] == board[i][2] && board[i][2] == '#' && board[i][1] == ' ')
			{
				board[i][1] = '#';
				goto flag1;
			}
			else if (board[0][i] == board[1][i] && board[0][i] == '#' && board[2][i] == ' ')
			{
				board[2][i] = '#';
				goto flag1;
			}
			else if (board[1][i] == board[2][i] && board[1][i] == '#' && board[0][i] == ' ')
			{
				board[0][i] = '#';
				goto flag1;
			}
			else if (board[0][i] == board[2][i] && board[2][i] == '#' && board[1][i] == ' ')
			{
				board[1][i] = '#';
				goto flag1;
			}
			else if (board[0][0] == board[1][1] && board[0][0] == '#' && board[2][2] == ' ')
			{
				board[2][2] = '#';
				goto flag1;
			}
			else if (board[1][1] == board[2][2] && board[1][1] == '#' && board[0][0] == ' ')
			{
				board[0][0] = '#';
				goto flag1;
			}
			else if (board[0][0] == board[2][2] && board[0][0] == '#' && board[1][1] == ' ')
			{
				board[1][1] = '#';
				goto flag1;
			}
			else if (board[0][2] == board[1][1] && board[1][1] == '#' && board[2][0] == ' ')
			{
				board[2][0] = '#';
				goto flag1;
			}
			else if (board[1][1] == board[2][0] && board[1][1] == '#' && board[0][2] == ' ')
			{
				board[0][2] = '#';
				goto flag1;
			}
			else if (board[2][0] == board[0][2] && board[2][0] == '#' && board[1][1] == ' ')
			{
				board[1][1] = '#';
				goto flag1;
			}
		}
		for (i = 0; i < rows; i++)
		{
			if (board[i][0] == board[i][1] && board[i][0] == '*' && board[i][2] == ' ')
			{
				board[i][2] = '#';
				goto flag1;
			}
			else if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')
			{
				board[i][0] = '#';
				goto flag1;
			}
			else if (board[i][0] == board[i][2] && board[i][2] == '*' && board[i][1] == ' ')
			{
				board[i][1] = '#';
				goto flag1;
			}
			else if (board[0][i] == board[1][i] && board[0][i] == '*' && board[2][i] == ' ')
			{
				board[2][i] = '#';
				goto flag1;
			}
			else if (board[1][i] == board[2][i] && board[1][i] == '*' && board[0][i] == ' ')
			{
				board[0][i] = '#';
				goto flag1;
			}
			else if (board[0][i] == board[2][i] && board[2][i] == '*' && board[1][i] == ' ')
			{
				board[1][i] = '#';
				goto flag1;
			}
			else if (board[0][0] == board[1][1] && board[0][0] == '*' && board[2][2] == ' ')
			{
				board[2][2] = '#';
				goto flag1;
			}
			else if (board[1][1] == board[2][2] && board[1][1] == '*' && board[0][0] == ' ')
			{
				board[0][0] = '#';
				goto flag1;
			}
			else if (board[0][0] == board[2][2] && board[0][0] == '*' && board[1][1] == ' ')
			{
				board[1][1] = '#';
				goto flag1;
			}
			else if (board[0][2] == board[1][1] && board[1][1] == '*' && board[2][0] == ' ')
			{
				board[2][0] = '#';
				goto flag1;
			}
			else if (board[1][1] == board[2][0] && board[1][1] == '*' && board[0][2] == ' ')
			{
				board[0][2] = '#';
				goto flag1;
			}
			else if (board[2][0] == board[0][2] && board[2][0] == '*' && board[1][1] == ' ')
			{
				board[1][1] = '#';
				goto flag1;
			}
		}
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			goto flag1;
		}
	}
flag1:;
}

void player_move(char board[ROWS][COLS], int rows, int cols)
{
	int x, y;
	printf("玩家落子:\n");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= rows && y >= 1 && y <= cols)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else printf("位置已被占用！请再试一次。\n");
		}
		else printf("输入错误!请重新输入.\n");
	}
}

static int is_full(char board[ROWS][COLS], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char check_win(char board[ROWS][COLS], int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < cols; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	else if (is_full(board, rows, cols))
		return 'q';
	return 0;
}