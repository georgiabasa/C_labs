#include <stdio.h>
int getchoice(void );

char getcharacter (void);

int getsize(void);

int printsquare(int size, char character);

int printromvos(int size, char character);

int printriangle(int size, char character);

int printpyramid(int size, char character);

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
    for(i=1; i<=1; i++);
    {
        for(j=1; j<=side; j++)
            printf("%c", character);
        printf("\n");
    }
    for(i=2; i<=(side-1); i++)
    {
        for(j=1; j<=1; j++)
            printf("%c", character);
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
        for(j=side; j<=side; j++)
            printf("%c", character);
        printf("\n");
    }
    for(i=side; i<=side; i++)
    {
        for(j=1; j<=side; j++)
            printf("%c", character);
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
            for(c=1; c<=((totalRowNo/2)+1-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+2-r); c<=((totalRowNo/2)+2-r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=2; r<=((totalRowNo/2)+1); r++)
        {
            for(c=1; c<=((totalRowNo/2)+1-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+1-r); c<=((totalRowNo/2)+1-r); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)+1-r); c<((totalRowNo/2)-1); c++)
                printf(" ");
            for(c=((totalRowNo/2)-1); c<=((totalRowNo/2)-1); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)); c<=((totalRowNo/2)-3+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-2+r); c<=((totalRowNo/2)-2+r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=((totalRowNo/2)+2); r<=(totalRowNo-1); r++)
        {
            for(c=1; c<=((totalRowNo/2)-totalRowNo+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+1-totalRowNo+r); c<=((totalRowNo/2)+1-totalRowNo+r); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)+1-totalRowNo+r); c<=((totalRowNo/2)-1); c++)
                printf(" ");
            for(c=((totalRowNo/2)-1); c<=((totalRowNo/2)-1); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)-1); c<((totalRowNo/2)-2+totalRowNo-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-1+totalRowNo-r); c<=((totalRowNo/2)-1+totalRowNo-r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=totalRowNo; r<=totalRowNo; r++)
        {
            for(c=1; c<=((totalRowNo/2)-totalRowNo+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+2-totalRowNo+r); c<=((totalRowNo/2)+2-totalRowNo+r); c++)
                printf("%c", character);
            printf("\n");
        }
    }
    if((totalRowNo%2)==0)
    {
        for(r=1; r<=1; r++)
        {
            for(c=1; c<=((totalRowNo/2)-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+2-r); c<=((totalRowNo/2)+3-r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=2; r<=(totalRowNo/2); r++)
        {
            for(c=1; c<=((totalRowNo/2)-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-r); c<=((totalRowNo/2)-r); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)-r); c<=((totalRowNo/2)-3); c++)
                printf(" ");
            for(c=((totalRowNo/2)-1); c<=((totalRowNo/2)); c++)
                printf("%c", character);
            for(c=(totalRowNo/2); c<=((totalRowNo/2)-3+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-3+r); c<=((totalRowNo/2)-3+r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=((totalRowNo/2)+1); r<=(totalRowNo-1); r++)
        {
            for(c=1; c<=((totalRowNo/2)-1-totalRowNo+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-totalRowNo+r); c<=((totalRowNo/2)-totalRowNo+r); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)+1-totalRowNo+r); c<=((totalRowNo/2)-1); c++)
                printf(" ");
            for(c=(totalRowNo/2); c<=((totalRowNo/2)+1); c++)
                printf("%c", character);
            for(c=((totalRowNo/2)+2); c<((totalRowNo/2)+1+totalRowNo-r); c++)
                printf(" ");
            for(c=((totalRowNo/2)+1+totalRowNo-r); c<=((totalRowNo/2)+1+totalRowNo-r); c++)
                printf("%c", character);
            printf("\n");
        }
        for(r=totalRowNo; r<=totalRowNo; r++)
        {
            for(c=1; c<((totalRowNo/2)-totalRowNo+r); c++)
                printf(" ");
            for(c=((totalRowNo/2)-totalRowNo+r); c<=((totalRowNo/2)+1-totalRowNo+r); c++)
                printf("%c", character);
            printf("\n");
        }
    }
    return 0;
}


int printriangle (int size, char character)
{
    int totalRowNo, row, column;
    totalRowNo=size;

    for(row=1; row<=2; row++)
    {
        for(column=1; column<=row; column++)
            printf("%c", character);
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
    {
        for(column=1; column<=row; column++)
            printf("%c", character);
        printf("\n");
    }
    return 0;
}

int printpyramid(int size, char character)
{
    int totalRowNo, row, space,symbol;
    totalRowNo=size;

    for(row=1; row<=1; row++)
    {
        for(space=1; space<=(totalRowNo-row); space++)
            printf(" ");
        for(symbol=1; symbol<=((2*row)-1); symbol++)
            printf("%c", character);
        printf("\n");
    }
    for(row=2; row<=(totalRowNo-1); row++)
    {
        for(space=1; space<=(totalRowNo-row); space++)
            printf(" ");
        printf("%c", character);
        for(symbol=1; symbol<=((2*row)-3); symbol++)
            printf(" ");
        printf("%c", character);
        printf("\n");
    }
    for(row=totalRowNo; row<=totalRowNo; row++)
    {
        for(symbol=1; symbol<=((2*row)-1); symbol++)
            printf("%c", character);
        printf("\n");
    }
    return 0;
}
