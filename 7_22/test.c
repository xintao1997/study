#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"
void menu()
{
	printf("***************************************\n");
	printf("*      1.play             0.exit      *\n");
	printf("***************************************\n");
}
void first_move()
{
	printf("***************************************\n");
	printf("*  1.computer first   2.player first  *\n");
	printf("***************************************\n");
}
void game()
{
	int choice, win;
	char board[ROWS][COLS];
	init_board(board, ROWS, COLS);
	first_move();
flag:
	printf("请选择");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		do
		{
			computer_move(board, ROWS, COLS);
			show_board(board, ROWS, COLS);
			win = check_win(board, ROWS, COLS);
			if (win != 0)
				break;
			player_move(board, ROWS, COLS);
			show_board(board, ROWS, COLS);
			win = check_win(board, ROWS, COLS);
		} while (win == 0);
		if (win == '#')
			printf("很遗憾，你输了!\n");
		if (win == '*')
			printf("恭喜，你赢了!\n");
		if (win == 'q')
			printf("平局\n");
		break;
	case 2:
		show_board(board, ROWS, COLS);
		do
		{
			player_move(board, ROWS, COLS);
			show_board(board, ROWS, COLS);
			win = check_win(board, ROWS, COLS);
			if (win != 0)
				break;
			computer_move(board, ROWS, COLS);
			show_board(board, ROWS, COLS);
			win = check_win(board, ROWS, COLS);
		} while (win == 0);
		if (win == '#')
			printf("很遗憾，你输了!\n");
		if (win == '*')
			printf("恭喜，你赢了!\n");
			break;
		if (win == 'q')
			printf("平局\n");
		break;
	default:
		printf("输入错误，请重新输入\n");
		goto flag;
	}
}
int main()
{
	int choice;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误请重新输入.\n");
			break;
		}
	} while (choice);
	return 0;
}