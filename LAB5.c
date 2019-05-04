
#include<stdio.h>
#include<math.h>
#define max_n 6
#define max_m 8
main()
{
	int x,i,y,num_i,value[max_m],a[max_n];
	printf("Please enter an array(0<=a[i]<=max_m-1): \n");
	for(i=0;i<max_n;i++)
	{
		scanf("%d",&a[i]);
		value[i]=-1;
	}
	printf("which of the number(x) do you want to print:\n");
	scanf("%d",&num_i);
	printf("%d\n",a[num_i]);
	printf("please enter a number to compare:\n");
	scanf("%d",&x);
	for(i=0;i<max_n;i++)
	{
	if(a[i]==x)
	{
	printf("Exit,and the number of subscript is %d\n",i);
	value[x]=i;
	break;
	}
	else if(i==max_n-1)
	printf("Not exit!\n");
	}
	printf("Please enter y:\n");
	scanf("%d",&y);
	for(i=0;i<max_n;i++)
	{
	value[a[i]]=i;		
	}
	if(value[y]==-1)
	printf("Not exit!");
	else 
	printf("Exit,and the subscript is %d\n",value[y]);
}