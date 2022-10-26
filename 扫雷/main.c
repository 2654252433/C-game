
#include "game.h"

void menu()
{
    printf("*************************\n");
    printf("**** 1.play   0.exit ****\n");
    printf("*************************\n");
}

void game()
{
    //雷的信息存储
    //1、布置好雷的信息
    char mine[ROWS][COLS]={0};//这个数组棋盘是自己看的布置雷的棋盘
    //2、排查出雷的信息
    char show[ROWS][COLS]={0};//这个数组棋盘是给玩家看的所展现出来的棋盘
    //初始化
    Init(mine,ROWS,COLS,'0');
    Init(show,ROWS,COLS,'*');
    //打印棋盘
    //Displayboard(mine,ROW,COL);//可让自己看到全部初始化为0的棋盘
    Displayboard(show,ROW,COL);//可让玩家看到全部覆盖了布置好的棋盘
    //布置雷
    Setmine(mine,ROW,COL);
    //Displayboard(mine,ROW,COL);可以看到是哪些位置布置了雷
    //扫雷
    Findlei(mine,show,ROW,COL);
}

void test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
       menu();
       printf("请选择:\n");
       scanf("%d",&input);
       switch(input)
      {
        case 0:
          printf("退出游戏\n");
          break;
        case 1:
          game();
          break;
        default:
          printf("输入错误，请重新输入\n");
          break;
      }
    }while(input);
}

int main()
{
    test();
    return 0;
}
