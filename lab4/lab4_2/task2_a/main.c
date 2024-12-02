#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charact
{
    char ch;
    int occurs;
    struct charact *next;
};

typedef struct charact Char;
typedef Char * ListofChar;
typedef Char * CharNode_ptr;
void letters(char name[50], ListofChar * lst_ptr);
void report(ListofChar chars);
Char * createnode(char ch);

int main(void)
{
    char name[50];
    ListofChar chars = NULL;
    scanf("%49s", name);
    letters(name, &chars);
    report(chars);
    return 0;
}

Char * createnode(char ch)
{
    CharNode_ptr newnode_ptr ;
    newnode_ptr = malloc(sizeof (Char));
    newnode_ptr -> ch = ch;
    newnode_ptr -> occurs = 0;
    newnode_ptr -> next = NULL;
    return newnode_ptr;
}

void letters(char name[50], ListofChar * lst_ptr)
{
    ListofChar *chars_ptr= lst_ptr;
    ListofChar temp_ptr;
    for(lst_ptr=chars_ptr; *name; ++name)
    {
        for(lst_ptr=chars_ptr; (temp_ptr= *lst_ptr); lst_ptr= &temp_ptr->next)
        {
            if(*name==temp_ptr->ch)
            {
                (temp_ptr->occurs)++;
            }
            else if(temp_ptr->ch=='\0')
            {
                temp_ptr->ch=*name;
                (temp_ptr->occurs)++;
            }
        }
        if (!temp_ptr) *lst_ptr=createnode(*name);
    }
    return;
}

void report(ListofChar chars)
{
    ListofChar temp= chars;
    if(temp==NULL)
    {
        printf("Empty list!\n");
        return;
    }
    for(temp=chars; temp!=NULL; temp=temp->next)
    {
        printf("%c: %d\n", temp->ch, temp->occurs);
    }
    return;
}
