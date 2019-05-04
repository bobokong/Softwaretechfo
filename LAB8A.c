/*        ****************************************************************                    */
/*             顺序存储结构下栈的基本操作                                                     */
/*        ****************************************************************                    */
/* 利用提供的子程序，编程实现以下功能：                                                       */
/* ①创建一个空栈[Initiate( )]；                                                              */
/* ②判断新建的栈是否为空；                                                                   */
/* ③提示用户输入"栈的深度"；                                                                 */
/* ④根据用户输入的"栈的深度"，逐一提示用户输入"栈中的各个元素"，完成栈的构造[Push( )]；      */
/* ⑤判断此时的栈是否为空；                                                                   */
/* ⑥调用子程序GetTop ( ) 打印当前栈的栈顶元素；                                              */
/* ⑦调用子程序Pop ( ) 打印输出栈中的所有元素；                                               */
/*   编写一个不调用子程序Pop ( )的打印栈中元素的子程序PrintStack( )，不破坏栈；               */
/* ⑧要求：提供尽可能友好的人机对话界面，便于用户（非程序设计者）使用。                       */
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

/*下面填写主程序*/
/* ①创建一个空栈[Initiate( )]；                                                              */
    struct STACK Stack;
    Initiate(&Stack);
/* ②判断新建的栈是否为空；                                                                   */
    IsEmpty(&Stack);
    if(IsEmpty(&Stack)==1)
    printf("Now The Stack is Empty!\n");

/* ③提示用户输入"栈的深度"；                                                                 */
    printf("Enter the depth of the stack : ");
    scanf("%d",&l);
/* ④根据用户输入的"栈的深度"，逐一提示用户输入"栈中的各个元素"，完成栈的构造[Push( )]；      */
    for(i=1;i<=l;i++)
    {
        scanf("%d",&x);
        Push(&Stack,x);
    }
/* ⑤判断此时的栈是否为空；                                                                   */
    IsEmpty(&Stack);
    if(IsEmpty(&Stack)==1)
    printf("Current Stack is Empty!\n");
/* ⑥调用子程序GetTop ( ) 打印当前栈的栈顶元素；                                              */
    printf("The top element of the stack is : %d\n",GetTop(&Stack));
/* ⑦调用子程序Pop ( ) 打印输出栈中的所有元素；                                               */
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
