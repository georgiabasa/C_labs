#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_vector.h>

void seed_gsl_mt_rng();
void seed_rand_rng();
void draws();
void print_frequency_tables();

static gsl_rng *r;
static gsl_vector *v_rand_frequency;
static gsl_vector *v_mt_frequency;
static unsigned long int nof_draws=1000000000;
static int range=45;

int main()
{
    seed_gsl_mt_rng();
    seed_rand_rng();
    v_rand_frequency=gsl_vector_alloc(range+1);
    v_mt_frequency=gsl_vector_alloc(range+1);
    draws();
    print_frequency_tables();
    gsl_vector_free(v_rand_frequency);
    gsl_vector_free(v_mt_frequency);
    gsl_rng_free(r);
    return 0;
}

void seed_gsl_mt_rng()
{
    r=gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL));
}

void seed_rand_rng()
{
    srand(time(NULL));
}

void draws()
{   long int j;
    int rand_num, mt_num;
    gsl_vector_set_all(v_mt_frequency,0);
    gsl_vector_set_all(v_rand_frequency,0);
    for (j=1; j<=nof_draws; j++)
    {   rand_num=(rand()% range)+1;
        mt_num=(int) ((gsl_rng_uniform_int(r,range)+1));
        gsl_vector_set(v_rand_frequency,rand_num,(gsl_vector_get(v_rand_frequency,rand_num))+1);
        gsl_vector_set(v_mt_frequency,mt_num,(gsl_vector_get(v_rand_frequency,mt_num))+1);
    }
}

void print_frequency_tables()
{
    int j;
    printf("FREQUENCY TABLES\n");
    printf("Number\tRand Rng Perc Frequences\tMersenne Twister Rng Perc Frequences\n");
    for (j=0; j<range; j++)
    {   printf("%d\t\t",j+1);
        printf("%.4f\t\t\t\t", (gsl_vector_get(v_rand_frequency,j+1)/nof_draws)*100);
        printf("%.4f\n", (gsl_vector_get(v_mt_frequency, j+1)/nof_draws)*100);
    }
}
