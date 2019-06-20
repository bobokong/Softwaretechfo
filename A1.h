/*��ʽ���н��ṹ*/
struct NODE_TYPE
{
    int Data;    
	/*��̽��,���������и����֮�����ϵ��ǰһ������pNextָ���һ����㣬�γ���ʽ����*/
    struct NODE_TYPE *pNext;  
};
/* ��ʽ���нṹ*/
struct LINK_QUEUE
{
    struct NODE_TYPE *front;      /*��ʽ���еĶ�ͷָ�룬����ָ����е�ͷ���(����һ�Σ��ڶ�������Ϊͷ���)*/
    struct NODE_TYPE *rear;       /*��ʽ���еĶ�βָ�룬���ʱָ���²�����(����ָ����е����һ�����)*/
	int Length;
};
/*�����ն��У� pQHeadΪ����ͷ���*/
void InitQueue(pQHead)
struct LINK_QUEUE *pQHead;
{
    /*����ͷ���Ķ�ͷ�Ͷ�βָ�������ڴ�*/
    pQHead->front=pQHead->rear = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!pQHead->front)	/*����Ƿ�����ʧ��*/
        printf("pQHead->front malloc error!\n");
    /*����ͷ���ָ����Ϊ��*/
    pQHead->front->pNext = NULL;
	pQHead->Length=0;
}
/*�ж϶����Ƿ�Ϊ��*/
int IsEmpty(pQHead)
struct LINK_QUEUE *pQHead;
{
    /*��ͷָ�����βָ����ȣ�˵������Ϊ��*/
    return(!pQHead->Length);
}
/*��Ԫ�����:����ʽ���е�β���ָ�룬ָ������Ԫ�ص��½��*/
void Add(pQHead,x)
struct LINK_QUEUE *pQHead;
int x;
{
    /*�����½��,�������ڴ�*/
    struct NODE_TYPE *temp = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!temp)
        printf("temp malloc error!\n");
    temp->Data = x;		
    temp->pNext = NULL;		/*����ֻ�ܴӶ�β����������һ������ʼ��ΪNULL*/ 
    pQHead->rear->pNext = temp;		/*����β���ĺ��ָ��ָ���½��*/    
    pQHead->rear = temp;	/*����β����ָ��ָ���½��temp,temp��Ϊ���һ�����*/ 
	pQHead->Length++;
}

int Del(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp;
    if(IsEmpty(pQHead))	/*�������Ϊ��,�򷵻�Error*/ 
    {
        printf("Error! Queue Empty!\n");
        return 0;
    }
    temp = pQHead->front->pNext;	/*��ʼ��tempΪҪ���ӵĽ���ָ��*/ 
    /*���Ҫ���ӵĽ��Ϊ���һ�����,ʹq->rearָ��ͷ����ֹ�������յ�ָ��*/ 
    if(pQHead->front->pNext == pQHead->rear)
        pQHead->rear = pQHead->front;
    pQHead->front->pNext = temp->pNext; /*ʹ��һ������Ϊ��ͷ,���û����һ�������ΪNULL*/ 
    free(temp); /*ɾ��Ҫ���ӵĽ��*/ 
	pQHead->Length--;
    return 1;
}
/*ȡ����*/
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

/*ȡ��β*/
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
/*��ն���*/ 
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
	/*�������Ϊ���˳�*/
    if(IsEmpty(pQHead)){
        printf("Queue Empty!");
		return;
    }
	printf("\n");
    printf("��ӡ�����е�����Ԫ��:\n");
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
/*�ı���ɫ����*/ 
void TextColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c); /*����C��ֵ����������ɫ*/
} 
/*����ĸ�Ԫ�أ���������Ԫ�أ��ظ�ִ������*/ 
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
	for(;strspn(a, "0123456789")!=strlen(a);)/*�����������������ʾ��ֱ����ȷ����*/ 
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
	return atoi(a);/*��������������ȷ������*/ 
}	