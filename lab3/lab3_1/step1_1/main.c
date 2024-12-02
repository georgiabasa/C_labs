#include <stdio.h>
#include <stdlib.h>
#define W 5

int main()
{
    char words[W][9 + 1] ;
    char test[9 + 1];
    char endword[9 +1] = "end";
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
        if((j++)<(W-1))
        {
            printf("%d %s\n", i, words[i]);
        }
        else if((j++)>=(W-1))
            break;
    }
    return 0;
}
