/*  顺序存储结构下栈的基本操作   */


/*初始化栈：创建一空栈*/
void Initiate(Stack)
struct STACK *Stack;
{
  Stack->Top=-1;
}

/*栈判空：为空返回1；不空返回0*/
int IsEmpty(Stack)
struct STACK *Stack;
{
  return(Stack->Top==-1);
}

/*压栈操作：将数据元素x插入到栈顶*/
int Push(Stack,x)
struct STACK *Stack;
int x;
{
  if(Stack->Top==MAX_LEN-1)
    return 0;
  Stack->Top++;
  Stack->s[Stack->Top]=x;
  return 1;
}

/*弹栈操作：将栈顶元素返回后删除该栈顶元素*/
int Pop(Stack)
struct STACK *Stack;
{
  if(IsEmpty(Stack))
    return NULL;

  return Stack->s[Stack->Top--];
}

/*读取栈顶元素（但不删除栈顶元素）*/
int GetTop(Stack)
struct STACK *Stack;
{
  if(IsEmpty(Stack))
    return NULL;

  return Stack->s[Stack->Top];
}


/*           非基本操作               */
/*打印栈中所有元素（但不删除栈中元素）*/
void PrintStack(Stack)
struct STACK *Stack;
{
  int i;

  if(IsEmpty(Stack))
    printf("Current Stack is Empty!");
  else
    {
       printf("Current Stack is:");
       for(i=Stack->Top;i>=0;i--)
         {
           printf("\n\t\t\t%d",Stack->s[i]);
           if(i==Stack->Top)
             printf("\tTop");
          }
       printf("\n");
     }
}

