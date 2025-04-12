///////////////////////////////////////////////////////////////////////////
// CountingSort.cpp                                                      //
// ver 1.0                                                               //
// Type:	source file                                              //
// Language:    C++                                                      //
// Platform:    Dell Alienware M14x, Win8                                //
// Author:      Yu Zhang, Syracuse University                            //
//              zyu.1106@gmail.com                                       //
//		yzhan39@syr.edu                                          //
// Description: http://www.yu-zhang.net/blog/2014/07/22/c-counting-sort///
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
using namespace std;

void drawLine()
{
	cout << endl << string(50, '-') << endl << endl;
}

void countingSort(int *a, int n, int max)
{
	int *counting = new int[max];
	int k = 0;
	for(int i = 0; i < max; i++)
		counting[i] = 0;
	for(int i = 0; i < n; i++)
		counting[a[i]]++;
	for(int i = 0; i < max; i++)
	{
		int count = counting[i];
		for(int j = 0; j < count; j++)
		{
			a[k] = i;
			k++;
		}
	}
}

void testCountingSort()
{
	drawLine();
	cout << "Test CountingSort()" << endl;
	int a[] = {5, 8, 0, 2, 4, 1, 7, 9, 3, 6};
	cout << "Original Array: ";
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl << endl;
	countingSort(a, 10, 9);
	cout << "CountingSort: ";
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
}


int main()
{
	testCountingSort();
	return 0;
}