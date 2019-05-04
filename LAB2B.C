#include "stdio.h"
#include "conio.h"
void swap(int *p1,int *p2)
{
    int p;
    p=*p1;
    *p1=*p2;
    *p2=p;
}
main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b>a)
        swap(&a,&b);
    if(c>a)
        swap(&a,&c);
    if(c>b)
        swap(&b,&c);
    printf("%d %d %d ",a,b,c);
    getch();
}

