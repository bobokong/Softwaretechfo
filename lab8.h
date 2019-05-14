// ��ʽ���н��ṹ
struct NODE_TYPE
{
    int Data;    //�������
    //�����������и����֮�����ϵ��ǰһ������nextָ���һ����㣬�γ���ʽ����
    struct NODE_TYPE *pNext;  //��̽��
};
// ��ʽ���нṹ
struct LINK_QUEUE
{
    struct NODE_TYPE *front;      //��ʽ���еĶ�ͷָ�룬����ָ����е�ͷ���(����һ�Σ��ڶ�������Ϊͷ���)
    struct NODE_TYPE *rear;       //��ʽ���еĶ�βָ�룬���ʱָ���²�����(����ָ����е����һ�����)
	int Length;
};
//�����ն��У� pQHead��Ϊ����ͷ���
void InitQueue(pQHead)
struct LINK_QUEUE *pQHead;
{
    //����ͷ���Ķ�ͷ�Ͷ�βָ�������ڴ�
    pQHead->front=pQHead->rear = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!pQHead->front) //����Ƿ�����ʧ��
        printf("pQHead->front malloc error!\n");
    //����ͷ���ָ����Ϊ��
    pQHead->front->pNext = NULL;
}
//�ж϶����Ƿ�Ϊ��
int IsEmpty(pQHead)
struct LINK_QUEUE *pQHead;
{
    //��ͷָ�����βָ����ȣ�˵������Ϊ��
    if(pQHead->front == pQHead->rear)
        return 1;
    return 0;
}
//��Ԫ�����:����ʽ���е�β���ָ�룬ָ������Ԫ�ص��½��
void Add(pQHead,x)
struct LINK_QUEUE *pQHead;
int x;
{
    //�����½��,�������ڴ�
    struct NODE_TYPE *temp = (struct NODE_TYPE *)malloc(sizeof(struct NODE_TYPE));
    if(!temp)
        printf("temp malloc error!\n");
    temp->Data = x; //��Ҫ����Ԫ�ش����½�����������
    temp->pNext = NULL; //����ֻ�ܴӶ�β����������һ������ʼ��ΪNULL
    //��ʽ����Ԫ��Ϊ���(LQNode)
    //pQHead->rearΪ���е����һ����㣬�������½��tempʱ,pQHead->rear->next = temp
    //ʹǰһ������nextָ���½�㣬�������и����֮�����ϵ
    pQHead->rear->pNext = temp; //����β���ĺ��ָ��ָ���½��,�����һ����ӣ�
                      //��pQueue->rear->next�൱��pQueue->front->next
    // pQHead->rear����ָ����е����һ�����
    pQHead->rear = temp;    //����β����ָ��ָ���½��temp,temp��Ϊ���һ�����
}

int Del(pQHead)
struct LINK_QUEUE *pQHead;
{
	struct NODE_TYPE *temp;
    //�������Ϊ��,�򷵻�ERRIR
    if(IsEmpty(pQHead))
    {
        printf("Queue Empty!\n");
        return 0;
    }
    //ֵ���һ�κ�ͳ��ӣ���pQueue->front->next==pQHead->rear->next,Ϊ��һ������Ľ��
    temp = pQHead->front->pNext; //��ʼ��tempΪҪ���ӵĽ���ָ��
    //���Ҫ���ӵĽ��Ϊ���һ�����,ʹq->rearָ��ͷ����ֹ�������յ�ָ��
    if(pQHead->front->pNext == pQHead->rear)
        pQHead->rear = pQHead->front;
    pQHead->front->pNext = temp->pNext; //ʹ��һ������Ϊ��ͷ,���û����һ�������ΪNULL
    free(temp); //ɾ��Ҫ���ӵĽ��
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

/*ȡ��β*/
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
//��ն���
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
	/*�������Ϊ��*/
    if(IsEmpty(pQHead)){
        printf("Queue Empty!");
		return;
    }
    printf("�������е�����Ԫ�س���:\n");
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