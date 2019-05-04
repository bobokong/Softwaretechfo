#include "stdio.h"
#include "malloc.h"     /*������̬�ڴ���亯����ͷ�ļ�*/
#include"string.h"
#define N 5

struct student
{
   char num[12];
   char name[8];
   char sex;
   int  score;
};

typedef struct node
{
  struct student stu;
  struct node *pnext;
}stud; 

stud *input(int n)      /*����������ĺ������β�nΪ����*/
{
  stud *p,*h,*s;         /* *h�����ͷ����ָ�룬*pָ��ǰ����ǰһ����㣬*sָ��ǰ���*/
  int i;                 /*������*/

  if((h=(stud *)malloc(sizeof(stud)))==NULL) /*����ռ䲢���*/
  {
    printf("Can not allocate memory!");      /*���ܷ����ڴ�ռ�*/
    exit(0);
  }

  h->stu.name[0]='\0';  /*�ѱ�ͷ���������������ÿ�*/
  h->pnext=NULL;        /*�ѱ�ͷ���������ÿ�*/

  p=h;                  /*pָ���ͷ���*/
  for(i=0;i<n;i++)
  {
    if((s= (stud *) malloc(sizeof(stud)))==NULL) /*�����´洢�ռ䲢���*/
    {
      printf("Can not allocate memory!");      /*���ܷ����ڴ�ռ�*/
      exit(0);
    }

    p->pnext=s;         /*��s�ĵ�ַ����p��ָ��Ľ������������Ͱ�p��s��ָ��Ľ������������*/
    printf("Please enter the num of the %dth person: \t",i+1);         /*��ʾ����ڣ����˵�ѧ��*/
    scanf("%s",s->stu.num);                                           /*�ڵ�ǰ���s���������д洢ѧ��*/

    printf("Please enter the name of the %dth person:\t",i+1);        /*��ʾ����ڣ����˵�����*/
    scanf("%s",s->stu.name);                                          /*�ڵ�ǰ���s���������д洢����*/

    printf("Please enter the sex of the %dth person(m OR f):\t",i+1); /*��ʾ����ڣ����˵��Ա�*/
    scanf("%s",&s->stu.sex);                                          /*�ڵ�ǰ���s���������д洢�Ա�*/

    printf("Please enter the score of the %dth person:\t",i+1);       /*��ʾ����ڣ����˵ĳɼ�*/
    scanf("%d",&s->stu.score);                                        /*�ڵ�ǰ���s���������д洢�ɼ�*/

    s->pnext=NULL;

    printf("\n");

    p=s;
  }

  return(h);
} 

void print(stud *h)
{
	stud *P=h;
	printf("NUMBER      NAME      SEX     SCORE");
	if(h!=0)
	do
	{    
	printf("%-12s%-10s%-8c%-8d\n",P->stu.num,P->stu.name,P->stu.sex,P->stu.score);             
	P=P->pnext  ; 
	}
	while(P!=NULL);
}
void sex(stud *head)
{
	stud *P=head;
	int m=0,f=0;
	if(head!=0)
	do
	{    
	if(P->stu.sex=='m')
		m=m+1;
	else if(P->stu.sex=='f')
		f=f+1;           
	P=P->pnext  ; 
	}
	while(P!=NULL);
	printf("The number of Male(Female) is %d(%d)",m,f);
}


void main()
{
	stud *head;          /*head�Ǳ��浥����ı�ͷ����ַ��ָ��*/ 
	head=input(N);       /*�����������½��ĵ������ͷ��ַ����head*/  
	print(head);         /*��ӡ���*/
	sex(head);           /*ͳ����Ů*/
	getchar();  
}
