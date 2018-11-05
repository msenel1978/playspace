
#include <iostream>
#include <vector>
#include <list>
using namespace std;
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

	result.push_back(v[window.front()]);
	cout << v[window.front()] <<", ";

	for (i = window_size; i < v.size(); ++i) {
		/* remove all numbers that are smaller than current number
    	from the tail of list */

    	while (!window.empty() && v[i] >= v[window.back()])
    		window.pop_back();

    	//remove first number if it doesn't fall in the window anymore
    	if(!window.empty() && window.front() <= i - window_size)
    		window.pop_front();

    	window.push_back(i);
    	result.push_back(v[window.front()]);
    	cout << v[window.front()] << ", ";
	}
	cout << endl;
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

	x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::reverse(x.begin(), x.end());
  
	for(i=0; i<x.size(); ++i)
		cout << x[i] << ' ';
	cout<<endl;

  	find_max_sliding_window(x, 3);

	x = {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67};
	std::reverse(x.begin(), x.end());

	for(int i=0; i<x.size(); ++i)
		cout << x[i] << ' ';
	cout<<endl;

	find_max_sliding_window(x, 3);

	return 0;

}