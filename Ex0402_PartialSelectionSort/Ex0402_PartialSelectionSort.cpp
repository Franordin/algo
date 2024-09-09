#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

void Print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

void SelectionSortPass(vector<int>& arr, int lo, int hi) {
	int min_index = lo;
	for (int j = lo + 1; j <= hi; j++)
		if (arr[j] < arr[min_index])
			min_index = j;
	swap(arr[lo], arr[min_index]);
}

void PartialSelectionSort(vector<int>& arr, int k) {
	Print(arr);

	for (int i = 0; i < k; i++) {
		SelectionSortPass(arr, i, arr.size() - 1);
		Print(arr);
	}
}

int main() {
	vector<int> my_vector = { 7, 10, 3, 4, 20, 15 };

	int k = 3;

	PartialSelectionSort(my_vector, k);

	cout << my_vector[k - 1] << endl;

	return 0;
}