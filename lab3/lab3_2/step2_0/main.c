#include <stdio.h>
#include <string.h>

int getchoice(void);
void insert_text(void);
void insert_vocab(void);
void correct_text(void);
void save_text(void);
void calculate_stat(void);
void exit_prog(void);


int main ()
{
    int choice;
    while(1)
    {
        choice=getchoice();
        if ((choice)!=6)
        {
            getchoice();
        }
        else
            break;
    }
    return 0;
}

int getchoice(void)
{
    int choice;
    printf(" 1.Insert text\n 2.Insert vocabulary\n 3.Correct text\n 4.Save text\n 5.Calculate text-statistics\n 6.Exit program\n");
    scanf("%d", &choice);
    if (choice!=6)
    {
        switch(choice)
        {
        case 1:
            insert_text();
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
            calculate_stat();
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

void insert_text(void)
{
    printf("insert_text\n");
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

void calculate_stat(void)
{
    printf("calculate_stat\n");
}

void exit_prog(void)
{
    printf("exit_prog\n");
}
