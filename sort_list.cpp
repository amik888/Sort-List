#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

void insertion_sort(std::vector <int> &num) {
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) //iterate over vector
	{
		key = num[j]; //key is value at current index (j)
		cout << key;
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--)
			//iterate over indexes before j
		{ // larger values move right

			//if value at current index is less than one of the indexes (i) before it,
			//
			if (key < num[i]) {
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
}


void insertion_sort_list(list <int> &num) {
	long long unsigned int i, j;
	int key;
	list<int>::iterator current = num.begin();
	list<int>::iterator previous = num.begin();
	bool insertionNeeded = false;


	for (j = 1; j < num.size(); j++)//iterate over vector
	{
		++current;
		key = *(current); //replace key = num[j],key is value at current iterator
		insertionNeeded = false;
    //cout << *current;

		for (i = j - 1; i >= 0; i--)
		{ // larger values move right
    previous = current;
    --previous;
    cout << *previous;
			if (*current < *previous)
				//if *current is less than previous, then move value at previous one ahead
				//and put
			{
				*(previous) = *previous;
				insertionNeeded = true;
			}
			else
			{
				break;
			}
		}
		if (insertionNeeded)
			*(++previous) = key;    //Put key into its proper location
	}
}




vector<int> random_vector(size_t size){
	vector<int> v1;
	for (long long unsigned int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}

list<int> random_list(size_t size)
{
	list<int> l1;
	for (long long unsigned int i = 0; i < size; i++)
	{
		l1.push_back(rand() % size);
	}
	return l1;
}

vector<int> sorted_vector(size_t size){
	vector<int> v1;
	for (long long unsigned int i = 0; i < size; i++)
		v1.push_back(i);
	return v1;
}

vector<int> reversed_vector(size_t size){
	vector<int> v1;
	for (int i = size-1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}

int main()
{
	vector<int> v1 = random_vector(4);
	for(auto ele : v1)
	{
		cout << ele << endl;
	}
	cout << endl;
	insertion_sort(v1);
	for(auto ele : v1)
	{
		cout << ele << endl;
	}
	cout << endl;


	list<int> l1 = random_list(4);
	for(auto ele : l1)
	{
		cout << ele << endl;
	}
	cout << endl;

	insertion_sort_list(l1);
	for(auto ele : l1)
	{
		cout << ele << endl;
	}


	return 0;
}
