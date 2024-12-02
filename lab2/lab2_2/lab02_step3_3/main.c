#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20

int print(double x[N][M]);

void stable_temp(double x[N][M]);

void trans_temp(double x[N][M]);

double max_number(double x[N][M]);

double min_number(double[N][M]);

void scale_temp(double max_num,double min_num, double temperature[N],double x[N][M], int k[N][M]);

int find_scale(double temp,double temperature[N]);

void freq(int x[N][M], int fr[N]);

void istogramma(int x[N]);

void current(double x[N][M]);

void next(double x[N][M], double t0[N][M]);

double diafora(double t0[N][M], double t1[N][M]);



int main()
{
    int i,time;
    double data[N][M];
    int k[N][M], fr[N];
    double temperature[N];
    double max_num,min_num;
    double t0[N][M], t1[N][M];
    stable_temp(data);
    max_num=max_number(data);
    min_num=min_number(data);
    scanf("%d",&time);
    for (i=0; i<time; i++)
        trans_temp(data);
    scale_temp(max_num,min_num,temperature,data, k);
    printf("\n");
    freq(k,fr);
    istogramma(fr);
    current(t1);
    next(t0, t1);
    printf("\n");
    diafora(t0, t1);
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

double max_number(double x[N][M])
{
    int i,j;
    double max_num=0;
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if (x[i][j] > max_num)
            {
                max_num=x[i][j];
            }

        }

    }
    return max_num;
}

double min_number(double x[N][M])
{
    int i,j;
    double min_num=500;
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if (x[i][j] < min_num)
            {
                min_num=x[i][j];
            }

        }

    }
    return min_num;
}

void scale_temp(double max_num,double min_num, double temperature[N],double x[N][M], int k[N][M])
{
    double mps;
    int i,j;
    mps= (max_num-min_num)/10;
    for (i=0; i<10; i++)
    {
        temperature[i]=min_num+(i+1)*mps;
    }
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            k[i][j]=find_scale(x[i][j], temperature);
        }
    }
    for (i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            printf(" %d", k[i][j]);
        }
        printf("\n");
    }
}


int find_scale(double temp, double temperature[N])
{
    int i;
    for (i=0; i<N; i++)
    {
        if (temp<=temperature[i])
        {
            return i;
        }
    }
}
void freq(int x[N][M], int fr[N])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        fr[i]=0;
    }
    for(i=0; i<N; i++)
    {
        for (j=0; j<M; j++)
            fr[x[i][j]]++ ;
    }
    for (i=0; i<N; i++)
        printf("%d\n", fr[i]) ;
}

void istogramma(int x[N])
{
    {
        int i,j;
        printf("\n");
        for(i=0; i<N; i++)
        {
            printf("%2d:",i);
            for(j=0; j<x[i]; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}

void current(double x[N][M])
{
    int i,j;
    double t1[N][M];
    stable_temp(x);
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            t1[i][j]=x[N][M];
    }
}

void next(double x[N][M], double t1[N][M])
{
    int i,j;
    double t0[N][M];
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            t0[i][j]=t1[i][j];
            trans_temp(t1);
        }
    }

}

double diafora(double t0[N][M], double t1[N][M])
{
    int i,j;
    double dt[N][M];
    double sum=0;
    stable_temp(t1);
    next(t0, t1);
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            dt[i][j]=t1[i][j]-t0[i][j];
            for(i=0; i<N; i++)
            {
                for(j=0; j<M; j++)
                {
                    if(dt[i][j]<0)
                    {
                        dt[i][j]=-dt[i][j];
                    }
                    sum=sum+dt[i][j];
                    stable_temp(t0);
                }
                if(sum<1)
                    continue;
                else if(sum>=1)
                {
                    print(dt);
                }
            }
        }
    }
}
