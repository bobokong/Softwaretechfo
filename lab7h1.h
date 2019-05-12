/* ѭ������ */
/* ʵ�ַ�ʽһ:����һ����־    QueueFull*/

#define MAX_LEN 8
struct QUEUE
    {
      int Q[MAX_LEN];
      int Front,Rear;
      int QueueFull;
    };

/*�����±���Ԫ�ظ�������Ӧ������Ԫ���±�=Ԫ�ظ���-1*/
/*��ʼ�����У�����һ�ն���*/
void InitQueue(Queue)
struct QUEUE *Queue;
{
 Queue->Front=MAX_LEN-1;
 Queue->Rear=MAX_LEN-1;
 Queue->QueueFull=0;
}

/*�����п�*/
int IsEmpty(Queue)
struct QUEUE *Queue;
{
  return (Queue->Front==Queue->Rear)&&(!Queue->QueueFull);
}

/*��������*/
int IsFull(Queue)
struct QUEUE *Queue;
{
 return (Queue->Front==Queue->Rear)&&(Queue->QueueFull);
}

/*��ն���*/
void Clear(Queue)
struct QUEUE *Queue;
{
 Queue->Front=MAX_LEN-1;
 Queue->Rear=MAX_LEN-1;
 Queue->QueueFull=0;
}

/*��Ӳ������ڶ�β����һ����Ԫ��x */
void Add(Queue,x)
struct QUEUE *Queue;
int x;
{
 if(IsFull(Queue))
   {
      printf("Queue Full!\n");
      return;
   }
  Queue->Rear=(Queue->Rear+1)%MAX_LEN;
  Queue->Q[Queue->Rear]=x;
  if(Queue->Rear==Queue->Front)
      Queue->QueueFull=1;
}

/*���Ӳ�����ɾ������Ԫ�أ�����Ԫ��ֵ�����y��*/
void Del(Queue,y)
struct QUEUE *Queue;
int *y;
{
 if(IsEmpty(Queue))
   {
      printf("Queue Empty!\n");
      return;
   }
  Queue->Front=(Queue->Front+1)%MAX_LEN;
  *y=Queue->Q[Queue->Front];
  Queue->QueueFull=0;
}

/*ȡ����*/
int GetFront(Queue,y)
struct QUEUE *Queue;
int *y;
{
 if(IsEmpty(Queue))
   {
      printf("\tQueue Empty!");
      return 0;
   }
  *y=Queue->Q[(Queue->Front+1)%MAX_LEN];
  return 1;
}

/*ȡ��β*/
int GetRear(Queue,y)
struct QUEUE *Queue;
int *y;
{
 if(IsEmpty(Queue))
   {
      printf("\tQueue Empty!");
      return 0;
   }
  *y=Queue->Q[Queue->Rear];
  return 1;
}


/*��ӡѭ�����У���������ṹ*/
void PrintNode(Queue)
struct QUEUE *Queue;
{
 int i;

 printf("\n\tNode:");
 for(i=0;i<MAX_LEN;i++)
   {
      printf("\t %d",i);
   }

 printf("\n\tData:");
 for(i=0;i<MAX_LEN;i++)
   {
      printf("\t %d",Queue->Q[i]);
   }

 printf("\n\t");
 for(i=0;i<MAX_LEN;i++)
   {
      printf("\t");
      if(i==Queue->Front)
        printf("Front");
   }

 printf("\n\t");
 for(i=0;i<MAX_LEN;i++)
   {
      printf("\t");
      if(i==Queue->Rear)
        printf("Rear");
   }

 printf("\n");
}

/*��ӡѭ�����У����ڶ��нṹ*/
void PrintNode_1(Queue)
struct QUEUE *Queue;
{
 int i;
 if(IsEmpty(Queue))
   {
      printf("Queue Empty!");
      return;
   }
/* printf("\nThe node in the QUEUE is:\n");*/
 printf("\n\tNode:");
 i=(Queue->Front+1)%MAX_LEN;
 while(i<=Queue->Rear)
   {
      printf("\t %d",i);
      i=(i+1)%MAX_LEN;
   }

 printf("\n\tData:");
 i=(Queue->Front+1)%MAX_LEN;
 while(i<=Queue->Rear)
   {
      printf("\t %d",Queue->Q[i]);
      i=(i+1)%MAX_LEN;
   }
 printf("\n\t\tFront");

 printf("\n\t");
 i=(Queue->Front+1)%MAX_LEN;
 while(i<=Queue->Rear)
   {
      printf("\t");
      i=(i+1)%MAX_LEN;
   }
 printf("Rear");

 printf("\n");
/* printf("That's all!");*/
}
