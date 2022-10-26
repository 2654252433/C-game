#include "game.h"

void Init(char board[ROWS][COLS],int rows,int cols,char set)
{
    int i=0;
    int j=0;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            board[i][j]=set;
        }
    }
}

void Displayboard(char board[ROWS][COLS],int row,int col)
{
    int i=0;
    int j=0;
    //打印列号
    for(i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i=1;i<=row;i++)
    {
        printf("%d ",i);//打印行号
        for(j=1;j<=col;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void Setmine(char board[ROWS][COLS],int row,int col)
{
    int count=LEICOUNT;
    while(count)
    {
        int x=rand()%row+1;
        int y=rand()%col+1;
        if(board[x][y]=='0')
        {
            board[x][y]='1';
            count--;
        }
    }
}

//    字符0减去字符0就等于数字0
//同样字符1(2,3)减去字符0就等于数字1(2,3)
//因为字符0的ASCLL码值是48，字符1，2，3的ASCLL码值为49，50，51
int getmine(char mine[ROWS][COLS],int x,int y)
{
    //返回雷的个数
    return mine[x-1][y-1]+
    mine[x][y-1]+
    mine[x+1][y-1]+
    mine[x-1][y]+
    mine[x+1][y]+
    mine[x-1][y+1]+
    mine[x][y+1]+
    mine[x+1][y+1]-8*'0';
    //用输入坐标周围的8个坐标ASCLL码值 减去 周围8个没有雷的坐标ASCLL码值
    //就可知道附件有几个雷
}

void Findlei(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    int win=0;
    while(win<row*col-LEICOUNT)
    {
      printf("请输入排查雷的坐标:\n");
      scanf("%d %d",&x,&y);
      if(x>=1&&x<=row&&y>=1&&y<=col)
      {
        //坐标合法
        if(mine[x][y]=='1')
        {
            printf("很遗憾，你被炸死了\n");
            Displayboard(mine,row,col);
            break;
        }
        else//不是雷
        {
            //计算x,y坐标周围有几个雷
            int count=getmine(mine,x,y);
            show[x][y]=count+'0';
            Displayboard(show,row,col);
            win++;
        }
       }
       else
       {
        printf("输入坐标合法，请重新输入:\n");
       }
    }
    if(win==row*col-LEICOUNT)
    {
        printf("恭喜你，排雷成功\n");
        Displayboard(mine,row,col);
    }
}
