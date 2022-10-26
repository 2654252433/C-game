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
    //��ӡ�к�
    for(i=0;i<=col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i=1;i<=row;i++)
    {
        printf("%d ",i);//��ӡ�к�
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

//    �ַ�0��ȥ�ַ�0�͵�������0
//ͬ���ַ�1(2,3)��ȥ�ַ�0�͵�������1(2,3)
//��Ϊ�ַ�0��ASCLL��ֵ��48���ַ�1��2��3��ASCLL��ֵΪ49��50��51
int getmine(char mine[ROWS][COLS],int x,int y)
{
    //�����׵ĸ���
    return mine[x-1][y-1]+
    mine[x][y-1]+
    mine[x+1][y-1]+
    mine[x-1][y]+
    mine[x+1][y]+
    mine[x-1][y+1]+
    mine[x][y+1]+
    mine[x+1][y+1]-8*'0';
    //������������Χ��8������ASCLL��ֵ ��ȥ ��Χ8��û���׵�����ASCLL��ֵ
    //�Ϳ�֪�������м�����
}

void Findlei(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x=0;
    int y=0;
    int win=0;
    while(win<row*col-LEICOUNT)
    {
      printf("�������Ų��׵�����:\n");
      scanf("%d %d",&x,&y);
      if(x>=1&&x<=row&&y>=1&&y<=col)
      {
        //����Ϸ�
        if(mine[x][y]=='1')
        {
            printf("���ź����㱻ը����\n");
            Displayboard(mine,row,col);
            break;
        }
        else//������
        {
            //����x,y������Χ�м�����
            int count=getmine(mine,x,y);
            show[x][y]=count+'0';
            Displayboard(show,row,col);
            win++;
        }
       }
       else
       {
        printf("��������Ϸ�������������:\n");
       }
    }
    if(win==row*col-LEICOUNT)
    {
        printf("��ϲ�㣬���׳ɹ�\n");
        Displayboard(mine,row,col);
    }
}
