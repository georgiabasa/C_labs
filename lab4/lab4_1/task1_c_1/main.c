#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 10

typedef struct text_t
{
    char ** t;
    int words;
} Text_t;

Text_t readText(void);

int main(void)
{
    Text_t mytext;
    int i;
    mytext = readText();
    for (i=0; i<mytext.words; i++)
        printf("%s\n", mytext.t[i]);
    return 0;
}

Text_t readText(void)
{
    Text_t my_text;
    char **mytext = NULL;
    char *word;
    int words = 0;
    while (scanf("%s", word= (char *)malloc(CHARS*sizeof(char))),
            strcmp(word,"TELOS"))
    {
        words ++;
        mytext = realloc(mytext, (words)*sizeof(char *));
        mytext[words-1] = word;
    }
    my_text.words=words;
    my_text.t=mytext;
    free(word);

    return my_text;
}
