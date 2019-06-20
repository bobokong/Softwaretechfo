/*      ****************************************************************************************************     */
/*      �ϻ���ҵ����lab8��   ��ʽ�洢�ṹ�¶��еĻ�������                                                        */
/*      ****************************************************************************************************     */
/*                                                                                                               */
/*  �����Ա���ӳ���ʵ�����¹��ܣ�                                                                               */
/*  �ٴ���һ���ն��У�                                                                                            */
/*  ���ж��½��Ķ����Ƿ�Ϊ�գ�                                                                                    */
/*  ����ʾ�û�����"���еĳ���"��                                                                                  */
/*  �ܸ����û������"���еĳ���"����һ��ʾ�û�����"�����еĸ���Ԫ��"����ɶ��еĹ��죻                            */
/*  ���жϴ�ʱ�Ķ����Ƿ�Ϊ�գ�                                                                                    */
/*  �޵����ӳ����ӡ��ǰ���еĶ���Ԫ�غͶ�βԪ�أ�                                                                */
/*  �߱�д��ӡ����Ԫ�ص��ӳ���PrintNode( )��                                                                      */
/*  ����ն��У�����3�������в��������4��Ԫ�أ�����2��Ԫ�أ���ӡ���У���ӡ��ǰ���еĶ���Ԫ�غͶ�βԪ�أ�         */
/*  ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ������3�ߣ�ʹ�á�                                          */
/*      ****************************************************************************************************     */
#include "windows.h"	/*����̨�����Ż�*/
#include "stdio.h"
#include "A1.h"
int main()
{     
	int i=-1,j=-1,x,y,length=0;           
    /*  �ٴ���һ���ն��У�                                             */
    struct LINK_QUEUE *Queue= (struct LINK_QUEUE*)malloc(sizeof(struct LINK_QUEUE)); /*��ͷ��������ڴ�*/
	SetConsoleTitle("��ʽ�洢�ṹ�¶��еĻ�������"); /*���ô��ڱ���*/ 
	if(!Queue) /*����Ƿ�����ʧ��*/
    {
		TextColor(4); /*��������Ϊ��ɫ*/
        printf("Queue malloc error!\n");
        TextColor(7); /*��������������Ϊ��ɫ*/
        return 0;
    }
    else
	{
	InitQueue(Queue);
    TextColor(4);
	printf("Empty quene generated successfully!\n\n");
	TextColor(7);
	}
	/*  ���ж��½��Ķ����Ƿ�Ϊ�գ�                                                                                    */
	if(IsEmpty(Queue))
    {
   		TextColor(4);
        printf("The queue is empty!\n\n");
        TextColor(7);
    }
	else
        printf("Queue Not Empty\n\n");
    /*����ʾ�û�����"ѭ�����еĳ���*/
    printf("Please enter the length of the queue : ");	
	length=IsRigth(&i,&j);/*i,*j��ѡ���ж���*/ 
    /*�ܸ����û������"ѭ�����еĳ���"����һ��ʾ�û�����"ѭ�������еĸ���Ԫ��"�����ѭ�����еĹ���; */
    for(i=0;i<length;i++)
    {
        printf("Please enter the %dth element : ",i+1);
        
        Add(Queue,IsRigth(&i,&j));
    }
    /*���жϴ�ʱ�Ķ����Ƿ�Ϊ��;*/
    if(IsEmpty(Queue))
        printf("\nThe queue is empty !\n");
     else
        printf("\nThe queue is not empty !\n");
    /*�޵����ӳ����ӡ��ǰ���еĶ���Ԫ�غͶ�βԪ��?*/
    GetFront(Queue,&y);
    printf("\nFront : %d\n",y);
    GetRear(Queue,&y);
    printf("Rear  : %d\n",y);

    PrintNode(Queue);
    /*����ն��У�����3�������в��������4��Ԫ�أ�����2��Ԫ�أ���ӡ���У���ӡ��ǰ���еĶ���Ԫ�غͶ�βԪ�أ�*/
    Clear(Queue);
    TextColor(4);
	printf("\n\nThe original quenue has been cleared !\n\n");
	TextColor(7);
	In_OutPut(Queue);
    free(Queue);
    return 0;
}
