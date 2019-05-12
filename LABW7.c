/*      ****************************************************************************************************      */
/*      上机作业：（lab7）   顺序存储结构下循环队列的基本操作                                                     */
/*                                                    实现方式一:设置一个标志    QueueFull                        */
/*                                                    实现方式二:浪费一个存储空间                                 */
/*      ****************************************************************************************************      */
/*                                                                                                                */
/*  利用提供的子程序，对于循环队列的两种实现方式编程实现以下功能，并比较两种实现方式的不同：                      */
/*  ①创建一个空的循环队列；                                                                                      */
/*  ②判断新建的循环队列是否为空和是否为满；                                                                      */
/*  ③提示用户输入"循环队列的长度"；                                                                              */
/*  ④根据用户输入的"循环队列的长度"，逐一提示用户输入"循环队列中的各个元素"，完成循环队列的构造；                */
/*  ⑤判断此时的循环队列是否为空和是否为满；                                                                      */
/*  ⑥调用子程序打印当前循环队列的队首元素和队尾元素；                                                            */
/*  ⑦编写子程序的打印循环队列元素的子程序PrintNode( )；                                                          */
/*  ⑧清空队列，连续3次做下列操作：入队4个元素，出队2个元素，打印循环队列，打印当前循环队列的队首元素和队尾元素； */
/*  ⑨要求：提供尽可能友好的人机对话界面，便于用户（非程序设计者）使用。                                          */
/*      ****************************************************************************************************      */

#include "stdio.h"
#include "math.h"

#include "lab7h1.h"


main()
{
  void PrintNode_2();

/*下面填写主程序*/
    int i,j,x,length,y,Y[10];
/*  ①创建一个空的循环队列；                                                                                      */
    struct QUEUE Queue;
    InitQueue(&Queue);
/*  ②判断新建的循环队列是否为空和是否为满；                                                                      */
    if(IsEmpty(&Queue)==1)
        printf("\tQUEUE EMPTY!\n");
    else if(IsFull(&Queue)==1)
        printf("\tQUEUE FULL!\n");
/*  ③提示用户输入"循环队列的长度"；                                                                              */
    printf("The length of queue is : ");
    scanf("%d",&length);
/*  ④根据用户输入的"循环队列的长度"，逐一提示用户输入"循环队列中的各个元素"，完成循环队列的构造；                */
    for(i=0;i<length;i++)
    {
        printf("Enter the %dth Queue :",i+1);
        scanf("%d",&x);
        Add(&Queue,x);
    }
    GetFront(&Queue,&y);
    printf("Front : %d\n",y);
    GetRear(&Queue,&y);
    printf("Rear  : %d\n",y);
    if(IsEmpty(&Queue))
        printf("\tQUEUE EMPTY!\n");
    else if(IsFull(&Queue))
        printf("\tQUEUE FULL!\n");
    else
        printf("QUEUE IS NOT EMPTY AND NOT FULL!\n");
    PrintNode_2(&Queue);
    Clear(&Queue);
    for(j=0;j<3;j++)
    {
		for(i=0;i<4;i++)
		{   printf("Enter the %dth Queue :",i+1);
			scanf("%d",&x);
			Add(&Queue,x);
		}
		for(i=0;i<2;i++)
		{  
			Del(&Queue,&y);
			Y[i+j]=y;
		}
		PrintNode_2(&Queue);
		GetFront(&Queue,&y);
		printf("Frond : %d\n",y);
		GetRear(&Queue,&y);
		printf("Rear  : %d\n",y);
    }

  getch();
}
void PrintNode_2(Queue)
struct QUEUE *Queue;
{
	int i;
	if(IsEmpty(Queue))
	{
		printf("Queue Empty!");
		return;
	}
/* printf("\nThe node in the QUEUE is:\n");*/
	printf("\n\tNode:");
	i=(Queue->Front+1)%MAX_LEN;
///////////////////////////////////////////////CORRECT
	do
	{
		printf("\t %d",i);
		i=(i+1)%MAX_LEN;
	}while(i!=Queue->Rear);
	printf("\t %d",i);

	printf("\n\tData:");
	i=(Queue->Front+1)%MAX_LEN;
///////////////////////////////////////////////CORRECT
	do
	{
		printf("\t %d",Queue->Q[i]);
		i=(i+1)%MAX_LEN;
	}while(i!=Queue->Rear);
	printf("\t %d",Queue->Q[i]);
	printf("\n\t\tFront");

	printf("\n\t");
	i=(Queue->Front+1)%MAX_LEN;
///////////////////////////////////////////////CORRECT
	do
	{
		printf("\t");
		i=(i+1)%MAX_LEN;
	}while(i!=Queue->Rear);
	printf("\t");
	printf("Rear");

	printf("\n");
/* printf("That's all!");*/
}
