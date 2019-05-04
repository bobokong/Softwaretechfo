/*      *******************************************************************************************           */
/*                   链式存储结构下线性表的基本操作                                                           */
/*      *******************************************************************************************           */
/*       上机作业3：利用提供的子程序，编程实现以下功能：                                                      */
/* ①创建一个空表[Initiate( )]；                                                                              */
/* ②提示用户输入"线性表长度"；                                                                               */
/* ③根据用户输入的"线性表长度"，逐一提示用户输入"线性表中的各个元素"，完成线性表的构造[Insert( )]；          */
/* ④通过调用子程序Length( ) 打印输出当前线性表的长度；                                                       */
/* ⑤自行编写子程序PrintList( ) 打印输出当前线性表的所有元素；                                                */
/* ⑥提示用户输入要查找的元素数值，通过调用子程序*Find( ) 找到符合要求的第一个元素，并打印输出该元素的数值；  */
/*                                               *GetPrior( ) 打印输出该元素的前驱元素值；                    */
/*                                               *GetNext( ) 打印输出该元素的后继元素值；                     */
/* ⑦通过调用子程序Insert( ) 在当前线性表的表头和表尾各插入一个元素0 ，打印输出插入后的线性表[PrintList( )]； */
/* ⑧通过调用子程序Delete( ) 删除⑦中插入的各个元素，打印输出删除后的线性表[PrintList( )]；                   */
/* ⑨调用自行编写的链式结构下线性表的逆转子程序Reverse( )，打印输出逆转后的线性表[PrintList( )]。             */
/* ⑩要求：提供尽可能友好的人机对话界面，便于用户（非程序设计者）使用。                                       */
/*                                                                                                            */
/*      *******************************************************************************************           */

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
  void Reverse();

/*下面填写主程序*/
  int i,n,x,data,*id,*data1,*data2;
  struct NODE_TYPE list;
  printf("Intiate List!\n");
/* ①创建一个空表[Initiate( )]；                                                                              */
  Initiate(&list);
/* ②提示用户输入"线性表长度"；                                                                               */
  printf("The length of list a is : ");
  scanf("%d",&n);
/* ③根据用户输入的"线性表长度"，逐一提示用户输入"线性表中的各个元素"，完成线性表的构造[Insert( )]；          */
  for(i=1;i<=n;i++)
  {
    printf("Enter the %dth data :",i);
    scanf("%d",&x);
    Insert(&list,i,x);
  }
/* ④通过调用子程序Length( ) 打印输出当前线性表的长度；                                                        */
  printf("The length of list is %d\n",Length(&list));
/* ⑤自行编写子程序PrintList( ) 打印输出当前线性表的所有元素；                                                 */
  printf("The list is:\n");
  PrintList(&list);
/* ⑥提示用户输入要查找的元素数值，通过调用子程序*Find( ) 找到符合要求的第一个元素，并打印输出该元素的数值；   */
  printf("Enter the data to be searched :");
   scanf("%d",&data);
   id=Find(&list,data);
   printf("Index of data %d is :\t%d\n",data,*id);
   data1=GetPrior(&list,data);
   printf("Prior of data %d is :\t%d\n",data,*data1);
   data2=GetNext(&list,data);
   printf("Next of data %d is  :\t%d\n",data,*data2);
/* ⑦通过调用子程序Insert( ) 在当前线性表的表头和表尾各插入一个元素0 ，打印输出插入后的线性表[PrintList( )]； */
   printf("Insert data 0 into Head and End of list!\n");
   Insert(&list,1,0);
   Insert(&list,Length(&list)+1,0);
   PrintList(&list);
/* ⑧通过调用子程序Delete( ) 删除⑦中插入的各个元素，打印输出删除后的线性表[PrintList( )]；                   */
   printf("delete the data Insert!\n");
   Delete(&list,1);
   Delete(&list,Length(&list));
   printf("The list after Insert operation is :\n");
	PrintList(&list);
/* ⑨调用自行编写的链式结构下线性表的逆转子程序Reverse( )，打印输出逆转后的线性表[PrintList( )]。             */
	printf("Reverse list!\n");
	Reverse(&list);
	PrintList(&list);
	getch();
}
void Reverse(list)
struct LIST_TYPE *list;
{
	int i; 
	int *node1,*node2;
	for(i=1;i<=list->Length/2;i++)
	{
	node1=GetAt(list,i);
	node2=GetAt(list,list->Length+1-i);
	*node1=*node1^*node2;
	*node2=*node2^*node1;
	*node1=*node1^*node2;
	}
}
