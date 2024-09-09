﻿#include <vector>
#include <iostream>
using namespace std;

void Print(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	//vector<int> arr = { 5, 2, 7, 3, 8, 5, 6, 4 };
	//vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4};
	vector<int> arr = { 5, 2, 7, 3, 4, 4, 6, 4 };
	//vector<int> arr = { 9, 8, 7, 6, 4, 3, 2, 1, 5 };

	int lo = 0;
	int hi = arr.size() - 1;
	int x = arr[hi]; // 4

	int i = lo - 1; // pivot보다 작은 것들중 가장 큰 인덱스

	Print(arr);

	for (int j = lo; j < hi; j++) {
		if (arr[j] <= x)
			swap(arr[j], arr[++i]);

		cout << "i = " << i << ", j = " << j << endl;
		Print(arr);
	}

	swap(arr[i + 1], arr[hi]);
	Print(arr);

	cout << i + 1 << endl; // 피벗 이하인 값들의 마지막 인덱스
}
