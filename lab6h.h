/*       *******************************************        */
/*                      链式存储结构下栈的基本操作                           */
/*       *******************************************        */

/*初始化栈：创建一空栈*/
void Initiate(list_stack)
struct LIST_STACK *list_stack;
{
  list_stack->pTop=NULL;
  list_stack->Length=0;
}

/*栈判空：为空返回1；不空返回0*/
int IsEmpty(list_stack)
struct LIST_STACK *list_stack;
{
  return (list_stack->Length==0);
}

/*压栈操作：将数据元素x插入到栈顶*/
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

/*弹栈操作：将栈顶元素返回后删除该栈顶元素*/
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

/*读取栈顶元素（但不删除栈顶元素）*/
int GetTop(list_stack)
struct LIST_STACK *list_stack;
{
  int value;

  if(IsEmpty(list_stack))
    return NULL;

  value=list_stack->pTop->Data;
  return value;
}
