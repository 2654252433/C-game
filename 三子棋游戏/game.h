#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//����
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void Playermove(char board[ROW][COL],int row,int col);
void Computermove(char board[ROW][COL],int row,int col);

//����������Ϸ����״̬
//���Ӯ--'*'
//����Ӯ--'#'
//ƽ��--'o'
//����--'e'
char Iswin(char board[ROW][COL],int row,int col);
int Isfull(char board[ROW][COL],int row,int col);
#endif // GAME_H_INCLUDED
