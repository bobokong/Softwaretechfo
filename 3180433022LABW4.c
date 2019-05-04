/*      *******************************************************************************************    */
/*      *******************************************************************************************    */
/*        �ֽ��㷨��  ����һ��������������ֵ��Ϊ��������ֵ����С�������ӣ������һ���㷨���ֽ��   */
/*                    ����Ϊ��������һ��Ϊ��������һ��Ϊż�����������������ֵ���Ӵ�С���ӡ�   */
/*      *******************************************************************************************    */
/*       �ϻ���ҵ4�����б�д��һ���ӳ���ʵ�������ķֽ��㷨��                                           */
/*     ����дһ�������ĳ���ʵ�����¹��ܣ�                                                              */
/*    �ٶ�̬����һ�����������������С��6������                                                      */
/*    �ڴ�ӡ������е���������                                                                       */
/*    �۵������б�д���ӳ���,ʵ������ķֽ��㷨����������ָ�루�ֱ�ָ�����������ż��������        */
/*    �ܴ�ӡ������������ż������                                                                     */
/*    ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                             */
/*                                                                                                     */
/*      *******************************************************************************************    */

#include "stdio.h"
#include "math.h"

struct NODE_TYPE
    {
      int Data;
      struct NODE_TYPE *pNext;
    };
struct LIST_TYPE
    {
      struct NODE_TYPE *pHead;
      int Length;
    };

#include "lab3h.h"

main()
{	
	void Split();
	/*������д������*/
	int i,n,x;
	struct NODE_TYPE list,list1,list2;
	printf("Intiate List!\n");                                                                    
	Initiate(&list);
	Initiate(&list1);
	Initiate(&list2);                                                                        
	printf("The length of list LIST is : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %dth data :",i);
		scanf("%d",&x);
		Insert(&list,i,x);
	}
	PrintList(&list);
	Split(&list,&list1,&list2);
	printf("The odd list is:\n");
	PrintList(&list1);
	printf("The even list is:\n");
	PrintList(&list2);

   getch();
}

/*  ����ֽ����    */
/* listΪԭ����ָ�룬list1Ϊ��������ָ�룬list2Ϊż������ָ�� */
void Split(list,list1,list2)
struct LIST_TYPE *list;
struct LIST_TYPE *list1;
struct LIST_TYPE *list2;
{
/*������д�ӳ���*/
	int n=1,m=1,data,i;
	for(i=1;i<=list->Length;i++)
	{	if((data=list->pHead->Data)%2==1){
		Insert(list1,n++,data);
		list->pHead=list->pHead->pNext;
		}
		else if((data=list->pHead->Data)%2==0){
		Insert(list2,m++,data);
		list->pHead=list->pHead->pNext;
		}
	}
	
}
