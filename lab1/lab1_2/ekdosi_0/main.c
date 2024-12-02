#include <stdio.h>
int getchoice(void );

int getchar(void);

int getsize(void);

int printsquare(int size);

int printromvos(int size);

int printriangle(int size);

int printpyramid(int size);

int main (void)
{
    int choice,size ;
    while(1)
    {
        if ((choice = getchoice())!= -1)
        {
            switch (choice)
            {
            case 0 :
                printsquare(size);
                break;
            case 1:
                printromvos(size);
                break;
            case 2:
                printriangle(size);
                break;
            case 3:
                printpyramid(size);
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

int getchar(void)
{
    printf("getchar\n");
    return 0;
}

int getsize(void)
{
    printf("getsize\n");
    return 0;
}

int printsquare(int size)
{
    printf("printsquare\n");
    return 0;
}

int printromvos(int size)
{
    printf("printromvos\n");
    return 0;
}

int printriangle (int size)
{
    printf("printriangle\n");
    return 0;
}

int printpyramid(int size)
{
    printf("prinpyramid\n");
    return 0;
}
