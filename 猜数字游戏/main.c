#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()//打印菜单
{
    printf("******  1.play  0.exit  ******\n");
}

//RAND_MAX--32767

void game()
{

    //生成一个随机数
    int ret=0;
    //srand(1);
    int guess;//接收猜的数字
    ret=rand()%100+1;//生成1-100之间的随机数
    //rand会在0-RAND_MAX(32767)中产生一个随机整数
    //RAND_MAX需要头文件#include <stdlib.h>
    while(1)
    {
        printf("请猜数字:>\n");
        scanf("%d",&guess);
        if(guess>ret)
        {
            printf("猜大了\n");
        }
        else if(guess<ret)
        {
            printf("猜小了\n");
        }
        else
        {
            printf("恭喜你，猜对了");
            break;
        }
    }
}

int main()
{
    int input=0;
    srand((unsigned int)time(NULL));
    //拿时间戳来设置随机数的生成起始点
    //time_t time(time_t*timer)
    //time_t本质上是个长整型（即long型）
    //使用time记得头文件#include <time.h>
    //NULL是空指针，不想让它产生什么实际效果

   do//do while至少能够进行一次游戏
    {
        menu();
        printf("请选择>:\n");
        scanf("%d",&input);
        switch(input)
        {
        case 0:
            printf("退出游戏\n");
            break;
        case 1:
            game();//进入游戏
            break;
        default:
            printf("选择错误\n");
            break;
        }
     }while(input);
    return 0;
}
