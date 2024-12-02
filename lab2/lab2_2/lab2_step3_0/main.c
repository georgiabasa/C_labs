#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20

int print(double x[N][M]);

void stable_temp(double x[N][M]);

void trans_temp(double x[N][M]);

void max_number(double x[N][M]);

void min_number(double x[N][M]);

void scale_temp(double max_num,double min_num, double temperature[N],double x[N][M]);

void find_scale(double temp,double temperature[N]);

void freq(int x[N][M], int fr[N]);

void istogramma(int x[N]);

void current(double x[N][M]);

void next(double x[N][M], double t0[N][M]);

void diafora(double t0[N][M], double t1[N][M]);



int main()
{
    double data[N][M], max_num, min_num, temperature[N], temp;
    int fr[N], x[N], g[N][M];
    stable_temp(data);
    print(data);
    printf("\n");
    trans_temp(data);
    max_number(data);
    min_number(data);
    scale_temp(max_num, min_num, temperature, data);
    find_scale(temp, temperature);
    freq(g, fr);
    istogramma(x);
    current(data);
    next(data,data);
    diafora(data, data);
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
            x[i][j]=3;
    }
}

void trans_temp(double x[N][M])
{
    printf("trans_temp\n");
}

void max_number(double x[N][M])
{
    printf("max_number\n");
}

void min_number(double x[N][M])
{
    printf("min_number\n");
}

void scale_temp(double max_num,double min_num, double temperature[N],double x[N][M])
{
    printf("scale_temp\n");
}

void find_scale(double temp,double temperature[N])
{
    printf("find_scale\n");
}

void freq(int x[N][M], int fr[N])
{
    printf("freq\n");
}

void istogramma(int x[N])
{
    printf("istogramma\n");
}

void current(double x[N][M])
{
    printf("current\n");
}

void next(double x[N][M], double t0[N][M])
{
    printf("next\n");
}

void diafora(double t0[N][M], double t1[N][M])
{
    printf("diafora\n");
}
