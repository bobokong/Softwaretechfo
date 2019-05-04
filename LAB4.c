#include "stdio.h"
#include "malloc.h"     /*包含动态内存分配函数的头文件*/
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

stud *input(int n)      /*建立单链表的函数，形参n为人数*/
{
  stud *p,*h,*s;         /* *h保存表头结点的指针，*p指向当前结点的前一个结点，*s指向当前结点*/
  int i;                 /*计数器*/

  if((h=(stud *)malloc(sizeof(stud)))==NULL) /*分配空间并检测*/
  {
    printf("Can not allocate memory!");      /*不能分配内存空间*/
    exit(0);
  }

  h->stu.name[0]='\0';  /*把表头结点的姓名数据域置空*/
  h->pnext=NULL;        /*把表头结点的链域置空*/

  p=h;                  /*p指向表头结点*/
  for(i=0;i<n;i++)
  {
    if((s= (stud *) malloc(sizeof(stud)))==NULL) /*分配新存储空间并检测*/
    {
      printf("Can not allocate memory!");      /*不能分配内存空间*/
      exit(0);
    }

    p->pnext=s;         /*把s的地址赋给p所指向的结点的链域，这样就把p和s所指向的结点连接起来了*/
    printf("Please enter the num of the %dth person: \t",i+1);         /*提示输入第？个人的学号*/
    scanf("%s",s->stu.num);                                           /*在当前结点s的数据域中存储学号*/

    printf("Please enter the name of the %dth person:\t",i+1);        /*提示输入第？个人的姓名*/
    scanf("%s",s->stu.name);                                          /*在当前结点s的数据域中存储姓名*/

    printf("Please enter the sex of the %dth person(m OR f):\t",i+1); /*提示输入第？个人的性别*/
    scanf("%s",&s->stu.sex);                                          /*在当前结点s的数据域中存储性别*/

    printf("Please enter the score of the %dth person:\t",i+1);       /*提示输入第？个人的成绩*/
    scanf("%d",&s->stu.score);                                        /*在当前结点s的数据域中存储成绩*/

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
	stud *head;          /*head是保存单链表的表头结点地址的指针*/ 
	head=input(N);       /*创建：把所新建的单链表表头地址赋给head*/  
	print(head);         /*打印输出*/
	sex(head);           /*统计男女*/
	getchar();  
}
