/*     **************************************************************************************************       */
/* 上机作业2：             顺序存储结构下线性表的基本运算                                                       */
/*                                                                                                              */
/* 利用提供的顺序存储结构下线性表基本运算的子程序，编程实现以下功能：                                           */
/* ①创建一个空表[Initiate( )]；                                                                                */
/* ②提示用户输入"线性表长度"；                                                                                 */
/* ③根据用户输入的"线性表长度"，逐一提示用户输入"线性表中的各个元素"，完成线性表的构造[Insert()]；             */
/* ④通过调用子程序Length() 打印输出当前线性表的长度；                                                          */
/* ⑤通过调用子程序*GetAt() 打印输出当前线性表的所有元素；(问：不调用子程序*GetAt()，如何实现？)                */
/* ⑥提示用户输入要查找的元素数值，通过调用子程序GetIndex()打印输出符合要求的第一个元素的位置；                 */
/*                                              *GetPrior()打印输出该元素的前驱元素值；                         */
/*                                              *GetNext() 打印输出该元素的后继元素值；                         */
/* ⑦通过调用子程序Insert()在当前线性表的表头和表尾各插入一个元素0，打印输出插入后的线性表；                    */
/* ⑧通过调用子程序Delete()删除⑦中插入的各个元素，打印输出删除后的线性表[*GetAt( )]；                          */
/* ⑨调用自行编写的顺序结构下线性表的逆转子程序Reverse( )，打印输出逆转后的线性表。                             */
/* ⑩要求：提供尽可能友好的人机对话界面，便于用户（非程序设计者）使用。                                         */
/*                                                                                                              */
/*     **************************************************************************************************       */

#include "stdio.h"
#include "math.h"
#define MAX_LEN 16

struct A
    {
      int list[MAX_LEN];
      int n;
    };

main()
{
  void Initiate();
  int Length();
  int *GetAt();
  int GetIndex();
  int *GetPrior();
  int *GetNext();
  int Insert();
  int Delete();
  void Reverse();
  /*下面填写主程序，完成上述功能要求*/
  int i,n,x,id,data,data1,data2;
  struct A aa;
  printf("Intiate List!\n");
/* ①创建一个空表[Initiate( )]；   */  
  Initiate(&aa);
/* ②提示用户输入"线性表长度"；*/
  printf("The length of list aa is:");
    scanf("%d",&n);
/* ③根据用户输入的"线性表长度"，逐一提示用户输入"线性表中的各个元素"，完成线性表的构造[Insert()]；*/
    for(i=1;i<=n;i++)
    {
      printf("Enter the %dth data :",i);
      scanf("%d",&x);
      Insert(&aa,i,x);
    }
  n=Length(&aa);
/* ④通过调用子程序Length() 打印输出当前线性表的长度； */      
  printf("The length of list is:\t%d\n",n);
/* ⑤通过调用子程序*GetAt() 打印输出当前线性表的所有元素；(问：不调用子程序*GetAt()，如何实现？) */
  printf("The list is:\n");
  for(i=1;i<=n;i++)
  {
    printf("The %dth is :%d\n",i,*GetAt(&aa,i));
   // printf("The %dth is :%d\n",i,aa.list[i-1]);
   }
/* ⑥提示用户输入要查找的元素数值，通过调用子程序GetIndex()打印输出符合要求的第一个元素的位置；                 */
/*                                              *GetPrior()打印输出该元素的前驱元素值；                         */
/*                                             *GetNext() 打印输出该元素的后继元素值；          */   
   printf("Enter the data to be searched :");
   scanf("%d",&data);
/* ⑦通过调用子程序Insert()在当前线性表的表头和表尾各插入一个元素0，打印输出插入后的线性表； */
   id=GetIndex(&aa,data);
   printf("Index of data %d is :\t%d\n",data,id);
   data1=*GetPrior(&aa,data);
   printf("Prior of data %d is :\t%d\n",data,data1);
   data2=*GetNext(&aa,data);
   printf("Next of data %d is:\t %d\n",data,data2);
   printf("Insert data 0 into Head and End of list!\n");
   Insert(&aa,1,0);
   Insert(&aa,aa.n+1,0);
   printf("The list after insert operation is :\n");
   for(i=1;i<=aa.n;i++)
   printf("\tThe %dth data is : %d\n",i,aa.list[i-1]);
/* ⑧通过调用子程序Delete()删除⑦中插入的各个元素，打印输出删除后的线性表[*GetAt( )]；*/
   printf("delete the data Insert!\n");
   Delete(&aa,1);
   Delete(&aa,aa.n);
   printf("The list after Insert operation is :\n");
   for(i=1;i<=aa.n;i++)
   printf("\tThe %dth data is : %d\n",i,aa.list[i-1]);
   printf("Reverse list!\n");
   Reverse(&aa);
   printf("The list after Reverse operation is :\n");
  for(i=1;i<=aa.n;i++)
   printf("\tThe %dth data is : %d\n",i,aa.list[i-1]); 
  getch();

}
/* ⑨调用自行编写的顺序结构下线性表的逆转子程序Reverse( )，打印输出逆转后的线性表。     */
void Reverse(a)
/*元素下标与元素个数不对应；元素下标=元素个数-1*/
struct A *a;
{
  /*下面填写子程序，完成顺序结构下线性表的逆转*/

int i;

