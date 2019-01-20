#include <stdio.h>
#include <stdlib.h>


#define MAX_POPULATION 10

typedef struct person {
	int birth_yr;
	int	death_yr;
} person_t;

static int find_max_yr(int cum_arry[], int init_yr, int len);
static int find_max_birth_yr(person_t population[]);
static int find_min_birth_yr(person_t population[]);
static int cumulative_arry(int delta_arry[], int len);
static int init_arry(int delta_arry[], int len);
static int print_arry_content(int arry[], int len);

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

static int init_arry(int delta_arry[], int len){
	int i = 0;

	for (i = 0; i < len; i++)
		delta_arry[i] = 0;

	return 1;
}

static int cumulative_arry(int delta_arry[], int len){
	int i;

	for (i = 1; i < len; i++)
		delta_arry[i] += delta_arry[i-1];

	return 1;

}

static int print_arry_content(int arry[], int len) {
	int i = 0;

	printf("\n Array: ");
	for (i = 0; i < len; i++)
		printf("%d\t",arry[i]);
	printf("\n");

	return 1;
}

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
		if (min_yr > population[i].birth_yr)
			min_yr = population[i].birth_yr;
	}

	return min_yr;
}

static int find_max_yr(int cum_arry[], int init_yr, int len) {
	int i = 0, max_yr = 0;

	for (i = 0; i < len; i++) {
		if (cum_arry[max_yr] < cum_arry[i])
			max_yr = i;
	}

	return (max_yr + init_yr);
}

static int find_max_pop_yr(person_t population[]) {
	int max_birth_yr = find_max_birth_yr(population);
	int min_birth_yr = find_min_birth_yr(population);
	int time_span = max_birth_yr - min_birth_yr + 1;
	int population_arry[time_span];
	int i;

	if (init_arry(population_arry, time_span) != 1)
		return -1;

	//print_arry_content(population_arry, time_span);

	for (i = 0; i < MAX_POPULATION; i++) {
		population_arry[population[i].birth_yr - min_birth_yr]++;
		if (population[i].death_yr <= max_birth_yr)
			population_arry[population[i].death_yr - min_birth_yr]--;
	}

	print_arry_content(population_arry, time_span);

	if (cumulative_arry(population_arry, time_span) != 1) {
		printf("\n Error!\n");
		return -1;
	}

	print_arry_content(population_arry, time_span);

	return find_max_yr(population_arry, min_birth_yr, time_span);
}

int main()
{	int max_population_yr = find_max_pop_yr(people);
	
	/* printf("First person:\t%d\t%d\n", people[0].birth_yr, people[0].death_yr); */
	printf("\n\nYear w. max population:%d\n\n", max_population_yr);

	return 1;
}