#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct data
{
    int value;
    struct data * next;
} Data;

typedef Data * DataList;
typedef int (*CallBack)(DataList);

typedef struct MyGates
{
    char gate[10];
    CallBack mygate;
} BoolFunc;

Data * createData(int value);
void appendData(DataList *lstptr, Data *newptr);

int myandlst(DataList mylist);
int myorlst(DataList mylist);
int myxorlst(DataList mylist);
int mynandlst(DataList mylist);
int mynorlst(DataList mylist);

int report(BoolFunc mygate, int x);

int main( )
{
    int i,j=0,x;
    BoolFunc myfunctions[] = {{"AND gate", myandlst},{"OR gate", myorlst}, {"XOR gate",myxorlst}, {"NAND gate", mynandlst}, {"NOR gate", mynorlst}};
    printf("Insert number of inputs: \n");
    scanf("%d", &x);
    for(i=0; i<= (sizeof(myfunctions)/ sizeof(BoolFunc)); i++)
        report(myfunctions[i],x);
    return 0;
}

Data * createData(int value)
{
    Data * dataptr;
    dataptr = malloc(sizeof (Data));
    dataptr->value = value;
    dataptr->next = NULL;
    return dataptr;
}
void appendData(DataList *lstptr, Data *newptr)
{
    if (*lstptr==NULL)
    {
        *lstptr = newptr;
        return;
    }
    appendData( &((*lstptr)->next), newptr);
    return;
}

int myandlst (DataList mylist)
{
    unsigned short output;

    if(mylist->next==NULL) return mylist->value;
    output = mylist->value && mylist->next->value;
    mylist->next->value = output;
    return myandlst(mylist->next);
}

int myorlst (DataList mylist)
{
    unsigned short output;

    if(mylist->next==NULL) return mylist->value;
    output = mylist->value || mylist->next->value;
    mylist->next->value = output;
    return myorlst(mylist->next);
}

int myxorlst (DataList mylist)
{
    unsigned short output;

    if(mylist->next==NULL) return mylist->value;
    output = (mylist->value || mylist->next->value) && !(mylist->value && mylist->next->value);
    mylist->next->value = output;
    return myxorlst(mylist->next);
}

int mynandlst (DataList mylist)
{
    unsigned short output;

    if(mylist->next==NULL) return !(mylist->value);
    output = (mylist->value && mylist->next->value);
    mylist->next->value = output;
    return mynandlst(mylist->next);
}

int mynorlst (DataList mylist)
{
    unsigned short output;

    if(mylist->next==NULL) return !(mylist->value);
    output =(mylist->value || mylist->next->value);
    mylist->next->value = output;
    return mynorlst(mylist->next);
}

int report(BoolFunc mygate, int x)
{
    int i;
    DataList mylist=NULL;
    DataList l_ptr;
    Data * n_ptr;
    unsigned short mps, n;

    printf("%s\n",mygate.gate);
    for(n=0; n<pow(2,x); n++)
    {
        free(mylist);
        mylist=NULL;
        mps=n;
        for(i=0; i<x; i++)
        {
            n_ptr=createData(mps&1);
            appendData(&mylist, n_ptr);
            mps=mps>>1;
        }
        l_ptr=mylist;
        while(l_ptr!=NULL)
        {
            printf("%d ", l_ptr->value);
            l_ptr=l_ptr->next;
        }
        printf("%d\n", mygate.mygate(mylist));
    }
    printf("\n");

    return 0;
}
