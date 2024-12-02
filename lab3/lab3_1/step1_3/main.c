#include <stdio.h>
#include <stdlib.h>
#define W 5

int main()
{
    char words[W][9 + 1] ;
    char test[9 + 1];
    char endword[9 +1] = "end";
    char Reversed[W][9 + 1];
    int i,j=0;
    while (scanf("%9s", test), strcmp(test,endword))
    {
        strcpy(words[i++], test);
        printf("%s\n", test);
        if((j++)>(W-1))
            break;
    }
    for (i=0; i<W; i++)
    {

        if((j++)>=(W-1))
            break;
    }

    printf("\n");

    for(i=0; i<W; i++)
    {
        int g;
        g=strlen(words[i]);
        for(j=0; j<=g; j++)
        {
            Reversed[W-i][j]=words[i][j];
            printf("%d %s\n, tolower('0x%x') gives 0x%x\n", i, Reversed[i], tolower(Reversed[i]));
        }
    }
    return 0;
}
