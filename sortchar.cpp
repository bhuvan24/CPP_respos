#include <iostream>
#include <string>

using namespace std;


void printSortedarray(string arr, int n)
{
	if (n == 1)
	{
		cout << arr;
		return;
	}
	
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);

	printSortedarray(arr, n - 1);
}

int main()
{
	string str;
	getline(cin, str);
	
	int val = str.length();
	printSortedarray(str, val);
	return 0;
}