#define _CRT_SECURE_NO_WARNINGS 1
#include "tuixiangzi.h"


int main()
{
	int input = 0;

	do
	{
		menu();
		printf("��ѡ����Ҫ���еĲ���:>");
		scanf_s("%d", &input);

		switch (input)
		{
		case PLAY: system("cls"), game(), system("cls");
			break;
		case EXIT: printf("�����˳���Ϸ\n");
			break;
		default: printf("�޷���ʶ�Ĳ���\n");
			break;
		}
	} while (input);
	return 0;
}