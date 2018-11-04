#include <iostream>
using std::cout;
using std::endl;

//A is sorted array
int A[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133,
	155, 162, 176, 188, 199, 200, 210, 222};

static int binary_search_rec(int A[], int key, size_t low, size_t high);

/* Linear Search */
int linear_search(int A[], int key, int len) {
	int i=0;

	while ((A[i] != key) && (i<=len))
		i++;

	return i;
}

int binary_search_iterative(int A[], int key, int len) {
	int low = 0;
	int high = len - 1;
	int mid;

	while (low <= high) {
		mid = low + ((high - low) / 2);

		if (A[mid] == key)
			return mid;

		if (key < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

/* Helper fucntion for binary_search_recursive */
static int
binary_search_rec(int A[], int key, size_t low, size_t high) {
	int mid;

	if (low > high)
		return -1;

	mid = low + ((high - low) / 2);
	if (A[mid] == key)
		return mid;

	if (key < A[mid])
		return binary_search_rec(A, key, low, mid -1);
	else 
		return binary_search_rec(A, key, mid + 1, high);
}

/* Recursive Binary Search */
int binary_search_recursive(int A[], int key, int len) {
	return binary_search_rec(A, key, 0, len -1);
}

int main(int argc, char *argv[])
{
	int index=0;
	int key = atoi(argv[1]);
	int size = sizeof(A) / sizeof(int);
	
	index = binary_search_recursive(A, key, size);
	//printf("Key=%d is at i=%d\n", key, index);
	cout << "Key: "<< key << " found at: "<< index << endl;

	return 1;
}