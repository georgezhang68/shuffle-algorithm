#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void Fisher_Yates_Shuffle(vector<int> arr);
void Knuth_Durstenfeld_Shuffle(vector<int> arr);
void Output_Shuffle_Array(vector<int> s_arr);
void Inside_Out_Shuffle(vector<int> arr);
void Reservoir_Sampling(vector<int> arr);

int main(void)
{
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
	}
	Fisher_Yates_Shuffle(arr);
	Knuth_Durstenfeld_Shuffle(arr);
	Inside_Out_Shuffle(arr);
	Reservoir_Sampling(arr);
}

/*
S(n) = O(n), T(n) = O(n^2)
*/
void Fisher_Yates_Shuffle(vector<int> arr)
{
	vector<int> shuffer_arr;
	int pos;
	srand((unsigned) time(NULL));
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		pos = rand() % arr.size();
		shuffer_arr.push_back(arr[pos]);
		arr.erase(arr.begin() + pos);
	}
	Output_Shuffle_Array(shuffer_arr);
}

/*
S(n) = O(1), T(n) = O(n)
*/
void Knuth_Durstenfeld_Shuffle(vector<int> arr)
{
	int pos;
	srand((unsigned) time(NULL));
	int size = arr.size();
	for (int i = size - 1; i >= 0; i--)
	{
		pos = rand() % (i + 1);
		swap(arr[pos], arr[i]);

	}
	Output_Shuffle_Array(arr);
}

/*
S(n) = O(n), T(n) = O(n)
*/
void Inside_Out_Shuffle(vector<int> arr)
{
	int pos;
	srand((unsigned) time(NULL));

	vector<int> shuffle_arr;
	shuffle_arr.assign(arr.size(), 0);
	copy(arr.begin(), arr.end(), shuffle_arr.begin());

	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		pos = rand() % (i + 1);
		swap(arr[pos], arr[i]);

	}
	Output_Shuffle_Array(arr);
}

/*
S(n) = O(1), T(n) = O(n)
*/
void Reservoir_Sampling(vector<int> arr)
{
	int k, pos;
	cin >> k;
	srand((unsigned) time(NULL));

	for (int i = k; i < arr.size(); i++)
	{
		pos = rand() % (i + 1);
		if (pos < k)
		{
			swap(arr[pos], arr[i]);
		}
	}
	for (vector<int>::iterator it = arr.begin(); it < arr.begin() + k; it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void Output_Shuffle_Array(vector<int> s_arr)
{
	for (vector<int>::iterator it = s_arr.begin(); it < s_arr.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}