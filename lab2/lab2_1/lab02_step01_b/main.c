#include <stdio.h>
#define N 10
#define M 5
int main( )
{
    int i,j;
    double data[N][M];
    double prod=1.0 ;
    for (i=0; i<N; i++)
    {for (j=0;j<M;j++)
        data[i][j] = ((double) (i+j+N) / N );
    }
    for (i=0; i<N; i++)
    {for (j=0;j<M;j++)
        printf(" %g ", data[i][j]);
    printf("\n");
    }
    for (i=0;i<N;i++)
    {for (j=0;j<M;j++)
        prod*=data[i][j];
    }
    printf("\n%g\n", prod);
    return 0;
}
