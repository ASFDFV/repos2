#define _CRT_SECURE_NO_WARNINGS 1
#include "tuixiangzi.h"


int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择想要进行的操作:>");
		scanf_s("%d", &input);

		switch (input)
		{
		case PLAY: system("cls"), game(), system("cls");
			break;
		case EXIT: printf("正在退出游戏\n");
			break;
		default: printf("无法辨识的操作\n");
			break;
		}
	} while (input);
	return 0;
}