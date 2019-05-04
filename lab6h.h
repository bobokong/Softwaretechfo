/*       *******************************************        */
/*                      ��ʽ�洢�ṹ��ջ�Ļ�������                           */
/*       *******************************************        */

/*��ʼ��ջ������һ��ջ*/
void Initiate(list_stack)
struct LIST_STACK *list_stack;
{
  list_stack->pTop=NULL;
  list_stack->Length=0;
}

/*ջ�пգ�Ϊ�շ���1�����շ���0*/
int IsEmpty(list_stack)
struct LIST_STACK *list_stack;
{
  return (list_stack->Length==0);
}

/*ѹջ������������Ԫ��x���뵽ջ��*/
void Push(list_stack,x)
struct LIST_STACK *list_stack;
int x;
{
  struct NODE_TYPE *pNewNode;

  pNewNode=(struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
  pNewNode->Data=x;
  pNewNode->pNext=list_stack->pTop;

  list_stack->pTop=pNewNode;
  list_stack->Length++;
}

/*��ջ��������ջ��Ԫ�ط��غ�ɾ����ջ��Ԫ��*/
int Pop(list_stack)
struct LIST_STACK *list_stack;
{
  int value;
  struct NODE_TYPE *pNode;

  if(IsEmpty(list_stack))
    return NULL;

  value=list_stack->pTop->Data;
  pNode=list_stack->pTop;
  list_stack->pTop=pNode->pNext;

  free(pNode);
  list_stack->Length--;
  return value;
}

/*��ȡջ��Ԫ�أ�����ɾ��ջ��Ԫ�أ�*/
int GetTop(list_stack)
struct LIST_STACK *list_stack;
{
  int value;

  if(IsEmpty(list_stack))
    return NULL;

  value=list_stack->pTop->Data;
  return value;
}
