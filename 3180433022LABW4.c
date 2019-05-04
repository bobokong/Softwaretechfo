/*      *******************************************************************************************    */
/*      *******************************************************************************************    */
/*        分解算法：  设有一个线性链表，其结点值均为整数，且值按从小到大链接，试设计一个算法，分解此   */
/*                    链表为两个链表，一个为奇数链表，一个为偶数链表，且两个链表的值均从大到小链接。   */
/*      *******************************************************************************************    */
/*       上机作业4：自行编写的一个子程序实现上述的分解算法，                                           */
/*     并编写一个完整的程序实现以下功能：                                                              */
/*    ①动态生成一个线性链表（结点数不小于6个）；                                                      */
/*    ②打印输出①中的线性链表；                                                                       */
/*    ③调用自行编写的子程序,实现链表的分解算法，返回两个指针（分别指向：奇数链表和偶数链表）；        */
/*    ④打印输出奇数链表和偶数链表                                                                     */
/*    ⑤要求：提供尽可能友好的人机对话界面，便于用户（非程序设计者）使用。                             */
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
	/*下面填写主程序*/
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

/*  链表分解程序    */
/* list为原链表指针，list1为奇数链表指针，list2为偶数链表指针 */
void Split(list,list1,list2)
struct LIST_TYPE *list;
struct LIST_TYPE *list1;
struct LIST_TYPE *list2;
{
/*下面填写子程序*/
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
