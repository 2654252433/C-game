
#include "game.h"

void menu()
{
    printf("*************************\n");
    printf("**** 1.play   0.exit ****\n");
    printf("*************************\n");
}

void game()
{
    //�׵���Ϣ�洢
    //1�����ú��׵���Ϣ
    char mine[ROWS][COLS]={0};//��������������Լ����Ĳ����׵�����
    //2���Ų���׵���Ϣ
    char show[ROWS][COLS]={0};//������������Ǹ���ҿ�����չ�ֳ���������
    //��ʼ��
    Init(mine,ROWS,COLS,'0');
    Init(show,ROWS,COLS,'*');
    //��ӡ����
    //Displayboard(mine,ROW,COL);//�����Լ�����ȫ����ʼ��Ϊ0������
    Displayboard(show,ROW,COL);//������ҿ���ȫ�������˲��úõ�����
    //������
    Setmine(mine,ROW,COL);
    //Displayboard(mine,ROW,COL);���Կ�������Щλ�ò�������
    //ɨ��
    Findlei(mine,show,ROW,COL);
}

void test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
       menu();
       printf("��ѡ��:\n");
       scanf("%d",&input);
       switch(input)
      {
        case 0:
          printf("�˳���Ϸ\n");
          break;
        case 1:
          game();
          break;
        default:
          printf("�����������������\n");
          break;
      }
    }while(input);
}

int main()
{
    test();
    return 0;
}
