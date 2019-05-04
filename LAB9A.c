/*       ********************************************************************           */
/*           ��ʽ�洢�ṹ��ջ�Ļ���������ϰ                                             */
/* �����ṩ���ӳ��򣬱��ʵ�����¹��ܣ�                                                 */
/* �ٴ���һ����ջ[Initiate( )]��                                                        */
/* ���ж��½���ջ�Ƿ�Ϊ�գ�                                                             */
/* ����ʾ�û�����"ջ�����"��                                                           */
/* �ܸ����û������"ջ�����"����һ��ʾ�û�����"ջ�еĸ���Ԫ��"�����ջ�Ĺ���[Push( )]��*/
/* ���жϴ�ʱ��ջ�Ƿ�Ϊ�գ�                                                             */
/* �޵����ӳ���GetTop ( ) ��ӡ��ǰջ��ջ��Ԫ�أ�                                        */
/*                Pop ( ) ��ӡջ��Ԫ��                                                  */
/* �߱�дһ���������ӳ���Pop ( )�Ĵ�ӡջ��Ԫ�ص��ӳ���PrintStack( )�����ƻ�ջ           */
/* ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                 */
/*       ********************************************************************           */

#include "stdio.h"

struct NODE_TYPE
    {
      int Data;
      struct NODE_TYPE *pNext;
    };
struct LIST_STACK
    {
      struct NODE_TYPE *pTop;
      int Length;
    };

#include "lab6h.h"

main()
{
  void PrintStack();

 /*������д������*/

    int x,i,l;

/*������д������*/
/* �ٴ���һ����ջ[Initiate( )]��                                                              */
    struct NODE_TYPE Stack;
    Initiate(&Stack);

/* ���ж��½���ջ�Ƿ�Ϊ�գ�                                                                   */
    IsEmpty(&Stack);
    if(IsEmpty(&Stack)==1)
    printf("Now The Stack is Empty!\n");

/* ����ʾ�û�����"ջ�����"��                                                                 */
    printf("Enter the depth of the stack : ");
    scanf("%d",&l);

/* �ܸ����û������"ջ�����"����һ��ʾ�û�����"ջ�еĸ���Ԫ��"�����ջ�Ĺ���[Push( )]��      */
    printf("The element of the stack is :\n");
    for(i=1;i<=l;i++)
    {
        scanf("%d",&x);
        Push(&Stack,x);
    }

/* ���жϴ�ʱ��ջ�Ƿ�Ϊ�գ�                                                                   */
    if(IsEmpty(&Stack)==1)
    printf("Current Stack is Empty!\n");

/* �޵����ӳ���GetTop ( ) ��ӡ��ǰջ��ջ��Ԫ�أ�                                              */
    printf("The top element of the stack is : %d\n",GetTop(&Stack));

/* �ߵ����ӳ���Pop ( ) ��ӡ���ջ�е�����Ԫ�أ�                                               */

/*  PrintStack(&Stack);                                                                       */
    /*printf("Current stack is :\n");
    for(i=1;i<=l;i++)
        printf("\n\t\t\t%d",Pop(&Stack));*/
    printf("Current stack is :\n");
    PrintStack(&Stack);
  getch();
}
void PrintStack(Stack)
struct LIST_STACK *Stack;
{
  struct NODE_TYPE *pNode;
  int i;
  pNode=Stack->pTop;
  printf("\n\t\t");
  if(IsEmpty(pNode))
    return NULL;
  else
  for(i=1;i<=Stack->Length;i++)
   {
     printf(" %d ->\t",pNode->Data);
     pNode=pNode->pNext;
   }
  printf("NULL\n");
}