  for(i=0;i<=floor(a->n/2)-1;i++)
    {
      a->list[i]=a->list[i]^a->list[a->n-i-1];
      a->list[a->n-i-1]=a->list[a->n-i-1]^a->list[i];
      a->list[i]=a->list[i]^a->list[a->n-i-1];
    }
}

/*下面为：顺序结构下线性表的基本操作子程序*/

/*初始化线性表：创建一空表*/
/*元素下标与元素个数不对应；元素下标=元素个数-1*/
void Initiate(a)
struct A *a;
{
  a->n=0;
  /*元素下标与元素个数对应；空表里有一个0元素*/
  /*  a->list[0]=0;                          */
}

/*取线性表的长度：共有几个有效结点*/
/*元素下标与元素个数不对应；元素下标=元素个数-1*/
int Length(a)
struct A *a;
{
  return a->n;
}


/*元素下标与元素个数不对应；元素下标=元素个数-1*/
/*读取第I个元素*/
int *GetAt(a,I)
struct A *a;
int I;
{
  if((I>=1)&&(I<=a->n))
    return &a->list[I-1];
  else
    return NULL;
}

/*元素下标与元素个数不对应；元素下标=元素个数-1*/
/*返回元素x的序号（线性表中第几个元素）*/
int GetIndex(a,x)
struct A *a;
int x;
{
  int k;
  for(k=0;k<a->n;k++)
    {
      if(a->list[k]==x)
      return k+1;
    }
  return 0;
}


/*元素下标与元素个数不对应；元素下标=元素个数-1*/
/*返回元素x的前驱元素*/
int *GetPrior(a,x)
struct A *a;
int x;
{
  int k;
  k=GetIndex(a,x);
  if(k>1)
    return GetAt(a,k-1);
  else
    return NULL;
}

/*元素下标与元素个数不对应；元素下标=元素个数-1*/
/*返回元素x的后继元素*/
int *GetNext(a,x)
struct A *a;
int x;
{
  int k;
  k=GetIndex(a,x);
  if(k<a->n)
    return GetAt(a,k+1);   /*若元素x在线性表中不存在，则返回线性表第一个元素*/
  else
    return NULL;
}

/*bool Insert(a,I,x)*/       /*元素下标与元素个数不对应；元素下标=元素个数-1*/
int Insert(a,I,x)            /*将元素x插入到线性表的第I个元素的位置，线性表长度加1*/
struct A *a;
int I;
int x;
{
/*空表的处理：插在表头第一个元素*/
/*非空表的处理：插在表中或最后一个元素的后面*/
  if((I>=1)&&(I<=a->n+1)&&(a->n<MAX_LEN))
    {
      int k;
      for(k=a->n;k>=I;k--)              /*后移第k个元素：a->list[k-1]*/
        {
            a->list[k]=a->list[k-1];    /*元素下标与元素个数不对应；元素下标=元素个数-1*/
        }
      a->list[I-1]=x;
      a->n++;
      return 1; /*插入成功*/
    }
  else
    return 0;   /*插入失败*/
}


/*元素下标与元素个数不对应；元素下标=元素个数-1*/
/*删除线性表中第I个元素，线性表长度减1*/
int Delete(a,I) /*bool Delete(a,I)*/
struct A *a;
int I;
{
  int k;
  if((I>=1)&&(I<=a->n))
    {
      for(k=I+1;k<=a->n;k++)              /*前移第k个元素：a->list[k-1]*/
        {
            a->list[k-2]=a->list[k-1];    /*元素下标与元素个数不对应；元素下标=元素个数-1*/
        }
      a->n--;
      return 1;     /*删除成功*/
    }
  else
    return 0;       /*删除失败*/
}
