#define _CRT_SECURE_NO_WARNINGS 1
#include "tuixiangzi.h"

struct MAP all_map[5] =
{ { 8, 8, { { 0, 0, 1, 1, 1, 0, 0, 0 },  //地图一
{ 0, 0, 1, 3, 1, 0, 0, 0 },
{ 0, 0, 1, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 2, 0, 2, 3, 1 },
{ 1, 3, 0, 2, 4, 1, 1, 1 },
{ 1, 1, 1, 1, 2, 1, 0, 0 },
{ 0, 0, 0, 1, 3, 1, 0, 0 },
{ 0, 0, 0, 1, 1, 1, 0, 0 } } },
{ 9, 9, { {1,1,1,1,1,0,0,0,0},   //地图二
{1,4,0,0,1,0,0,0,0},
{1,0,2,2,1,0,1,1,1},
{1,0,2,0,1,0,1,3,1},
{1,1,1,0,1,1,1,3,1},
{0,1,1,0,0,0,0,3,1},
{0,1,0,0,0,1,0,0,1},
{0,1,0,0,0,1,1,1,1},
{0,1,1,1,1,1,0,0,0} } },
{ 7, 10, { { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },  //地图三
{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
{ 1, 1, 2, 1, 1, 1, 0, 0, 0, 1 },
{ 1, 0, 4, 0, 2, 0, 0, 2, 0, 1 },
{ 1, 0, 3, 3, 1, 0, 2, 0, 1, 1 },
{ 1, 1, 3, 3, 1, 0, 0, 0, 1, 0 },
{0,1,1,1,1,1,1,1,1,0} } },
{ 8, 6, { { 0, 1, 1, 1, 1, 0 },    //地图四
{ 1, 1, 0, 0, 1, 0 },
{ 1, 4, 2, 0, 1, 0 },
{ 1, 1, 2, 0, 1, 1 },
{ 1, 1, 0, 2, 0, 1 },
{ 1, 3, 2, 0, 0, 1 },
{ 1, 3, 3, 5, 3, 1 },
{ 1, 1, 1, 1, 1, 1 } } },
{ 8, 8, { { 0, 1, 1, 1, 1, 1, 0, 0 },  //地图五
{ 0, 1, 0, 4, 0, 1, 1, 1 },
{ 1, 1, 0, 1, 2, 0, 0, 1 },
{ 1, 0, 5, 3, 0, 3, 0, 1 },
{ 1, 0, 0, 2, 2, 0, 1, 1 },
{ 1, 1, 1, 0, 1, 3, 1, 0 },
{ 0, 0, 1, 0, 0, 0, 1, 0 },
{ 0, 0, 1, 1, 1, 1, 1, 0 } } } };

void menu()
{
	printf("*****************************\n");
	printf("**********1.开始游戏**********\n");
	printf("**********0.退出游戏**********\n");
	printf("*****************************\n");
}

void find_man(char(*map)[COL], const int* row, const int* col, int* x, int* y)
{
	int i = 0;
	for (i = 0; i < *row; i++)
	{
		int j = 0;
		for (j = 0; j < *col; j++) {
			if ((map[i][j] == 4) || ((map)[i][j] == 7)) {
				*x = i;
				*y = j;
			}

		}
	}
}

void print_map(char(*map)[COL], const int* row, const int* col)
{
	int i = 0;

	printf("\n-------------\n\n");
	for (i = 0; i < *row; i++)
	{
		int j = 0;
		for (j = 0; j < *col; j++)
		{
			switch ((map[i][j]))
			{
			case 0:printf("  ");
				break;
			case 1: printf("■");
				break;
			case 2:printf("□");
				break;
			case 3:printf("◎");
				break;
			case 4:printf("♀");
				break;
			case 5:printf("★");
				break;
			case 7:printf("＠");
				break;
			}
		}
		printf("\n");
	}
	printf("\nW A S D控制角色的上下左右");
	printf("\n■是墙，□是箱子，◎是目标\n♀是玩家,★表示箱子在目标上，＠表示人在目标上");
	printf("\n-------------------\n\n");
}
int is_win(char(*map)[COL], const int* row, const int* col)
{
	int dest = 0;
	int i = 0;
	for (i = 0; i < *row; i++) 
	{
		int j = 0;
		for (j = 0; j < *col; j++)
		{
			if ((map[i][j] == 2) || (map[i][j] == 7))
				return 0;
		}
	}
	return 1;
}
void player_act(char(*map)[COL], int* x, int* y)
{
	char input = 0;
	switch (input = _getch())
	{
	case 'W':
	case 'w':
	case 38:
	   {
		if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 4;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 4;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 7;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 7;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 4;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 4;
			map[(*x) - 2][*y] = 2;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 0)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 4;
			map[(*x) - 2][*y] = 2;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 4;
			map[(*x) - 2][*y] = 5;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 4;
			map[(*x) - 2][*y] = 5;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3)
		{
			map[*x][*y] = 3;
			map[(*x) - 1][*y] = 7;
			map[(*x) - 2][*y] = 5;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 7;
			map[(*x) - 2][*y] = 2;
			--* x;
		}
		else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3)
		{
			map[*x][*y] = 0;
			map[(*x) - 1][*y] = 7;
			map[(*x) - 2][*y] = 5;
			--* x;
		}
	   }
	   break;
	case 'S':
	case 's':
	case 40: 
	{
		if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 4;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 4;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 7;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 7;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 4;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 4;
			map[(*x) + 2][*y] = 2;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 0)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 4;
			map[(*x) + 2][*y] = 2;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 4;
			map[(*x) + 2][*y] = 5;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 4;
			map[(*x) + 2][*y] = 5;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3)
		{
			map[*x][*y] = 3;
			map[(*x) + 1][*y] = 7;
			map[(*x) + 2][*y] = 5;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 7;
			map[(*x) + 2][*y] = 2;
			++* x;
		}
		else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3)
		{
			map[*x][*y] = 0;
			map[(*x) + 1][*y] = 7;
			map[(*x) + 2][*y] = 5;
			++* x;
		}
	}
	  break;
	case 'A':
	case 'a':
	case 37:
	{
		if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 4;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 4;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 7;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 7;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 4;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 4;
			map[*x][(*y) - 2] = 2;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 0)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 4;
			map[*x][(*y) - 2] = 2;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 4;
			map[*x][(*y) - 2] = 5;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 4;
			map[*x][(*y) - 2] = 5;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3)
		{
			map[*x][*y] = 3;
			map[*x][(*y) - 1] = 7;
			map[*x][(*y) - 2] = 5;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 7;
			map[*x][(*y) - 2] = 2;
			--* y;
		}
		else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3)
		{
			map[*x][*y] = 0;
			map[*x][(*y) - 1] = 7;
			map[*x][(*y) - 2] = 5;
			--* y;
		}
	}
	  break;
	case 'D':
	case 'd':
	case 39:
	{
		if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 4;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 4;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 7;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 4)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 7;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 4;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 4;
			map[*x][(*y) + 2] = 2;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 0)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 4;
			map[*x][(*y) + 2] = 2;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 3)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 4;
			map[*x][(*y) + 2] = 5;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 4;
			map[*x][(*y) + 2] = 5;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 3)
		{
			map[*x][*y] = 3;
			map[*x][(*y) + 1] = 7;
			map[*x][(*y) + 2] = 5;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 7;
			map[*x][(*y) + 2] = 2;
			++* y;
		}
		else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3)
		{
			map[*x][*y] = 0;
			map[*x][(*y) + 1] = 7;
			map[*x][(*y) + 2] = 5;
			++* y;
		}
	}
	break;
	}
}

void game()
{
	int i = 0;
	int x = 0;
	int y = 0;
	struct MAP* pmap = NULL;
	printf("\n\n现在游戏有%d关，你要从第几关开始？>:", 5);
	scanf_s("%d", &i);
	pmap = all_map + i - 1; 
	find_man(pmap->map, &(pmap->row), &(pmap->col), &x, &y);
	while (1)
	{
		system("cls");
		print_map(pmap->map, &(pmap->row), &(pmap->col));
		player_act(pmap->map, &x, &y);
		if (is_win(pmap->map, &(pmap->row), &(pmap->col)) && i < 5)
		{
			system("cls");
			print_map(pmap->map, &(pmap->row), &(pmap->col));
			printf("你真棒，小子\n");
			system("pause");
			pmap++;
			x = 0;
			y = 0;
			i++;
			find_man(pmap->map, &(pmap->row), &(pmap->col), &x, &y);
		}
		else if (i == 5) {
			printf("你通关了");
		
		}
	}
}
