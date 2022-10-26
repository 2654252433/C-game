#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define LEICOUNT 10

void Init(char board[ROWS][COLS],int rows,int cols,char set);
void Displayboard(char board[ROWS][COLS],int row,int col);
void Setmine(char board[ROWS][COLS],int row,int col);
void Findlei(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

#endif // GAME_H_INCLUDED
