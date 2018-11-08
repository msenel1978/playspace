#include <iostream>
#include <vector>
#include <list>
using namespace std;
using std::cout;
using std::endl;
using std::vector;
using std::list;

int binary_search(vector<int>& arr, int start, int end, int key) {
	int mid;

	if (start > end)
		return -1;

	mid = start + (end - start) / 2;

	if (arr[mid] == key)
		return mid;

	if (arr[start] < arr[mid] && key < arr[mid] && key >= arr[start])
		return binary_search(arr, start, mid-1, key);
	else if (arr[mid] < arr[end] && key > arr[mid] && key <= arr[end])
		return binary_search(arr, mid+1, end, key);
	else if (arr[start] > arr[mid])
		return binary_search(arr, start, mid-1, key);
	else if (arr[end] < arr[mid])
		return binary_search(arr, mid+1, end, key);

	return -1;
}

int binary_search_rotated(vector<int>& arr, int key) {
	return binary_search(arr, 0, arr.size()-1, key);
}

int main(int argc, char *argv[])
{
	vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
	int key = atoi(argv[1]);
	
	cout<<"Key: "<< key << " found at: "<< binary_search_rotated(v1, key)<<endl;

	return 0;

}
