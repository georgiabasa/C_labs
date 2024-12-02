#include <stdio.h>
#include <stdlib.h>

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

int myandlst(DataList mylist);
int myorlst(DataList mylist);
int myxorlst(DataList mylist);
int mynandlst(DataList mylist);
int mynorlst(DataList mylist);

int report(BoolFunc mygate);

int main( )
{
    int i,j=0;
    DataList mylist=NULL;
    BoolFunc myfunctions[] = {{"AND gate", myandlst},{"OR gate", myorlst}, {"XOR gate",myxorlst}, {"NAND gate", mynandlst}, {"NOR gate", mynorlst}};
    for(i=0; i<= (sizeof(myfunctions)/ sizeof(BoolFunc)); i++)
    {
        report(myfunctions[j]);
        j++;
    }
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
    if(mylist==NULL) return 0;
    return mylist->value * mylist->next->value;
}

int myorlst (DataList mylist)
{
    if(mylist==NULL) return 0;
    return mylist->value + mylist->next->value>0;
}

int myxorlst (DataList mylist)
{
    if(mylist==NULL) return 0;
    return (mylist->value + mylist->next->value) * !(mylist->value * mylist->next->value);
}

int mynandlst (DataList mylist)
{
    if(mylist==NULL) return 0;
    return !(mylist->value * mylist->next->value);
}

int mynorlst (DataList mylist)
{
    if(mylist==NULL) return 0;
    return !(mylist->value + mylist->next->value);
}

int report(BoolFunc mygate)
{
    int i,j;
    DataList mylist1;
    DataList mylist2;

    mylist1=createData(i);
    mylist2=createData(j);
    appendData(&(mylist1->next), mylist2);
    printf("%s\n",mygate.gate);

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            mylist1->value=i;
            mylist2->value=j;
            printf("%d %d %d\n", mylist1->value, mylist2->value, mygate.mygate(mylist1));
        }
    }
    printf("\n");
    return 0;
}
