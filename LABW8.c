#include "stdio.h"
#include "stdlib.h"
#include "lab8.h"
int main()
{
    int i,j,x,y,length;          //用于保存出队的元素

    //给头结点申请内存
    struct LINK_QUEUE *Queue= (struct LINK_QUEUE*)malloc(sizeof(struct LINK_QUEUE));
    if(!Queue) //检测是否申请失败
    {
        printf("Queue malloc error!\n");
        return 0;
    }
    InitQueue(Queue);
/*  ③提示用户输入"循环队列的长度"；                                                                              */
    printf("The length of queue is : ");
    scanf("%d",&length);
/*  根据用户输入的"循环队列的长度"，逐一提示用户输入"循环队列中的各个元素"，完成循环队列的构造；                */
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