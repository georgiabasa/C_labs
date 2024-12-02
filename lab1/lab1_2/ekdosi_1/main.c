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
    printf("printsquare\n");
    return 0;
}

int printromvos(int size, char character)
{
    printf("printromvos\n");
    return 0;
}

int printriangle (int size, char character)
{
    printf("printriangle\n");
    return 0;
}

int printpyramid(int size, char character)
{
    printf("prinpyramid\n");
    return 0;
}
