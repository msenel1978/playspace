#include <iostream>
using namespace std;
using std::cout;
using std::endl;

int binary_search_rotated(vector<int>& arr, int key) {
  // TODO: Write - Your - Code
  return -1;
}

nt main(int argc, char *argv[])
{
	vector<int> v1 = {6, 7, 1, 2, 3, 4, 5};
	int key = atoi(argv[1]);
	
	cout<<"Key: "<< key << " found at: "<< binary_search_rotated(v1, key)<<endl;

	return 0;

}