/*     **************************************************************************************************       */
/* �ϻ���ҵ2��             ˳��洢�ṹ�����Ա�Ļ�������                                                       */
/*                                                                                                              */
/* �����ṩ��˳��洢�ṹ�����Ա����������ӳ��򣬱��ʵ�����¹��ܣ�                                           */
/* �ٴ���һ���ձ�[Initiate( )]��                                                                                */
/* ����ʾ�û�����"���Ա���"��                                                                                 */
/* �۸����û������"���Ա���"����һ��ʾ�û�����"���Ա��еĸ���Ԫ��"��������Ա�Ĺ���[Insert()]��             */
/* ��ͨ�������ӳ���Length() ��ӡ�����ǰ���Ա�ĳ��ȣ�                                                          */
/* ��ͨ�������ӳ���*GetAt() ��ӡ�����ǰ���Ա������Ԫ�أ�(�ʣ��������ӳ���*GetAt()�����ʵ�֣�)                */
/* ����ʾ�û�����Ҫ���ҵ�Ԫ����ֵ��ͨ�������ӳ���GetIndex()��ӡ�������Ҫ��ĵ�һ��Ԫ�ص�λ�ã�                 */
/*                                              *GetPrior()��ӡ�����Ԫ�ص�ǰ��Ԫ��ֵ��                         */
/*                                              *GetNext() ��ӡ�����Ԫ�صĺ��Ԫ��ֵ��                         */
/* ��ͨ�������ӳ���Insert()�ڵ�ǰ���Ա�ı�ͷ�ͱ�β������һ��Ԫ��0����ӡ������������Ա�                    */
/* ��ͨ�������ӳ���Delete()ɾ�����в���ĸ���Ԫ�أ���ӡ���ɾ��������Ա�[*GetAt( )]��                          */
/* ��������б�д��˳��ṹ�����Ա����ת�ӳ���Reverse( )����ӡ�����ת������Ա�                             */
/* ��Ҫ���ṩ�������Ѻõ��˻��Ի����棬�����û����ǳ�������ߣ�ʹ�á�                                         */
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
  /*������д�����������������Ҫ��*/
  int i,n,x,id,data,data1,data2;
  struct A aa;
  printf("Intiate List!\n");
/* �ٴ���һ���ձ�[Initiate( )]��   */  
  Initiate(&aa);
/* ����ʾ�û�����"���Ա���"��*/
  printf("The length of list aa is:");
    scanf("%d",&n);
/* �۸����û������"���Ա���"����һ��ʾ�û�����"���Ա��еĸ���Ԫ��"��������Ա�Ĺ���[Insert()]��*/
    for(i=1;i<=n;i++)
    {
      printf("Enter the %dth data :",i);
      scanf("%d",&x);
      Insert(&aa,i,x);
    }
  n=Length(&aa);
/* ��ͨ�������ӳ���Length() ��ӡ�����ǰ���Ա�ĳ��ȣ� */      
  printf("The length of list is:\t%d\n",n);
/* ��ͨ�������ӳ���*GetAt() ��ӡ�����ǰ���Ա������Ԫ�أ�(�ʣ��������ӳ���*GetAt()�����ʵ�֣�) */
  printf("The list is:\n");
  for(i=1;i<=n;i++)
  {
    printf("The %dth is :%d\n",i,*GetAt(&aa,i));
   // printf("The %dth is :%d\n",i,aa.list[i-1]);
   }
/* ����ʾ�û�����Ҫ���ҵ�Ԫ����ֵ��ͨ�������ӳ���GetIndex()��ӡ�������Ҫ��ĵ�һ��Ԫ�ص�λ�ã�                 */
/*                                              *GetPrior()��ӡ�����Ԫ�ص�ǰ��Ԫ��ֵ��                         */
/*                                             *GetNext() ��ӡ�����Ԫ�صĺ��Ԫ��ֵ��          */   
   printf("Enter the data to be searched :");
   scanf("%d",&data);
