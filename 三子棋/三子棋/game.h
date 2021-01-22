
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROW][COL],int row,int col);//声明函数
void DisplayBoard(char board[ROW][COL], int row, int col); 
void Playermove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);

//四种状态
//玩家赢-‘*’
//电脑赢-‘#’
//平局  -‘Q’
//继续  -‘C’

char IsWin(char board[ROW][COL], int row, int col);