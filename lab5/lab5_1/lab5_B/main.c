#include <stdio.h>
#include <stdlib.h>

int myand(int a, int b);
int myor(int a, int b);
typedef int (*CallBack)(int, int);
int report(CallBack f);


int main( )
{
    CallBack f ;
    f = myand;
    report(f);
    f = myor;
    report(f);
    return 0;
}

int myand (int a, int b)
{
    return a * b;
}

int myor (int a, int b)
{
    return a + b>0;
}

int report(CallBack f)
{
    int i,j;
    for(j=0; j<=1; j++)
    {
        for(i=0; i<=1; i++)
        {
            printf("%d %d %d\n", j, i, f(j, i));
        }
    }
    printf("\n\n");
    return 0;
}
