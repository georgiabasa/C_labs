#include <stdio.h>
#include <stdlib.h>

int getchoice(void );

char getcharacter (void);

int getsize(void);

int printsquare(int size, char character);

int printromvos(int size, char character);

int printriangle(int size, char character);

int printpyramid(int size, char character);

void printInsCh(int g, char character);

void sameforInsNo(int g, char character);

void plusoneInsNo(int g, char character);

void printspace(int g);

int main (void)
{
    char character;
    int choice, size;
    while(1)
    {
        if ((choice = getchoice())!= -1)
        {
            size = getsize() ;
            character = getcharacter ();
            switch (choice)
            {
            case 0 :
                printsquare(size, character);
                break;
            case 1:
                printromvos(size, character);
                break;
            case 2:
                printriangle(size,character);
                break;
            case 3:
                printpyramid(size,character);
                break;
            default:
                printf("There is no shape for this number.\n");
                break;
            }
        }
        else
            break;
    }
    return 0;
}
int getchoice(void)
{
    int choice;
    printf("Insert shape-number:\n 0-square\n 1-romvos\n 2-triangle\n 3-pyramid\n ");
    scanf("%d",&choice);
    return choice;
}

char getcharacter(void)
{
    char ch;
    printf("Insert character: ");
    scanf("\n%c", &ch);
    return ch;
}

int getsize(void)
{
    int size;
    printf("Insert row-number: ");
    scanf("%d",&size);
    return size;
}

int printsquare(int size, char character)
{
    int i, j, side;
    side=size;
    for(i=1; i<=1; i++)
        printInsCh(side, character);
    printf("\n");
    for(i=2; i<=(side-1); i++)
    {
        printInsCh(1, character);
        for(j=2; j<=(side-1); j++)
        {
            if(j==i || j==(side-(i-1)))
            {
                printf("%c", character);
            }
            else
            {
                printf(" ");
            }
        }
        sameforInsNo(side, character);
        printf("\n");
    }
    for(i=side; i<=side; i++)
    {
        printInsCh(side, character);
        printf("\n");
    }
    return 0;
}

int printromvos(int size, char character)
{
    int totalRowNo, r, c;
    totalRowNo=size;
    if((totalRowNo%2)!=0)
    {
        for(r=1; r<=1; r++)
        {
            printspace(((totalRowNo/2)+1-r));
            sameforInsNo(((totalRowNo/2)+2-r), character);
            printf("\n");
        }
        for(r=2; r<=((totalRowNo/2)+1); r++)
        {
            printspace(((totalRowNo/2)+1-r));
            sameforInsNo(((totalRowNo/2)+1-r), character);
            for(c=((totalRowNo/2)+1-r); c<((totalRowNo/2)-1); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)-1), character);
            for(c=((totalRowNo/2)); c<=((totalRowNo/2)-3+r); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)-2+r), character);
            printf("\n");
        }
        for(r=((totalRowNo/2)+2); r<=(totalRowNo-1); r++)
        {
            printspace(((totalRowNo/2)-totalRowNo+r));
            sameforInsNo(((totalRowNo/2)+1-totalRowNo+r), character);
            for(c=((totalRowNo/2)+1-totalRowNo+r); c<=((totalRowNo/2)-1); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)-1), character);
            for(c=((totalRowNo/2)-1); c<((totalRowNo/2)-2+totalRowNo-r); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)-1+totalRowNo-r), character);
            printf("\n");
        }
        for(r=totalRowNo; r<=totalRowNo; r++)
        {
            printspace(((totalRowNo/2)-totalRowNo+r));
            sameforInsNo(((totalRowNo/2)+2-totalRowNo+r), character);
            printf("\n");
        }
    }
    if((totalRowNo%2)==0)
    {
        for(r=1; r<=1; r++)
        {
            printspace(((totalRowNo/2)-r));
            plusoneInsNo(((totalRowNo/2)+2-r), character);
            printf("\n");
        }
        for(r=2; r<=(totalRowNo/2); r++)
        {
            printspace(((totalRowNo/2)-r));
            sameforInsNo(((totalRowNo/2)-r), character);
            for(c=((totalRowNo/2)-r); c<=((totalRowNo/2)-3); c++)
                printf(" ");
            plusoneInsNo(((totalRowNo/2)-1), character);
            for(c=(totalRowNo/2); c<=((totalRowNo/2)-3+r); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)-3+r), character);
            printf("\n");
        }
        for(r=((totalRowNo/2)+1); r<=(totalRowNo-1); r++)
        {
            printspace(((totalRowNo/2)-1-totalRowNo+r));
            sameforInsNo(((totalRowNo/2)-totalRowNo+r), character);
            for(c=((totalRowNo/2)+1-totalRowNo+r); c<=((totalRowNo/2)-1); c++)
                printf(" ");
            plusoneInsNo((totalRowNo/2), character);
            for(c=((totalRowNo/2)+2); c<((totalRowNo/2)+1+totalRowNo-r); c++)
                printf(" ");
            sameforInsNo(((totalRowNo/2)+1+totalRowNo-r), character);
            printf("\n");
        }
        for(r=totalRowNo; r<=totalRowNo; r++)
        {
            printspace(((totalRowNo/2)-1-totalRowNo+r));
            plusoneInsNo(((totalRowNo/2)-totalRowNo+r), character);
            printf("\n");
        }
    }
    return 0;
}


int printriangle (int size, char character)
{
    int totalRowNo, row, column;
    totalRowNo=size;

    for(row=1; row<=2; row++){
        printInsCh(row, character);
        printf("\n");
    }
    for(row=3; row<=(totalRowNo-1); row++)
    {
        printf("%c", character);
        for(column=2; column<=(row-1); column++)
            printf(" ");
        printf("%c", character);
        printf("\n");
    }
    for(row=totalRowNo; row<=totalRowNo; row++)
        printInsCh(row, character);
    printf("\n");
    return 0;
}

int printpyramid(int size, char character)
{
    int totalRowNo, row, space,symbol;
    totalRowNo=size;

    for(row=1; row<=1; row++)
    {
        printspace((totalRowNo-row));
        printInsCh(((2*row)-1), character);
        printf("\n");
    }
    for(row=2; row<=(totalRowNo-1); row++)
    {
        printspace((totalRowNo-row));
        printf("%c", character);
        printspace(((2*row)-3));
        printf("%c", character);
        printf("\n");
    }
    for(row=totalRowNo; row<=totalRowNo; row++)
    {
        printInsCh(((2*row)-1), character);
        printf("\n");
    }
    return 0;
}

void printInsCh(int g, char character)
{
    int i;
    for(i=1; i<=g; i++)
        printf("%c", character);
}

void sameforInsNo(int g, char character)
{
    int i;
    for(i=g; i<=g; i++)
        printf("%c", character);
}

void plusoneInsNo(int g, char character)
{
    int i;
    for(i=g; i<=(g+1); i++)
        printf("%c", character);
}

void printspace(int g)
{
    int i;
    for(i=1; i<=g; i++)
        printf(" ");
}
