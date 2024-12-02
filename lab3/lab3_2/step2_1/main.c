#include <stdio.h>
#include <string.h>
#define N 150

int getchoice(char data[N][50+1]);

void insert_text(char data[N][50+1]);

void insert_vocab(void);

void correct_text(void);

void save_text(void);

void calculate_stat(char data[N][50+1]);



int main ()
{
    int choice;
    char data[N][50+1];
    while(1)
    {
        choice=getchoice(data);
        if ((choice)!=6)
        {
            getchoice(data);
        }
        else
            break;
    }
    return 0;
}


int getchoice(char data[N][50+1])
{
    int choice;
    printf(" 1.Insert text\n 2.Insert vocabulary\n 3.Correct text\n 4.Save text\n 5.Calculate text-statistics\n 6.Exit program\n");
    scanf("%d", &choice);
    if (choice!=6)
    {
        switch(choice)
        {
        case 1:
            insert_text(data);
            break;
        case 2:
            insert_vocab();
            break;
        case 3:
            correct_text();
            break;
        case 4:
            save_text();
            break;
        case 5:
            calculate_stat(data);
            break;
        default:
            printf("Your number is not a choice.\n");
        }
    }
    else if(choice==6)
    {
        exit(0);
    }
    return choice;
}


void insert_text(char data[N][50+1])
{
    char words[N][50 + 1];
    char test[50 + 1];
    char endword[50 +1] = "T*E*L*O*S";
    int i,j=0;
    memset(words, '\0', sizeof(words));
    printf("write 'T*E*L*O*S' when you finish insertion.\n");
    while (scanf("%50s", test), strcmp(test,endword))
    {
        strcpy(words[i++], test);
        if((j++)>(N-1))
            break;
    }
    for (i=0; i<N; i++)
    {
        if((j++)<(N-1))
        {
            printf("\n");
            for(i=0; i<j-1; i++)
                printf("%d %s\n", i+1, words[i]);
        }
        else if((j++)>=N)
        {
            for(i=0; i<N; i++)
                printf("%d %s\n", i+1, words[i]);
        }
        break;
    }
    printf("\n");
    for(i=0; i<N; i++)
        strcpy(data[i], words[i]);
}


void insert_vocab(void)
{
    printf("insert_vocab\n");
}


void correct_text(void)
{
    printf("correct_text\n");
}


void save_text(void)
{
    printf("save_text\n");
}


void calculate_stat(char data[N][50+1])
{
    int i, j=0, count_w=0, chars=0, space=0, count_dw=0;
    int ist[50+1];
    for(i=0; i<(50+1); i++)
        ist[i]=0;
    for(i=0; i<N; i++)
    {
        if((data[i][0])!='\0')
        {
            count_w++;
            count_dw++;
            chars+=(int) strlen(data[i]);
            for(j=0; j<i; j++)
            {
                if((strcmp(data[i], data[j]))==0 && i!=j)
                {
                    count_dw--;
                    break;
                }
            }
            ist[(int) (strlen(data[i]))]++;
        }
    }
    printf("\nSatistics:\n");
    printf("words= %d\n", count_w);
    printf("chars= %d\n", chars);
    printf("chars+spaces= %d\n", count_w-1+chars);
    printf("different words= %d\n", count_dw);
    for(i=0; i<(50+1); i++)
        printf("%d words have %d chars\n", ist[i], i);
    printf("\n");
}
