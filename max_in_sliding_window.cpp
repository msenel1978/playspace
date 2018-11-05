
#include <iostream>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;

vector<int> find_max_sliding_window(vector<int>& v, int window_size) {
	//TODO: Write - Your - Code
	vector<int> result;
	list<int> window;
	int i;

	cout << "max = ";
	if (window_size > v.size()) {
		cout << endl;
		return result;
	}

	//find out max for first window
	for (i=0; i< window_size; ++i) {
		while(!window.empty() && v[i] >= v[window.back()]) {
			window.pop_back();
		}

		window.push_back(i);
	}




	return result;
}

int main(int argc, char *argv[])
{
	vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;

  	for(i=0; i<x.size(); ++i)
  		cout << x[i] << ' ';
  
	cout<<endl;
	find_max_sliding_window(x, 3);


	return 1;
}