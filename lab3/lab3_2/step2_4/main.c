#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26418
#define V 70000

int getchoice(char data[N][50+1], char words[V][50+1]);

void insert_text(char data[N][50+1]);

void insert_vocab(char words[V][50+1]);

int correct_text(char data[N][50+1], char words[V][50+1]);

void save_text(char data[N][50+1]);

void calculate_stat(char data[N][50+1]);

int compare(char data[N][50+1], char words[V][50+1]);

void replace_w(char data[N][50+1]);

void add_to_vocab(char data[N][50+1], char words[V][50+1]);


int main ()
{
    int choice;
    char data[N][50+1];
    char words[V][50+1];
    while(1)
    {
        choice=getchoice(data,words);
        if ((choice)!=6)
        {
            getchoice(data, words);
        }
        else
            break;
    }
    return 0;
}


int getchoice(char data[N][50+1], char words[V][50+1])
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
            insert_vocab(words);
            break;
        case 3:
            correct_text(data,words);
            break;
        case 4:
            save_text(data);
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
    FILE *alice;
    alice=fopen("AlicesAdventuresInWonderland.txt","r");

    if(alice==NULL)
    {
        printf("ERROR! opening file");
        exit(0);
    }
    for(i=0; i<N; i++)
    {
        fscanf(alice, "%50s", &data[i]);
        printf("%d %s\n", i+1, data[i]);
    }
    fclose(alice);
}


void insert_vocab(char words[V][50+1])
{
    int i;
    FILE *vocabulary;
    vocabulary=fopen("englishWords.txt", "r");
    if(vocabulary==NULL)
    {
        printf("ERROR! opening vocabulary");
        exit(0);
    }
    for(i=0; i<V; i++)
    {
        fscanf(vocabulary, "%50s", &words[i]);
    }
    fclose(vocabulary);
}


int correct_text(char data[N][50+1], char words[V][50+1])
{
    int i,j,choice;
    compare(data,words);
    while(compare(data,words)==0)
    {
        printf(" 1.Replace word\n 2.Add to vocabulary\n 3.Ignore and Continue\n 4.Exit\n");
        scanf("%d", &choice);
        if ((choice)!=4)
        {
            switch(choice)
            {
            case 1:
                replace_w(data);
                break;
            case 2:
                add_to_vocab(data, words);
                break;
            case 3:
                break;
            default:
                printf("Your number is not a choice.\n");
                correct_text(data,words);
            }
        }
        else if(choice==4)
        {
            break;
        }
    }
    return choice;
}


void save_text(char data[N][50+1])
{
    int i;
    FILE *fp;
    char filename[50+1];
    printf("Insert file-name: ");
    scanf("%s", filename);
    fp=fopen(filename, "w");
    if (fp==NULL)
    {
        printf("Error! creating this file");
        exit(0);
    }
    fprintf(fp, "%s",data);
    fclose(fp);
    printf("Your text has successfully been saved in file: %s \n", filename);
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
    fprintf(filename, " words= %d\n chars= %d\n chars+spaces= %d\n different words= %d\n \nIstogram:\n", count_w, chars, count_w-1+chars, count_dw);
    for(i=0; i<(50+1); i++)
        fprintf(filename, "%d words have %d chars\n", ist[i], i);
    fclose(filename);
}

int compare(char data[N][50+1], char words[V][50+1])
{
    int i,j;
    insert_text(data);
    insert_vocab(words);
    for(i=0; i<N; i++)
    {
        if((data[i][0])!='\0')
        {
            for(j=0; j<V; j++)
            {
                if(strcmp(words[j], data[i])!=0)
                {
                    printf("This word doesn't exist in vocabulary: %s\n", data[i]);
                    return 0;
                }
                else if(strcmp(words[j], data[i])==0)
                {
                    return 1;
                    break;
                }
            }
        }
    }
}

void replace_w(char data[N][50+1])
{
    int i;
    char replaced[N][50+1];
    FILE *alice;
    printf("Insert the word to replace '%s' with:", data[i]);
    scanf("%50s", replaced);
    memmove(data[i]+strlen(data[i]), data[i], strlen(data[i]));
    puts(replaced[i]);
}

void add_to_vocab(char data[N][50+1], char words[V][50+1])
{
    int i;
    char *copyvoc[V][50+1];
    FILE *vocabulary;
    vocabulary=fopen("englishWords.txt", "w+");
    fwrite(words[i] , strlen(words[i]) , sizeof(words) , vocabulary);
    fprintf(vocabulary, "\n");
    fwrite(data, 1, sizeof(data), vocabulary);
    fclose(vocabulary);
}
