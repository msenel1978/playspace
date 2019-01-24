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

void swap_strings(char **s1_ptr, char **s2_ptr) {
	char *temp = *s1_ptr;

	*s1_ptr = *s2_ptr;
	*s2_ptr = temp;
}

bool OneEditApart(char *s1, char *s2) {
	bool got_difference = false;
	int i = 0, j = 0;
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	/* Assume size(s1) < size(s2). O/w. swap */
	if (s1_len > s2_len) {
		printf("Before swap: %s - %s\n", s1, s2);
		swap_strings(&s1, &s2);
		printf("After swap: %s - %s\n", s1, s2);
	}

	if (s2_len - s1_len > 1)
		return false;

	for (i = 0, j=0; i < s1_len; ++i, ++j)
		if (s1[i] != s2[j]) {
			if (got_difference)
				return false;

			/* Saw one-edit */
			got_difference = true;

			/* s2 longer, maybe an insertion */
			/* so skip a character in s2 */
			if (s2_len > s1_len)
				--i;

		}
	/* Either seen only one difference */
	/* or (non-dfiference and s2 is one char longer */ 
	return (got_difference || (s1_len != s2_len));
}


int main(int argc, char *argv[])
{
	char *s1 = argv[1];
	char *s2 = argv[2];

	/* printf("\n%s\t%s -- %d\n", s1, s2, size_string(s1)); */
	printf("\nMy strings:\t%s-%lu\t%s-%lu\n", s1, strlen(s1), s2, strlen(s2));

	if (OneEditApart(s1, s2))
		printf("True\n");
	else 
		printf("False\n");

	return 1;
}