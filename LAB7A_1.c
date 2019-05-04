/*      *******************************************************************************************           */
/*                   ��ʽ�洢�ṹ�����Ա�Ļ�������                                                           */
/*      *******************************************************************************************           */
/*       �ϻ���ҵ3�������ṩ���ӳ��򣬱��ʵ�����¹��ܣ�                                                      */
/* �ٴ���һ���ձ�[Initiate( )]��                                                                              */
/* ����ʾ�û�����"���Ա���"��                                                                               */
/* �۸����û������"���Ա���"����һ��ʾ�û�����"���Ա��еĸ���Ԫ��"��������Ա�Ĺ���[Insert( )]��          */
/* ��ͨ�������ӳ���Length( ) ��ӡ�����ǰ���Ա�ĳ��ȣ�                                                       */
/* �����б�д�ӳ���PrintList( ) ��ӡ�����ǰ���Ա������Ԫ�أ�                                                */
/* ����ʾ�û�����Ҫ���ҵ�Ԫ����ֵ��ͨ�������ӳ���*Find( ) �ҵ�����Ҫ��ĵ�һ��Ԫ�أ�����ӡ�����Ԫ�ص���ֵ��  */
/*                                               *GetPrior( ) ��ӡ�����Ԫ�ص�ǰ��Ԫ��ֵ��                    */
/*                                               *GetNext( ) ��ӡ�����Ԫ�صĺ��Ԫ��ֵ��                     */
/* ��ͨ�������ӳ���Insert( ) �ڵ�ǰ���Ա�ı�ͷ�ͱ�β������һ��Ԫ��0 ����ӡ������������Ա�[PrintList( )]�� */
/* ��ͨ�������ӳ���Delete( ) ɾ�����в���ĸ���Ԫ�أ���ӡ���ɾ��������Ա�[PrintList( )]��                   */
/* ��������б�д����ʽ�ṹ�����Ա����ת�ӳ���Reverse( )����ӡ�����ת������Ա�[PrintList( )]��             */
/* ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                                       */
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

/*������д������*/
  int i,n,x,data,*id,*data1,*data2;
  struct NODE_TYPE list;
  printf("Intiate List!\n");
/* �ٴ���һ���ձ�[Initiate( )]��                                                                              */
  Initiate(&list);
/* ����ʾ�û�����"���Ա���"��                                                                               */
  printf("The length of list a is : ");
  scanf("%d",&n);
/* �۸����û������"���Ա���"����һ��ʾ�û�����"���Ա��еĸ���Ԫ��"��������Ա�Ĺ���[Insert( )]��          */
  for(i=1;i<=n;i++)
  {
    printf("Enter the %dth data :",i);
    scanf("%d",&x);
    Insert(&list,i,x);
  }
/* ��ͨ�������ӳ���Length( ) ��ӡ�����ǰ���Ա�ĳ��ȣ�                                                        */
  printf("The length of list is %d\n",Length(&list));
/* �����б�д�ӳ���PrintList( ) ��ӡ�����ǰ���Ա������Ԫ�أ�                                                 */
  printf("The list is:\n");
  PrintList(&list);
/* ����ʾ�û�����Ҫ���ҵ�Ԫ����ֵ��ͨ�������ӳ���*Find( ) �ҵ�����Ҫ��ĵ�һ��Ԫ�أ�����ӡ�����Ԫ�ص���ֵ��   */
  printf("Enter the data to be searched :");
   scanf("%d",&data);
   id=Find(&list,data);
   printf("Index of data %d is :\t%d\n",data,*id);
   data1=GetPrior(&list,data);
   printf("Prior of data %d is :\t%d\n",data,*data1);
   data2=GetNext(&list,data);
   printf("Next of data %d is  :\t%d\n",data,*data2);
/* ��ͨ�������ӳ���Insert( ) �ڵ�ǰ���Ա�ı�ͷ�ͱ�β������һ��Ԫ��0 ����ӡ������������Ա�[PrintList( )]�� */
   printf("Insert data 0 into Head and End of list!\n");
   Insert(&list,1,0);
   Insert(&list,Length(&list)+1,0);
   PrintList(&list);
/* ��ͨ�������ӳ���Delete( ) ɾ�����в���ĸ���Ԫ�أ���ӡ���ɾ��������Ա�[PrintList( )]��                   */
   printf("delete the data Insert!\n");
   Delete(&list,1);
   Delete(&list,Length(&list));
   printf("The list after Insert operation is :\n");
	PrintList(&list);
/* ��������б�д����ʽ�ṹ�����Ա����ת�ӳ���Reverse( )����ӡ�����ת������Ա�[PrintList( )]��             */
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
