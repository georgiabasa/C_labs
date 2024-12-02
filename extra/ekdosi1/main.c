#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <gsl/gsl_rng.h>

void seed_gsl_mt_rng(void);
void seed_rand_rng(void);
void draws(unsigned long int draws, int range);
static gsl_rng *r;


int main()
{
    seed_gsl_mt_rng();
    seed_rand_rng();
    printf("PRNGs seeded successfully.Initiate trials.\n\n");
    draws(10,45);
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

void draws(unsigned long int draws, int range)
{
    int j;
    printf("Draw\tRand\tThe Mersenne Twister\n");
    for (j=1; j<=draws; j++)
    {
        printf("%d\t",j);
        printf("%d\t",(rand()% range)+1);
        printf("%d\n", (int) ((gsl_rng_uniform_int(r,range)+1)));
    }
}
