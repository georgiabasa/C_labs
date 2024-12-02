#include <stdio.h>
#include <string.h>
struct charact
{
    char ch;
    int sec;
};

typedef struct charact Char;
Char distance(char name[50]);
void report(Char temp);
int main(void)
{
    char name[50];
    Char first;
    scanf("%49s", name);
    first = distance(name);
    report(first);
    return 0;
}
Char distance(char name[50])
{
    int i;
    Char temp ;
    temp.ch=name[0];
    temp.sec=0;
    for (i=1; i<strlen(name); i++)
    {
        if (name[i]==name[0])
        {
            temp.sec+=i;
            break;
        }
    }
    return temp;
}
void report(Char t)
{
    printf("%c\n%d", t.ch, t.sec);
    return;
}
