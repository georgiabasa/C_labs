#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20

int print(double x[N][M]);

void stable_temp(double x[N][M]);

void trans_temp(double x[N][M]);


int main()
{
    double data[N][M];
    stable_temp(data);
    print(data);
    printf("\n");
    trans_temp(data);
    print(data);
    return 0;
}


int print(double x[N][M])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf(" %.2f ", x[i][j]);
    }
    return 0;
}

void stable_temp(double x[N][M])
{
    int i,j;
    i=0;
    j=0;
    for(j=0; j<M; j++)
    {
        x[0][j]=1.5;
        x[9][j]=3.5;
    }
    for(i=0; i<N; i++)
    {
        x[i][0]=2.5;
        x[i][19]=4.5;
    }
    for(i=0; i<=0; i++)
    {
        for(j=0; j<=0; j++)
            x[i][j]=(1.5+2.5)/2;
        for(j=19; j<M; j++)
            x[i][j]=(1.5+4.5)/2;
    }
    for(i=9; i<N; i++)
    {
        for(j=0; j<=0; j++)
            x[i][j]=(3.5+2.5)/2;
        for(j=19; j<M; j++)
            x[i][j]=(4.5+3.5)/2;
    }
    for(i=1; i<(N-1); i++)
    {
        for(j=1; j<(M-1); j++)
            x[i][j]=3.00;
    }
}

void trans_temp(double x[N][M])
{
    int i,j;
    i=0;
    j=0;
    for(i=1; i<(N-1); i++)
    {
        for(j=1; j<(M-1); j++)
            x[i][j] =0.1 * (x[i-1][j-1]+x[i-1][j]+x[i-1][j+1]+x[i][j-1]+2*x[i][j]+x[i][j+1]+x[i+1][j-1]+x[i+1][j]+x[i+1][j+1]);
    }
}
