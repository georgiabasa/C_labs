#include <stdio.h>
#include <stdlib.h>

int myand(int a, int b);
int myor(int a, int b);
int myxor(int a, int b);
int mynand(int a, int b);
int mynor(int a, int b);
typedef int (*CallBack)(int, int);
int report(CallBack f);
int g;

int main( )
{
    CallBack myfunctions[] = {myand, myor, myxor, mynand, mynor};
    for(g=0; g<= (sizeof(myfunctions)/ sizeof(CallBack)); g++)
    {
        report(myfunctions[g]);
    }
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

int myxor(int a, int b)
{
    return (((!a)&&b) || (a&&(!b)));
}

int mynand(int a, int b)
{
    return !(a&&b);
}

int mynor(int a, int b)
{
    return !(a||b);
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
    printf("\n");
    return 0;
}
