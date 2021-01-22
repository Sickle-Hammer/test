#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include"game.h"

void menu()
{
	printf("*****************************\n");
	printf("*******1.play  0.exit********\n");
	printf("*****************************\n");
	
}
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |
void game()
{
	char ret = 0;
	//���顪������߳���������Ϣ
	char board[ROW][COL] = { 0 };//�ɶ��Ը�ǿ
	//��Ȼ0�ǲ��ɴ�ӡ�ַ������չ���Ҫͨ����ʼ����0��Ϊ�ո�
	InitBoard(board, ROW, COL);//��ʼ������

	DisplayBoard(board, ROW, COL);//��ӡ����

	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n"); 
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ͨ��timeʱ�����ת�����������������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);//input Ϊ0.��Ϊ�٣�����ѭ������Ϊ���㣬��������ѭ����
	
}

int main()
{
	
	test();
	
	
	return 0;
}