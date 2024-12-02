#include <stdio.h>
#include <string.h>

struct charact
{
    char ch;
    int sec;
};

typedef struct charact Char;
void letters(char name[50], Char chars[50]);
void report(char name[50], Char chars[50]);

int main(void)
{
    char name[50];
    Char chars[50];
    scanf("%49s", name);
    letters(name, chars);
    report(name, chars);
    return 0;
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

void report(char name[50], Char t[50])
{
    int i;
    for (i=strlen(name)-1; i>=0; i--)
    {
        printf("%c: %d\n", t[i].ch, t[i].sec);
    }
    return;
}
