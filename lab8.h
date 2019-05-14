// 链式队列结点结构
struct NODE_TYPE
{
    int Data;    //结点数据
    //【负责建立队列各结点之间的联系，前一个结点的next指向后一个结点，形成链式队列
    struct NODE_TYPE *pNext;  //后继结点
};
// 链式队列结构
struct LINK_QUEUE
{
    struct NODE_TYPE *front;      //链式队列的队头指针，总是指向队列的头结点(出队一次，第二个结点变为头结点)
    struct NODE_TYPE *rear;       //链式队列的队尾指针，入队时指向新插入结点(总是指向队列的最后一个结点)
	int Length;
};
//创建空队列： pQHead即为队列头结点
void InitQueue(pQHead)
struct LINK_QUEUE *pQHead;
{
    //队列头结点的队头和队尾指针申请内存
    pQHead->front=pQHead->rear = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!pQHead->front) //检测是否申请失败
        printf("pQHead->front malloc error!\n");
    //设置头结点指针域为空
    pQHead->front->pNext = NULL;
}
//判断队列是否为空
int IsEmpty(pQHead)
struct LINK_QUEUE *pQHead;
{
    //队头指针与队尾指针相等，说明队列为空
    if(pQHead->front == pQHead->rear)
        return 1;
    return 0;
}
//新元素入队:即链式队列的尾结点指针，指向存放新元素的新结点
void Add(pQHead,x)
struct LINK_QUEUE *pQHead;
int x;
{
    //创建新结点,并申请内存
    struct NODE_TYPE *temp = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!temp)
        printf("temp malloc error!\n");
    temp->Data = x; //将要插入元素存入新结点的数据域内
    temp->pNext = NULL; //队列只能从队尾插入所以下一个结点初始化为NULL
    //链式队列元素为结点(LQNode)
    //pQHead->rear为队列的最后一个结点，当插入新结点temp时,pQHead->rear->next = temp
    //使前一个结点的next指向新结点，建立队列各结点之间的联系
    pQHead->rear->pNext = temp; //将队尾结点的后继指针指向新结点,如果第一次入队，
                      //则pQueue->rear->next相当于pQueue->front->next
    // pQHead->rear总是指向队列的最后一个结点
    pQHead->rear = temp;    //将队尾结点的指针指向新结点temp,temp变为最后一个结点
}

int Del(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp;
    //如果队列为空,则返回ERRIR
    if(IsEmpty(pQHead))
    {
        printf("Queue Empty!\n");
        return 0;
    }
    //值入队一次后就出队，则pQueue->front->next==pQHead->rear->next,为第一个插入的结点
    temp = pQHead->front->pNext; //初始化temp为要出队的结点的指针
    //如果要出队的结点为最后一个结点,使q->rear指向头结点防止出现悬空的指针
    if(pQHead->front->pNext == pQHead->rear)
        pQHead->rear = pQHead->front;
    pQHead->front->pNext = temp->pNext; //使下一个结点成为队头,如果没有下一个结点则为NULL
    free(temp); //删除要出队的结点
    temp = NULL;
    return 1;
}

int GetFront(pQHead,y)
struct LINK_QUEUE *pQHead;
int *y;
{
	struct NODE_TYPE *temp = pQHead->front->pNext;
	if(IsEmpty(temp))
	{
		printf("\tQueue Empty!");
		return 0;
	}
	*y=temp->Data;
	return 1;
}

/*取队尾*/
int GetRear(pQHead,y)
struct LINK_QUEUE *pQHead;
int *y;
{
	struct NODE_TYPE *temp = pQHead->front;
	if(IsEmpty(temp))
	{
		printf("\tQueue Empty!");
		return 0;
	}
	while(temp!= pQHead->rear)
    {
        temp = temp->pNext;
    }
	if(IsEmpty(temp))
	{
		printf("\tQueue Empty!");
		return 0;
	}
	*y=temp->Data;
	return 1;
}
//清空队列
void Clear(pQHead)
struct LINK_QUEUE *pQHead;
{
    pQHead->front = pQHead->rear;
}

void PrintNode(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp = pQHead->front;
	int i=0;
	/*如果队列为空*/
    if(IsEmpty(pQHead)){
        printf("Queue Empty!");
		return;
    }
    printf("将队列中的所有元素出队:\n");
	/* printf("\nThe node in the QUEUE is:\n");*/
	temp = pQHead->front;
	printf("\n\t");
	while(temp!= pQHead->rear)
    {
        temp = temp->pNext;
        printf("\t-> %d",temp->Data);
    }
	printf("\n\t\tFront");
	printf("\n\t");
	temp = pQHead->front;
	while(temp!=pQHead->rear)
	{
		printf("\t");
		temp = temp->pNext;
	}
	printf("Rear");
    printf("\n");
}