#include "stdio.h"
#include<string.h>
#include "conio.h"
#define N 5
struct student
{
   char num[6];
   char sex[8];
   char name[8];
   int score[4];
}stu[N];

void input()
{
   int i,j;
   for(i=0;i<N;i++)
   {
       	printf("\n please input %d of %d\n",i+1,N);
	printf("num: ");
 	scanf("%s",&stu[i].num);
 	printf("sex(man/woman): ");
 	scanf("%s",&stu[i].sex);
	if(strcmp(stu[i].sex,"man")!=0&&strcmp(stu[i].sex,"woman")!=0) {
	printf("wrong! Please enter man or woman \n");
	scanf("%s",&stu[i].sex);
	}
 	printf("name: ");
	scanf("%s",&stu[i].name);
	for(j=0;j<3;j++)
       {
           printf("score %d.",j+1);
	   scanf("%d",&stu[i].score[j]);
	}
       printf("\n");
    }
}

void print()
{
    int i,j;
    printf("\nNo.   sex    Name     Sco1    Sco2    Sco3\n");
    for(i=0;i<N;i++)
    {
       printf("%-6s%-7s%-11s",stu[i].num,stu[i].sex,stu[i].name);
       for(j=0;j<3;j++)
       printf("%-8d",stu[i].score[j]);
       printf("\n");
    }
}
void Sex()
{
	int i ,sum1=0,sum2=0;
	for(i=0;i<N;i++) {
	if(strcmp(stu[i].sex,"man")==0)
		sum1=sum1+1;
	if(strcmp(stu[i].sex,"woman")==0)
		sum2=sum2+1;
	}
	printf("The number of man is %d",sum1);
	printf("The number of woman is %d",sum2);	
	
}
main()
{
    input();
    print();
	Sex();
    getch();
}
