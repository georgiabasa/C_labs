#include <stdio.h>
#include <stdlib.h>

typedef int (*CallBack)(int, int);

typedef struct gate
{
    CallBack f;
    char gate[10];
    struct gate * in1 ;
    struct gate * in2 ;
} Gate;

typedef struct MyGates
{
    char gate[10];
    CallBack mygate;
} BoolFunc;

int myand(int a, int b);
int myor(int a, int b);
int myxor(int a, int b);
int mynand(int a, int b);
int mynor(int a, int b);

int getinput()
{
    int x;
    scanf("%d", &x);
    return x;
}

int get_0()
{
    return 0;
}

int get_1()
{
    return 1;
}

Gate * creategate(CallBack f)
{
    Gate * temp ;
    temp = malloc(sizeof (Gate));
    temp->f = f;
    temp->in1 = NULL;
    temp->in2 = NULL;
    return temp;
}

char functions(CallBack f)
{
    char and, or, xor, nand, nor;
    if (f=myand)
        return and;
    if (f=myor)
        return or;
    if (f=myxor)
        return xor;
    if (f=mynand)
        return nand;
    if (f=mynor)
        return nor;

}

int eval(Gate *x, char name, CallBack f)
{
    int a, b;
    name=functions(f);
    if (x->in1 != NULL)
        a = eval(x->in1, functions(f), f);
    if (x->in2 != NULL)
        b = eval(x->in2, functions(f), f);
    if (x->in1==NULL && x->in2 == NULL)
        return (x->f)(0,0);
    else
        return (x->f)(a,b);
}

void getoutput(Gate *x_eval, Gate *x_gate, CallBack f)
{
    int y;
    y=eval(x_eval, functions(f), f);
    if(y==0)
    {
        x_gate->in1=creategate(get_0);
    }
    if(y==1)
    {
        x_gate->in1=creategate(get_1);
    }
}

int main( )
{
    CallBack f;
    Gate * a_ptr, * b_ptr, * c_ptr, *d_ptr, *e1_ptr, *e_ptr, *z1_ptr, *z2_ptr, *z3_ptr, *z4_ptr, *z5_ptr, *z_ptr, *g_ptr;
    f= functions;
    a_ptr = creategate(mynor);
    printf("Insert inputs for NOR gate:\n");
    a_ptr->in1 = creategate(getinput);
    a_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(a_ptr, functions(f), f));
    b_ptr = creategate(myand);
    printf("Insert inputs for AND gate:\n");
    b_ptr->in1 = creategate(getinput);
    b_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(b_ptr, functions(f), f));
    c_ptr = creategate(myor);
    printf("Insert inputs for OR_1 gate:\n");
    c_ptr->in1 = creategate(getinput);
    c_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(c_ptr, functions(f), f));
    d_ptr = creategate(myor);
    printf("Insert inputs for OR_2 gate:\n");
    d_ptr->in1 = creategate(getinput);
    d_ptr->in2 = creategate(getinput);
    printf("-----\n\n\nTHA ME PERASETE STIN C? (type 'YES' to get the final output)\n", eval(c_ptr, functions(f), f));

    e1_ptr=creategate(mynand);
    getoutput(a_ptr, e1_ptr, f);
    getoutput(b_ptr, e1_ptr, f);
    e_ptr=creategate(mynand);
    getoutput(e1_ptr, e_ptr, f);
    getoutput(c_ptr, e_ptr, f);
  /*  printf("output NAND: %d\n", eval(e_ptr)); */


    if(eval(a_ptr, functions(f), f)==1 && eval(b_ptr, functions(f), f)==1 && eval(d_ptr, functions(f), f)==1)
    {
        z1_ptr=creategate(myor);
        getoutput(b_ptr, z1_ptr, f);
        getoutput(a_ptr, z1_ptr, f);
        z2_ptr=creategate(myor);
        getoutput(a_ptr, z2_ptr, f);
        getoutput(d_ptr, z2_ptr, f);
        z_ptr=creategate(myor);
        getoutput(z1_ptr, z_ptr, f);
        getoutput(z2_ptr, z_ptr, f);
    }
    else
    {
        z1_ptr=creategate(myand);
        getoutput(b_ptr, z1_ptr, f);
        getoutput(a_ptr, z1_ptr, f);
        z2_ptr=creategate(myand);
        getoutput(a_ptr, z2_ptr, f);
        getoutput(d_ptr, z2_ptr, f);
        z3_ptr=creategate(myand);
        getoutput(b_ptr, z3_ptr, f);
        getoutput(d_ptr, z3_ptr, f);
        z4_ptr=creategate(myand);
        getoutput(z1_ptr, z4_ptr, f);
        getoutput(z2_ptr, z4_ptr, f);
        z5_ptr=creategate(myand);
        getoutput(z2_ptr, z5_ptr, f);
        getoutput(z3_ptr, z5_ptr, f);
        z_ptr=creategate(myand);
        getoutput(z4_ptr, z_ptr, f);
        getoutput(z5_ptr, z_ptr, f);
    }
  /*  printf("output xor: %d\n", eval(z_ptr)); */

    g_ptr=creategate(myor);
    getoutput(e_ptr, g_ptr, f);
    getoutput(z_ptr, g_ptr, f);
    printf("final output: %d\n", eval(g_ptr, functions(f), f));

    return 0;
}

int myand (int a, int b)
{
    return a && b;
}

int myor (int a, int b)
{
    return a || b>0;
}

int myxor(int a, int b)
{
    return (((!a)&&b) || (a&&(!b)));
}

int mynand(int a, int b)
{
    return !(a && b);
}

int mynor(int a, int b)
{
    return !(a || b);
}
