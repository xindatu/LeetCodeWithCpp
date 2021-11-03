#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void selectionSort(vector<int>& arr) {
	int n = arr.size();
	int minIdx;
	for (int i = 0; i < n-1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}
		if (i != minIdx) 
		{
			swap(arr, i, minIdx);
		}
	}

}

void bubbleSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = n - 1; i > -1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
}

void insertionSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr, j, j - 1);
			}
			else
			{
				break;
			}
		}
	}
}

vector<int> merge(vector<int>& left, vector<int>& right) {
	vector<int> arr;
	vector<int>::iterator t1 = left.begin();
	vector<int>::iterator t2 = right.begin();
	while (t1 != left.end() && t2 != right.end()) 
	{
		arr.push_back(*t1 < *t2 ? *t1++ : *t2++);
	}
	while (t1 != left.end())
	{
		arr.push_back(*t1++);
	}
	while (t2 != right.end())
	{
		arr.push_back(*t2++);
	}
	return arr;

}

void mergeSort(vector<int>& arr) {
	int n = arr.size();
	if (!(n / 2)) {
		return;
	}
	vector<int> left(arr.begin(), arr.begin() + n / 2);
	mergeSort(left);
	vector<int> right(arr.begin() + n / 2, arr.end());
	mergeSort(right);
	arr = merge(left, right);
}

int partition(vector<int>& arr, int L, int R)
{
	int p = L;
	for (int i = L; i < R; i++)
	{
		if (arr[i] <= arr[R])
		{
			swap(arr, i, p++);
		}
	}
	swap(arr, p, R);
	return p;
}

void quickSort(vector<int>& arr, int L, int R)
{
	if (L < R) 
	{
		swap(arr, L + rand() % (R - L + 1), R);
		int p = partition(arr, L, R);
		quickSort(arr, L, p-1);
		quickSort(arr, p+1, R);
	}
}

void heapSort(vector<int>& arr) {
	int n = arr.size() - 1;
	int maxIdx;
	while (n)
	{
		for (int i = n; i >= 0; i--)
		{
			if (i * 2 + 1 <= n)
			{
				maxIdx = i * 2 + 2 <= n && arr[i * 2 + 2] > arr[i * 2 + 1] ? i * 2 + 2 : i * 2 + 1;
				if (arr[i] < arr[maxIdx])
				{
					swap(arr, i, maxIdx);
				}
			}
		}
		swap(arr, n--, 0);
	}
}

int main() {
	vector<int> arr{ 5, 6, 1, 2, 7, 0, 3, 5, 1 };
	//selectionSort(arr);
	//bubbleSort(arr);
	//insertionSort(arr);
	//mergeSort(arr);
	//quickSort(arr, 0, arr.size()-1);
	heapSort(arr);

	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}