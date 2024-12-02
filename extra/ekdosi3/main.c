#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_vector.h>
#include <math.h>


void seed_gsl_mt_rng();
void seed_rand_rng();
void draws();
void forecast();

static gsl_rng *r;
static gsl_vector *v_rand_results;
static gsl_vector *v_mt_results;
static unsigned long int nof_draws=pow(2,31)-1;
static int range=45;

int main()
{
    seed_gsl_mt_rng();
    seed_rand_rng();
    v_rand_results=gsl_vector_alloc(101);
    v_mt_results=gsl_vector_alloc(101);
    draws();
    forecast();
    gsl_vector_free(v_rand_results);
    gsl_vector_free(v_mt_results);
    gsl_rng_free(r);
    return 0;
}

void seed_gsl_mt_rng(void)
{
    r=gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL));
}

void seed_rand_rng(void)
{
    srand(time(NULL));
}

void draws(void)
{
    unsigned long int j;
    int rand_num, mt_num;
    gsl_vector_set_all(v_mt_results,0);
    gsl_vector_set_all(v_rand_results,0);
    for (j=0; j<=nof_draws; j++)
    {
        mt_num=(int) ((gsl_rng_uniform_int(r,range)+1));
        rand_num=(rand()% range)+1;
        if (j<100)
        {
            gsl_vector_set(v_mt_results,j+1,mt_num);
            gsl_vector_set(v_rand_results,j+1,rand_num);
        }
    }
}

void forecast(void)
{
    int j;
    int rand_num,mt_num;
    printf("PREDICTING RAND\n");
    printf("Rand Predict vs Draw\t\t\t GSL Mt Predict vs Draw\n");
    for (j=0; j<100; j++)
    {
        printf("%g\tvs.\t", (gsl_vector_get(v_rand_results,j+1)));
        rand_num=(rand()% range)+1;
        printf("%d\t\t\t  ",rand_num);
        mt_num=(int) ((gsl_rng_uniform_int(r,range)+1));
        printf("%g  \tvs.\t", (gsl_vector_get(v_mt_results,j+1)));
        printf("%d\n",mt_num);


    }
}
