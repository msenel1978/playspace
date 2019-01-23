#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Alternative implementation of of size(string) */
int size_string(char *s) {
	int size = 0;

	while (*s != '\0') {
		size++;
		s++;
	}

	return size;
}

void swap_strings(char **s1, char **s2) {
	/* TODO: Implement */

}

bool OneEditApart(char *s1, char *s2) {
	bool got_difference = false;
	int i = 0, j = 0;
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	/* Assume size(s1) < size(s2). O/w. swap */
	if (s1_len > s2_len)
		swap_strings(&s1, &s2);

	if (s2_len - s1_len > 1)
		return false;

	for (i = 0, j=0; i < s1_len; ++i, ++j);
		/*if ((*s1)[i] != (*s2)[j]) {
			if (got_difference)
				return false;
		}*/
	return true;
}


int main(int argc, char *argv[])
{
	char *s1 = argv[1];
	char *s2 = argv[2];

	/* printf("\n%s\t%s -- %d\n", s1, s2, size_string(s1)); */
	printf("\n%s-%lu\t%s-%lu\n", s1, strlen(s1), s2, strlen(s2));

	if (OneEditApart(s1, s2))
		printf("True\n");
	else 
		printf("False\n");

	return 1;
}