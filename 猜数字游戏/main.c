#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()//��ӡ�˵�
{
    printf("******  1.play  0.exit  ******\n");
}

//RAND_MAX--32767

void game()
{

    //����һ�������
    int ret=0;
    //srand(1);
    int guess;//���ղµ�����
    ret=rand()%100+1;//����1-100֮��������
    //rand����0-RAND_MAX(32767)�в���һ���������
    //RAND_MAX��Ҫͷ�ļ�#include <stdlib.h>
    while(1)
    {
        printf("�������:>\n");
        scanf("%d",&guess);
        if(guess>ret)
        {
            printf("�´���\n");
        }
        else if(guess<ret)
        {
            printf("��С��\n");
        }
        else
        {
            printf("��ϲ�㣬�¶���");
            break;
        }
    }
}

int main()
{
    int input=0;
    srand((unsigned int)time(NULL));
    //��ʱ����������������������ʼ��
    //time_t time(time_t*timer)
    //time_t�������Ǹ������ͣ���long�ͣ�
    //ʹ��time�ǵ�ͷ�ļ�#include <time.h>
    //NULL�ǿ�ָ�룬������������ʲôʵ��Ч��

   do//do while�����ܹ�����һ����Ϸ
    {
        menu();
        printf("��ѡ��>:\n");
        scanf("%d",&input);
        switch(input)
        {
        case 0:
            printf("�˳���Ϸ\n");
            break;
        case 1:
            game();//������Ϸ
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
     }while(input);
    return 0;
}
