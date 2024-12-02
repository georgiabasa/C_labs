/*Μπασαγιάννη Γεωργία 1084016*/

#include <stdio.h>
#include <stdlib.h>

void printfivechars(void);

void printnchars(int n, char ch);

void squarefive(void);

void squaren(int n);

int main()
{
   /* 1.1 */
   printfivechars();
   printf("\n");

   /* 1.2*/
   printnchars(8,'=');
   printf("\n");
   printnchars(22,'!');

   /* 1.3 */
   printf("\n");
   int x;
   scanf("%d",&x);
   printnchars(x,'#');

   /*1.4 */
   printf("\n");
   squarefive();

   /*1.5*/
   squaren(3);

   return 0;
}


void printfivechars(void)
{   int i;
   for (i=0;i<5;i++)
   {   printf("=");
   }
}

void printnchars(int n, char ch)
{
   int i;
   for (i=0;i<n;i++)
   {
       printf("%c",ch);
   }
}

void squarefive(void)
{
   int i;
   for (i=0;i<5;i++)
   {
       printfivechars();
       printf("\n");
   }
}

void squaren(int n)
{
   int i;
   for (i=0;i<n;i++)
   {
       printnchars(n,'!');
       printf("\n");
   }
}
