#include <stdio.h>
#define N 10

int load(double x[N]) ;

int print(double x[N]) ;

double computeprod(double x[N]);

void printprod (double prod);

double computeprodsum(double x[N],double *sum);

void printprodsum(double sum);


int main( )
{
    double data[N];
    double sum,prod ;
    load(data);
    print(data);
    prod = computeprod(data);
    printprod(prod);
    computeprodsum(data,&sum);
    printprodsum(sum);
    return 0;
}

int print(double x[N])
{
    int i;
    for (i=0; i<N; i++)
    {
        printf(" %g ", x[i]) ;
    }
    return 0;
}
int load(double x[N])
{
    int i;
    for (i=0; i<N; i++)
    {
        x[i] = ((double) i+N) / N ;
    }
    return 0;
}

double computeprodsum(double x[N],double *sum)
{   int i;
    *sum=0;
    for (i=0;i<N;i++)
        {(*sum)+=x[i];
        }
        return *sum;

}

void printprodsum (double sum)
{
    printf("\n%g",sum);
}

double computeprod(double x[N])
{   int i;
    double prod=1.0;
    for (i=0;i<N;i++)
        prod*=x[i];
    return prod;
}

void printprod (double prod)
{
    printf("\n%g",prod);
}
