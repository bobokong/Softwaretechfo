/*        ****************************************************************                    */
/*             ˳��洢�ṹ��ջ�Ļ�������                                                     */
/*        ****************************************************************                    */
/* �����ṩ���ӳ��򣬱��ʵ�����¹��ܣ�                                                       */
/* �ٴ���һ����ջ[Initiate( )]��                                                              */
/* ���ж��½���ջ�Ƿ�Ϊ�գ�                                                                   */
/* ����ʾ�û�����"ջ�����"��                                                                 */
/* �ܸ����û������"ջ�����"����һ��ʾ�û�����"ջ�еĸ���Ԫ��"�����ջ�Ĺ���[Push( )]��      */
/* ���жϴ�ʱ��ջ�Ƿ�Ϊ�գ�                                                                   */
/* �޵����ӳ���GetTop ( ) ��ӡ��ǰջ��ջ��Ԫ�أ�                                              */
/* �ߵ����ӳ���Pop ( ) ��ӡ���ջ�е�����Ԫ�أ�                                               */
/*   ��дһ���������ӳ���Pop ( )�Ĵ�ӡջ��Ԫ�ص��ӳ���PrintStack( )�����ƻ�ջ��               */
/* ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                       */
/*                                                                                            */
/*        ****************************************************************                    */


#include "stdio.h"

#define MAX_LEN 16
struct STACK
    {
      int s[MAX_LEN];
      int Top;
    };

#include "lab5h.h"

main()
{
    int x,i,l;

/*������д������*/
/* �ٴ���һ����ջ[Initiate( )]��                                                              */
    struct STACK Stack;
    Initiate(&Stack);
/* ���ж��½���ջ�Ƿ�Ϊ�գ�                                                                   */
    IsEmpty(&Stack);
    if(IsEmpty(&Stack)==1)
    printf("Now The Stack is Empty!\n");

/* ����ʾ�û�����"ջ�����"��                                                                 */
    printf("Enter the depth of the stack : ");
    scanf("%d",&l);
/* �ܸ����û������"ջ�����"����һ��ʾ�û�����"ջ�еĸ���Ԫ��"�����ջ�Ĺ���[Push( )]��      */
    for(i=1;i<=l;i++)
    {
        scanf("%d",&x);
        Push(&Stack,x);
    }
/* ���жϴ�ʱ��ջ�Ƿ�Ϊ�գ�                                                                   */
    IsEmpty(&Stack);
    if(IsEmpty(&Stack)==1)
    printf("Current Stack is Empty!\n");
/* �޵����ӳ���GetTop ( ) ��ӡ��ǰջ��ջ��Ԫ�أ�                                              */
    printf("The top element of the stack is : %d\n",GetTop(&Stack));
/* �ߵ����ӳ���Pop ( ) ��ӡ���ջ�е�����Ԫ�أ�                                               */
/*  PrintStack(&Stack);                                                                       */
    printf("Current stack is :\n");
    for(i=1;i<=l;i++)
    { 
        printf("\n\t\t\t%d",Pop(&Stack));
        if(i==1)
		printf("\t\tTop"); 
    }   
  getch();
}
