#include <stdio.h>
#include <stdlib.h>

typedef int (*CallBack)(int, int);

typedef struct gate
{
    CallBack f;
    struct gate * in1 ;
    struct gate * in2 ;
} Gate;

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

int eval(Gate *x)
{
    int a, b;
    if (x->in1 != NULL)
        a = eval(x->in1);
    if (x->in2 != NULL)
        b = eval(x->in2);
    if (x->in1==NULL && x->in2 == NULL)
        return (x->f)(0,0);
    else
        return (x->f)(a,b);
}

void getoutput_1(Gate *x_eval, Gate *x_gate)
{
    int y;
    y=eval(x_eval);
    if(y==0)
    {
        x_gate->in1=creategate(get_0);
    }
    if(y==1)
    {
        x_gate->in1=creategate(get_1);
    }
}

void getoutput_2(Gate *x_eval, Gate *x_gate)
{
    int y;
    y=eval(x_eval);
    if(y==0)
    {
        x_gate->in2=creategate(get_0);
    }
    if(y==1)
    {
        x_gate->in2=creategate(get_1);
    }
}

int main( )
{
    Gate * a_ptr, * b_ptr, * c_ptr, *d_ptr, *e1_ptr, *e_ptr, *z1_ptr, *z2_ptr, *z3_ptr, *z4_ptr, *z5_ptr, *z_ptr, *g_ptr;
    a_ptr = creategate(mynor);
    printf("Insert inputs for NOR gate:\n");
    a_ptr->in1 = creategate(getinput);
    a_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(a_ptr));
    b_ptr = creategate(myand);
    printf("Insert inputs for AND gate:\n");
    b_ptr->in1 = creategate(getinput);
    b_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(b_ptr));
    c_ptr = creategate(myor);
    printf("Insert inputs for OR_1 gate:\n");
    c_ptr->in1 = creategate(getinput);
    c_ptr->in2 = creategate(getinput);
    printf("-----\n", eval(c_ptr));
    d_ptr = creategate(myor);
    printf("Insert inputs for OR_2 gate:\n");
    d_ptr->in1 = creategate(getinput);
    d_ptr->in2 = creategate(getinput);
    printf("-----\n\n\nTHA ME PERASETE STIN C? (type 'YES' to get the final output)\n", eval(d_ptr));

    e1_ptr=creategate(mynand);
    getoutput_1(a_ptr, e1_ptr);
    getoutput_2(b_ptr, e1_ptr);
    e_ptr=creategate(mynand);
    getoutput_1(e1_ptr, e_ptr);
    getoutput_2(c_ptr, e_ptr);
  /*  printf("output NAND: %d\n", eval(e_ptr)); */


    if(eval(a_ptr)==1 && eval(b_ptr)==1 && eval(d_ptr)==1)
    {
        z1_ptr=creategate(myor);
        getoutput_1(b_ptr, z1_ptr);
        getoutput_2(a_ptr, z1_ptr);
        z2_ptr=creategate(myor);
        getoutput_1(a_ptr, z2_ptr);
        getoutput_2(d_ptr, z2_ptr);
        z_ptr=creategate(myor);
        getoutput_1(z1_ptr, z_ptr);
        getoutput_2(z2_ptr, z_ptr);
    }
    else
    {
        z1_ptr=creategate(myand);
        getoutput_1(b_ptr, z1_ptr);
        getoutput_2(a_ptr, z1_ptr);
        z2_ptr=creategate(myand);
        getoutput_1(a_ptr, z2_ptr);
        getoutput_2(d_ptr, z2_ptr);
        z3_ptr=creategate(myand);
        getoutput_1(b_ptr, z3_ptr);
        getoutput_2(d_ptr, z3_ptr);
        z4_ptr=creategate(myand);
        getoutput_1(z1_ptr, z4_ptr);
        getoutput_2(z2_ptr, z4_ptr);
        z5_ptr=creategate(myand);
        getoutput_1(z2_ptr, z5_ptr);
        getoutput_2(z3_ptr, z5_ptr);
        z_ptr=creategate(myand);
        getoutput_1(z4_ptr, z_ptr);
        getoutput_2(z5_ptr, z_ptr);
    }
  /*  printf("output xor: %d\n", eval(z_ptr)); */

    g_ptr=creategate(myor);
    getoutput_1(e_ptr, g_ptr);
    getoutput_2(z_ptr, g_ptr);
    printf("final output: %d\n", eval(g_ptr));

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
