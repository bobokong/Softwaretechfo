/*    链式存储结构下线性表的基本操作     */


/*初始化链表：创建一空链表*/
void Initiate(list)
struct LIST_TYPE *list;
{
  list->pHead=NULL;
  list->Length=0;
}

/*取链表的长度：共有几个结点*/
int Length(list)
struct LIST_TYPE *list;
{
  return list->Length;
}

/*读取序号为I的结点（即链表中的第I个结点）的数据域*/
int *GetAt(list,I)
struct LIST_TYPE *list;
int I;
{
  int k;
  struct NODE_TYPE *pNode=list->pHead;
  if((I>=1)&&(I<=list->Length))
    {
      for(k=1;k<I;k++)
        {
            pNode=pNode->pNext;
        }
      return &pNode->Data;
    }
  else
    return NULL;
}

/*查找数据域为x的结点*/
struct NODE_TYPE *Find(list,x)
struct LIST_TYPE *list;
int x;
{
  int k;
  struct NODE_TYPE *pNode=list->pHead;
  while(pNode!=NULL)
    {
      if(pNode->Data==x)
         return pNode;
      pNode=pNode->pNext;
    }
  return NULL;
}

/*查找数据域为x的结点的前驱结点*/
struct NODE_TYPE *GetPrior(list,x)
struct LIST_TYPE *list;
int x;
{
  int k;
  struct NODE_TYPE *pNode=list->pHead;
  if(!pNode)
    return NULL;
  if(pNode->pNext==NULL)
    return NULL;
  while(pNode->pNext!=NULL)
    {
      if(pNode->pNext->Data==x)
        return pNode;
      pNode=pNode->pNext;
    }
  return NULL;
}

/*查找数据域为x的结点的后继结点*/
struct NODE_TYPE *GetNext(list,x)
struct LIST_TYPE *list;
int x;
{
  struct NODE_TYPE *pNode=Find(list,x);
  if(!pNode)
    return NULL;
  else
    return pNode->pNext;
}

/*在链表的第I个结点位置插入数据域为x的结点*/
/*bool　Insert(list,I,x)*/
int Insert(list,I,x)
struct LIST_TYPE *list;
int I;
int x;
{
  struct NODE_TYPE *pNewNode;
  struct NODE_TYPE *pPreNode;
  int i;

  if((I>list->Length+1)||(I<=0))
    return 0;

  if(I==1)
    {
      pNewNode=(struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
      pNewNode->Data=x;
      pNewNode->pNext=list->pHead;
      list->pHead=pNewNode;
      list->Length++;
      return 1;
    }

  pPreNode=list->pHead;
  for(i=1;i<I-1;i++)
    {
       pPreNode=pPreNode->pNext;
    }

  pNewNode=(struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
  pNewNode->Data=x;
  pNewNode->pNext=pPreNode->pNext;
  pPreNode->pNext=pNewNode;
  list->Length++;
  return 1;
}

/*删除链表的第I个结点*/
int Delete(list,I)
struct LIST_TYPE *list;
int I;
{
  struct NODE_TYPE *pDelNode;
  struct NODE_TYPE *pPreNode;
  int i;

  if((I>list->Length)||(I<=0))
    return 0;

  if(I==1)
    {
      pDelNode=list->pHead;
      list->pHead=pDelNode->pNext;
      free(pDelNode);
      list->Length--;
      return 1;
    }

  pPreNode=list->pHead;
  for(i=1;i<I-1;i++)
    {
       pPreNode=pPreNode->pNext;
    }

  pDelNode=pPreNode->pNext;
  pPreNode->pNext=pDelNode->pNext;
  free(pDelNode);
  list->Length--;
  return 1;
}

/*print the list*/
int PrintList(list)
struct LIST_TYPE *list;
{
  struct NODE_TYPE *pNode;
  int i;

  pNode=list->pHead;
  printf("\n\t\t");
  for(i=1;i<=Length(list);i++)
   {
     printf(" %d ->\t",pNode->Data);
     pNode=pNode->pNext;
   }
  printf("NULL\n");
}
