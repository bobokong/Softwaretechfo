#include "stdio.h"
#include "stdlib.h"
#include "lab8.h"
int main()
{
    int i,j,x,y,length;          //���ڱ�����ӵ�Ԫ��

    //��ͷ��������ڴ�
    struct LINK_QUEUE *Queue= (struct LINK_QUEUE*)malloc(sizeof(struct LINK_QUEUE));
    if(!Queue) //����Ƿ�����ʧ��
    {
        printf("Queue malloc error!\n");
        return 0;
    }
    InitQueue(Queue);
/*  ����ʾ�û�����"ѭ�����еĳ���"��                                                                              */
    printf("The length of queue is : ");
    scanf("%d",&length);
/*  �����û������"ѭ�����еĳ���"����һ��ʾ�û�����"ѭ�������еĸ���Ԫ��"�����ѭ�����еĹ��죻                */
    for(i=0;i<length;i++)
    {
        printf("Enter the %dth Queue :",i+1);
        scanf("%d",&x);
        Add(Queue,x);
    }
    GetFront(Queue,&y);
    printf("Front : %d\n",y);
    GetRear(Queue,&y);
    printf("Rear  : %d\n",y);
    if(IsEmpty(Queue))
        printf("Queue Empty");
    PrintNode(Queue);
    Clear(Queue);
    for(j=0;j<3;j++)
    {
		for(i=0;i<4;i++)
		{   printf("Enter the %dth Queue :",i+1);
			scanf("%d",&x);
			Add(Queue,x);
		}
		for(i=0;i<2;i++)
		{  
			Del(Queue,&y);
		}
		PrintNode(Queue);
		GetFront(Queue,&y);
		printf("Frond : %d\n",y);
		GetRear(Queue,&y);
		printf("Rear  : %d\n",y);
    }
    free(Queue);
    Queue = NULL;
    return 0;
}