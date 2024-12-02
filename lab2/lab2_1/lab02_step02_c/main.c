 #include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5
int load(double x[N][M]) ;

int print(double x[N][M]) ;

double computeprod(double x[N][M]);

void printprod (double prod);

void dataT(double x[N][M]);

int main( )
{
    double data[N][M];
    double prod ;
    load(data);
    print(data);
    prod = computeprod(data);
    printprod(prod);
    dataT(data);
    return 0;
}

int print(double x[N][M])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf(" %g ", x[i][j]);
        printf("\n");
    }
    return 0;
}
int load(double x[N][M])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<M; j++)
            x[i][j] = ((double) (i+j+N) / N );
    }
    return 0;
}

double computeprod(double x[N][M])
{
    int i,j;
    double prod=1;
    for (i=0; i<N; i++)
    {
        for (j=0; j<M; j++)
            prod*=x[i][j];

    }
    return prod;
}

void printprod (double prod)
{
    printf("\n%g\n",prod);
    printf("\n");
}

void dataT(double x[N][M])
{
    double dataT[M][N];
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<M; j++)
            dataT[j][i]=x[i][j];
    }
    for (i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
            printf(" %g ", dataT[i][j]);
        printf("\n");
    }
}
