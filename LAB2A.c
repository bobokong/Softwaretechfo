#include "stdio.h"
#include "conio.h"
main()
{
	int i,j;
	for(i=1;i<=317;i++)
		for(j=1;j<=317;j++)
		if(i*i==(i+j)*(i+j)-168&&i*i-100>0)
		printf("%d ",i*i-100);
}