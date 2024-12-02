#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 10
typedef struct text_t
{
    char ** t;
    int words;
} Text_t;

typedef struct charact
{
    char ch;
    int sec;
} Char;
void letters(char name[50], Char chars[50]);
void report(Char chars[50]);
void initialize(Char chars[50]);

Text_t readText(void);

int main()
{
    Text_t mytext;
    Char chars[50];
    int i;
    mytext = readText();
    for (i=0; i<mytext.words; i++)
    {
        printf("%s\n", mytext.t[i]);
        letters(mytext.t[i],chars);
        report(chars);
    }
    return 0;
}

Text_t readText(void)
{
    Text_t my_text;
    FILE * fp;
    char **mytext = NULL;
    char *word;
    int words = 0;
    char fname[50];
    fp = fopen("test3.txt", "r");

    while (fscanf(fp,"%s", word=(char *)malloc(CHARS*sizeof(char)))!=EOF)
    {
        words ++;
        mytext = realloc(mytext, (words)*sizeof(char *));
        mytext[words-1] = word;
    }
    my_text.words=words;
    my_text.t=mytext;
    free(word);
    fclose(fp);

    return my_text;
}

void letters(char name[50], Char chars[50])
{
    size_t i, j;
    memset(chars, 0, 50*sizeof(Char));
    for (i=0; i<strlen(name); i++)
    {
        for (j=0; j<50; j++)
        {
            if  (name[i]==chars[j].ch)
            {
                chars[j].sec+=(i-j);
            }

            else if (chars[j].ch=='\0')
            {
                chars[j].ch=name[i];
                chars[j].sec+=(i-j);
                break;
            }
        }
    }
    return;
}

void report(Char t[50])
{
    int i;
    for (i=0; i<50 && t[i].ch!='\0'; i++)
    {
        printf("%c: %d\n", t[i].ch, t[i].sec);
    }
    return;
}
