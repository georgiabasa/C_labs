#include <stdio.h>
#include <stdlib.h>

typedef int (*CallBack)(int, int);

typedef struct MyGates{
    char gate[10];
    CallBack mygate;
}BoolFunc;

int myand(int a, int b);
int myor(int a, int b);
int myxor(int a, int b);
int mynand(int a, int b);
int mynor(int a, int b);

int report(BoolFunc f);
int g;

int main( )
{
    BoolFunc myfunctions[] = {{"AND gate", myand},{"OR gate", myor}, {"XOR gate",myxor},{"NAND gate", mynand},{"NOR gate", mynor}};
    for(g=0; g<= (sizeof(myfunctions)/ sizeof(BoolFunc)); g++)
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

int report(BoolFunc f)
{
    int i,j;
    printf("%s\n",f.gate);
    for(j=0; j<=1; j++)
    {
        for(i=0; i<=1; i++)
        {
            printf("%d %d %d\n", j, i, f.mygate(j, i));
        }
    }
    printf("\n");
    return 0;
}
