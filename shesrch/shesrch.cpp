#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/////////////////////////////////////////////////////////////
//1 TEST 7 32 1 2 3 4 5 15 32
//2 TEST 16 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//
/////////////////////////////////////////////////////////////


void BinarySearch(vector<int> arr, int left, int right, int num, bool flag)
{



	int mid;
	if (flag == true)
	{
		if (right >= arr.size()) 
			right = arr.size() - 1;
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		cout << arr[mid] << " ";
		if (arr[mid] < num)
		{
			left = mid + 1;
		}
		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		if (arr[mid] == num)
		{
			break;
		}
	}
}


void DoublingSearch(vector<int> arr, int num)
{
	int i = 0;
	while (pow(2, i) < arr.size() && num > arr[pow(2, i)])
	{
		i -= -1;
	}
	if (pow(2, i) < arr.size() && arr[pow(2, i)] == num)
	{
		cout << num;
		return;
	}
	bool flag = true;
	if (i > 0)
		if (pow(2, i) < arr.size())
			BinarySearch(arr, pow(2, i - 1) + 1, pow(2, i) - 1, num, true);
		else
			BinarySearch(arr, pow(2, i - 1) + 1, pow(2, i), num, true);
	else
		BinarySearch(arr, 0, 1, num, true);
}

int main()
{
	// initial arr
	size_t size;
	cin >> size;
	vector<int> arr(size); int num;
	cin >> num;

	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "Initial array:\n";

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	// linear 
	cout << "\nLinear search:\n";

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] == num)
			break;
	}

	cout << "\nBinary search:\n";
	BinarySearch(arr, 0, arr.size()-1, num, false);
	cout << "\nDoubling search:\n";
	DoublingSearch(arr, num);



	return(0);
}