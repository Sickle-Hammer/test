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
	//数组——存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//可读性更强
	//虽然0是不可打印字符，但终归需要通过初始化将0改为空格
	InitBoard(board, ROW, COL);//初始化棋盘

	DisplayBoard(board, ROW, COL);//打印棋盘

	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n"); 
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//通过time时间戳来转化成随机数的生成器
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);//input 为0.则为假，跳出循环，若为非零，则依旧在循环中
	
}

int main()
{
	
	test();
	
	
	return 0;
}