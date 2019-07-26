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
	printf("��ѡ��");
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
			printf("���ź���������!\n");
		if (win == '*')
			printf("��ϲ����Ӯ��!\n");
		if (win == 'q')
			printf("ƽ��\n");
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
			printf("���ź���������!\n");
		if (win == '*')
			printf("��ϲ����Ӯ��!\n");
			break;
		if (win == 'q')
			printf("ƽ��\n");
		break;
	default:
		printf("�����������������\n");
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
		printf("��ѡ��:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������.\n");
			break;
		}
	} while (choice);
	return 0;
}