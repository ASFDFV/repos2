#ifndef __TUIXIANGZI_H__
#define __TUIXIANGZI_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ROW 12
#define COL 12
#define NUM 5;
enum MENU
{
	EXIT,
	PLAY
};

struct MAP
{
	const int row;
	const int col;
	char map[ROW][COL];
};

void menu();

void game();

void print_map(char(*map)[COL], const int* row, const int* col);

void find_man(char(*map)[COL], const int* row, const int* col, const int* x, const int* y);

void player_act(char(*map)[COL], const int* x, const int* y);

int is_win(char(*map)[COL], const int* row, const int* col);

#endif