/* ��ͨ�������ӳ���Insert()�ڵ�ǰ���Ա�ı�ͷ�ͱ�β������һ��Ԫ��0����ӡ������������Ա� */
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
/* ��ͨ�������ӳ���Delete()ɾ�����в���ĸ���Ԫ�أ���ӡ���ɾ��������Ա�[*GetAt( )]��*/
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
/* ��������б�д��˳��ṹ�����Ա����ת�ӳ���Reverse( )����ӡ�����ת������Ա�     */
void Reverse(a)
/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
struct A *a;
{
  /*������д�ӳ������˳��ṹ�����Ա����ת*/

int i;

  for(i=0;i<=floor(a->n/2)-1;i++)
    {
      a->list[i]=a->list[i]^a->list[a->n-i-1];
      a->list[a->n-i-1]=a->list[a->n-i-1]^a->list[i];
      a->list[i]=a->list[i]^a->list[a->n-i-1];
    }
}

/*����Ϊ��˳��ṹ�����Ա�Ļ��������ӳ���*/

/*��ʼ�����Ա�����һ�ձ�*/
/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
void Initiate(a)
struct A *a;
{
  a->n=0;
  /*Ԫ���±���Ԫ�ظ�����Ӧ���ձ�����һ��0Ԫ��*/
  /*  a->list[0]=0;                          */
}

/*ȡ���Ա�ĳ��ȣ����м�����Ч���*/
/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
int Length(a)
struct A *a;
{
  return a->n;
}


/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
/*��ȡ��I��Ԫ��*/
int *GetAt(a,I)
struct A *a;
int I;
{
  if((I>=1)&&(I<=a->n))
    return &a->list[I-1];
  else
    return NULL;
}

/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
/*����Ԫ��x����ţ����Ա��еڼ���Ԫ�أ�*/
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


/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
/*����Ԫ��x��ǰ��Ԫ��*/
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

/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
/*����Ԫ��x�ĺ��Ԫ��*/
int *GetNext(a,x)
struct A *a;
int x;
{
  int k;
  k=GetIndex(a,x);
  if(k<a->n)
    return GetAt(a,k+1);   /*��Ԫ��x�����Ա��в����ڣ��򷵻����Ա��һ��Ԫ��*/
  else
    return NULL;
}

/*bool Insert(a,I,x)*/       /*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
int Insert(a,I,x)            /*��Ԫ��x���뵽���Ա�ĵ�I��Ԫ�ص�λ�ã����Ա��ȼ�1*/
struct A *a;
int I;
int x;
{
/*�ձ�Ĵ������ڱ�ͷ��һ��Ԫ��*/
/*�ǿձ�Ĵ������ڱ��л����һ��Ԫ�صĺ���*/
  if((I>=1)&&(I<=a->n+1)&&(a->n<MAX_LEN))
    {
      int k;
      for(k=a->n;k>=I;k--)              /*���Ƶ�k��Ԫ�أ�a->list[k-1]*/
        {
            a->list[k]=a->list[k-1];    /*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
        }
      a->list[I-1]=x;
      a->n++;
      return 1; /*����ɹ�*/
    }
  else
    return 0;   /*����ʧ��*/
}


/*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
/*ɾ�����Ա��е�I��Ԫ�أ����Ա��ȼ�1*/
int Delete(a,I) /*bool Delete(a,I)*/
struct A *a;
int I;
{
  int k;
  if((I>=1)&&(I<=a->n))
    {
      for(k=I+1;k<=a->n;k++)              /*ǰ�Ƶ�k��Ԫ�أ�a->list[k-1]*/
        {
            a->list[k-2]=a->list[k-1];    /*Ԫ���±���Ԫ�ظ�������Ӧ��Ԫ���±�=Ԫ�ظ���-1*/
        }
      a->n--;
      return 1;     /*ɾ���ɹ�*/
    }
  else
    return 0;       /*ɾ��ʧ��*/
}
