/*  ˳��洢�ṹ��ջ�Ļ�������   */


/*��ʼ��ջ������һ��ջ*/
void Initiate(Stack)
struct STACK *Stack;
{
  Stack->Top=-1;
}

/*ջ�пգ�Ϊ�շ���1�����շ���0*/
int IsEmpty(Stack)
struct STACK *Stack;
{
  return(Stack->Top==-1);
}

/*ѹջ������������Ԫ��x���뵽ջ��*/
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

/*��ջ��������ջ��Ԫ�ط��غ�ɾ����ջ��Ԫ��*/
int Pop(Stack)
struct STACK *Stack;
{
  if(IsEmpty(Stack))
    return NULL;

  return Stack->s[Stack->Top--];
}

/*��ȡջ��Ԫ�أ�����ɾ��ջ��Ԫ�أ�*/
int GetTop(Stack)
struct STACK *Stack;
{
  if(IsEmpty(Stack))
    return NULL;

  return Stack->s[Stack->Top];
}


/*           �ǻ�������               */
/*��ӡջ������Ԫ�أ�����ɾ��ջ��Ԫ�أ�*/
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

