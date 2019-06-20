/*链式队列结点结构*/
struct NODE_TYPE
{
    int Data;    
	/*后继结点,负责建立队列各结点之间的联系，前一个结点的pNext指向后一个结点，形成链式队列*/
    struct NODE_TYPE *pNext;  
};
/* 链式队列结构*/
struct LINK_QUEUE
{
    struct NODE_TYPE *front;      /*链式队列的队头指针，总是指向队列的头结点(出队一次，第二个结点变为头结点)*/
    struct NODE_TYPE *rear;       /*链式队列的队尾指针，入队时指向新插入结点(总是指向队列的最后一个结点)*/
	int Length;
};
/*创建空队列： pQHead为队列头结点*/
void InitQueue(pQHead)
struct LINK_QUEUE *pQHead;
{
    /*队列头结点的队头和队尾指针申请内存*/
    pQHead->front=pQHead->rear = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!pQHead->front)	/*检测是否申请失败*/
        printf("pQHead->front malloc error!\n");
    /*设置头结点指针域为空*/
    pQHead->front->pNext = NULL;
	pQHead->Length=0;
}
/*判断队列是否为空*/
int IsEmpty(pQHead)
struct LINK_QUEUE *pQHead;
{
    /*队头指针与队尾指针相等，说明队列为空*/
    return(!pQHead->Length);
}
/*新元素入队:即链式队列的尾结点指针，指向存放新元素的新结点*/
void Add(pQHead,x)
struct LINK_QUEUE *pQHead;
int x;
{
    /*创建新结点,并申请内存*/
    struct NODE_TYPE *temp = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!temp)
        printf("temp malloc error!\n");
    temp->Data = x;		
    temp->pNext = NULL;		/*队列只能从队尾插入所以下一个结点初始化为NULL*/ 
    pQHead->rear->pNext = temp;		/*将队尾结点的后继指针指向新结点*/    
    pQHead->rear = temp;	/*将队尾结点的指针指向新结点temp,temp变为最后一个结点*/ 
	pQHead->Length++;
}

int Del(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp;
    if(IsEmpty(pQHead))	/*如果队列为空,则返回Error*/ 
    {
        printf("Error! Queue Empty!\n");
        return 0;
    }
    temp = pQHead->front->pNext;	/*初始化temp为要出队的结点的指针*/ 
    /*如果要出队的结点为最后一个结点,使q->rear指向头结点防止出现悬空的指针*/ 
    if(pQHead->front->pNext == pQHead->rear)
        pQHead->rear = pQHead->front;
    pQHead->front->pNext = temp->pNext; /*使下一个结点成为队头,如果没有下一个结点则为NULL*/ 
    free(temp); /*删除要出队的结点*/ 
	pQHead->Length--;
    return 1;
}
/*取队首*/
int GetFront(pQHead,y)
struct LINK_QUEUE *pQHead;
int *y;
{
	if(IsEmpty(pQHead))
	{
		printf("\tQueue Empty!");
		return 0;
	}
	*y=pQHead->front->pNext->Data;
	return 1;
}

/*取队尾*/
int GetRear(pQHead,y)
struct LINK_QUEUE *pQHead;
int *y;
{
	if(IsEmpty(pQHead))
	{
		printf("\tQueue Empty!");
		return 0;
	}
	*y=pQHead->rear->Data;
	return 1;
}
/*清空队列*/ 
void Clear(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp=pQHead->front->pNext;
    while(temp)
	{
		pQHead->front->pNext = temp->pNext;
		free(temp);
		temp=pQHead->front->pNext;
	}
	pQHead->rear=pQHead->front;	
	pQHead->Length=0;
}

void PrintNode(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp = pQHead->front;
	int i=1;
	/*如果队列为空退出*/
    if(IsEmpty(pQHead)){
        printf("Queue Empty!");
		return;
    }
	printf("\n");
    printf("打印队列中的所有元素:\n");
	printf("\n\tNode:");
	printf("\n\t");
	for(i=1;i<=pQHead->Length;i++)
        printf("\t-> %d",i);
	printf("\n\tData:");
	while(temp!= pQHead->rear)
    {
        temp = temp->pNext;
        printf("\t   %d",temp->Data);
    }
	printf("\n\t\t   Front");
	printf("\n\t");
	for(i=1;i<=pQHead->Length;i++)
		printf("\t");
	printf("   Rear");
    printf("\n");
}
/*文本颜色设置*/ 
void TextColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c); /*根据C的值设置字体颜色*/
} 
/*入队四个元素，出队两个元素，重复执行三次*/ 
void In_OutPut(pQHead)
struct LINK_QUEUE *pQHead;
{
	int i,j,y;
	for(j=0;j<3;j++)
    {
		for(i=0;i<4;i++)
        {   
            printf("Please enter an element (%d/4): ",i+1);
            Add(pQHead,IsRigth(&i,&j));
        }
        for(i=0;i<2;i++)
        {  
            Del(pQHead);
        }
        PrintNode(pQHead);
        GetFront(pQHead,&y);
        printf("\nFrond : %d\n",y);
        GetRear(pQHead,&y);
        printf("Rear  : %d\n\n",y);
    }
}
int IsRigth(int *i,int *j)
{
	char *a[50];
	scanf("%s",a);
	for(;strspn(a, "0123456789")!=strlen(a);)/*输入错误错误则进行提示，直到正确跳出*/ 
	{
		TextColor(4);
		printf("Input is wrong\n"); 
		TextColor(7);
		if(*i>=0&&*j<0)
			printf("Please enter an integer\nPlease enter the %dth element : ",*i+1);
		else if(*i<0&&*j<0)
			printf("Please enter an integer: ");			
		else
			printf("Please enter an element (%d/4): ",*i+1);
		scanf("%s",a);
		 
		
	}
	return atoi(a);/*返回输入类型正确的数据*/ 
}	