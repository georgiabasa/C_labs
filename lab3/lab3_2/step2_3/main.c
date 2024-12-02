#include <stdio.h>
#include <string.h>
#define N 5000

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
    int i;
    char words[N][50+1];
    FILE *alice;
    alice=fopen("AlicesAdventuresInWonderland.txt","r");

    if(alice==NULL)
       {
           printf("ERROR! opening file");
           exit(0);
       }
    for(i=0; i<N; i++)
    {
        fscanf(alice, "%50s", &words[i]);
        printf("%d %s\n", i+1, words[i]);
    }
    fclose(alice);
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
    FILE *filename;
    char name[100];
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
    printf("\nStatistics:\n");
    printf("words= %d\n", count_w);
    printf("chars= %d\n", chars);
    printf("chars+spaces= %d\n", count_w-1+chars);
    printf("different words= %d\n", count_dw);
    printf("\nIstogram:\n");
    for(i=0; i<(50+1); i++)
        printf("%d words have %d chars\n", ist[i], i);
    printf("\n");
    printf("Give file-name for statistics:\n");
    scanf(" %s", name);
    filename=fopen(name, "w");
    fprintf(filename, "\nSatistics:\n words= %d\n chars= %d\n chars+spaces= %d\n different words= %d\n \nIstogram:\n", count_w, chars, count_w-1+chars, count_dw);
    for(i=0; i<(50+1); i++)
        fprintf(filename, "%d words have %d chars\n", ist[i], i);
    fclose(filename);
}
