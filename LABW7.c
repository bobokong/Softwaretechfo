/*      ****************************************************************************************************      */
/*      �ϻ���ҵ����lab7��   ˳��洢�ṹ��ѭ�����еĻ�������                                                     */
/*                                                    ʵ�ַ�ʽһ:����һ����־    QueueFull                        */
/*                                                    ʵ�ַ�ʽ��:�˷�һ���洢�ռ�                                 */
/*      ****************************************************************************************************      */
/*                                                                                                                */
/*  �����ṩ���ӳ��򣬶���ѭ�����е�����ʵ�ַ�ʽ���ʵ�����¹��ܣ����Ƚ�����ʵ�ַ�ʽ�Ĳ�ͬ��                      */
/*  �ٴ���һ���յ�ѭ�����У�                                                                                      */
/*  ���ж��½���ѭ�������Ƿ�Ϊ�պ��Ƿ�Ϊ����                                                                      */
/*  ����ʾ�û�����"ѭ�����еĳ���"��                                                                              */
/*  �ܸ����û������"ѭ�����еĳ���"����һ��ʾ�û�����"ѭ�������еĸ���Ԫ��"�����ѭ�����еĹ��죻                */
/*  ���жϴ�ʱ��ѭ�������Ƿ�Ϊ�պ��Ƿ�Ϊ����                                                                      */
/*  �޵����ӳ����ӡ��ǰѭ�����еĶ���Ԫ�غͶ�βԪ�أ�                                                            */
/*  �߱�д�ӳ���Ĵ�ӡѭ������Ԫ�ص��ӳ���PrintNode( )��                                                          */
/*  ����ն��У�����3�������в��������4��Ԫ�أ�����2��Ԫ�أ���ӡѭ�����У���ӡ��ǰѭ�����еĶ���Ԫ�غͶ�βԪ�أ� */
/*  ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                                          */
/*      ****************************************************************************************************      */

#include "stdio.h"
#include "math.h"

#include "lab7h1.h"


main()
{
  void PrintNode_2();

/*������д������*/
    int i,j,x,length,y,Y[10];
/*  �ٴ���һ���յ�ѭ�����У�                                                                                      */
    struct QUEUE Queue;
    InitQueue(&Queue);
/*  ���ж��½���ѭ�������Ƿ�Ϊ�պ��Ƿ�Ϊ����                                                                      */
    if(IsEmpty(&Queue)==1)
        printf("empty\n");
    else if(IsFull(&Queue)==1)
        printf("full\n");
/*  ����ʾ�û�����"ѭ�����еĳ���"��                                                                              */
    printf("The length of queue is : ");
    scanf("%d",&length);
/*  �ܸ����û������"ѭ�����еĳ���"����һ��ʾ�û�����"ѭ�������еĸ���Ԫ��"�����ѭ�����еĹ��죻                */
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
        printf("empty");
    else if(IsFull(&Queue))
        printf("Full");
    else
        printf("Queue is not empty and not full");
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
	do
	{
		printf("\t %d",i);
		i=(i+1)%MAX_LEN;///////////////////////////////////////////////CORRECT
	}while(i!=Queue->Rear);
	printf("\t %d",i);

	printf("\n\tData:");
	i=(Queue->Front+1)%MAX_LEN;
	do
	{
		printf("\t %d",Queue->Q[i]);
		i=(i+1)%MAX_LEN;///////////////////////////////////////////////CORRECT
	}while(i!=Queue->Rear);
	printf("\t %d",Queue->Q[i]);
	printf("\n\t\tFront");

	printf("\n\t");
	i=(Queue->Front+1)%MAX_LEN;
	do
	{
		printf("\t");
		i=(i+1)%MAX_LEN;///////////////////////////////////////////////CORRECT
	}while(i!=Queue->Rear);
	printf("\t");
	printf("Rear");

	printf("\n");
/* printf("That's all!");*/
}
