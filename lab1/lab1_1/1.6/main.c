#include <stdio.h>
#include <stdlib.h>


int main()
{
    int g;
    scanf("%d",&g);
    printchars(g,'q');
    printchars2(g);
    printchars3(g);
    printchars2(g);
    printchars(g,'q');


}

void printchars2(int g){
    for(int i=0;i<=g;i++){
        if (i==0 || i==g-1){
            printf("%c",'a');
        }
        else {
            printf("%c",'-');
        }

}

void printchars3(int g){
    for(int i=0;i<=g;i++){
        if (i==0 || i==g-1){
            printf("%c",'a');
        }
        else{
            if (i==1 || i==g-2){
                printf("%c",'-');
            }
            else{
                printf("%c",'*');
            }
        }
    }
}
