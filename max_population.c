#include <stdio.h>
#include <stdlib.h>


#define MAX_POPULATION 10

typedef struct person {
	int birth_yr;
	int	death_yr;
} person_t;

static int find_max_birth_yr(person_t population[]);
static int find_min_birth_yr(person_t population[]);

/*
int birth_yr[10] = {2000, 1998, 1900, 1876, 1976, 1923, 1978, 1996, 2014, 1976};
int death_yt[10] = {2019, 2020, 1976, 1914, 2011, 1938, 2014, 2008, 2100, 2060};
*/

person_t people[MAX_POPULATION] = { {2000, 2019},
						{1998, 2020},
						{1900, 1976},
						{1876, 1914},
						{1976, 2011},
						{1923, 1938},
						{1978, 2014},
						{1996, 2008},
						{2014, 2100},
						{1976, 2060} };


static int find_max_birth_yr(person_t population[]) {
	int max_yr = population[0].birth_yr;
	int i;

	for (i = 1; i < MAX_POPULATION; i++) {
		if (max_yr < population[i].birth_yr)
			max_yr = population[i].birth_yr;
	}

	return max_yr;
}

static int find_min_birth_yr(person_t population[]) {
	int min_yr = population[0].birth_yr;
	int i;

	for (i = 1; i < MAX_POPULATION; i++) {
		if (max_yr > population[i].birth_yr)
			max_yr = population[i].birth_yr;
	}

	return max_yr;
}

int main()
{
	printf("First person:\t%d\t%d\n", people[0].birth_yr, people[0].death_yr);
	printf("Max Birthyear:%d\n", find_max_birth_yr(people));
	return 1;
}