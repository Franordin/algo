#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
using namespace std;

void Print(vector<float>& arr) {
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void PrintBuckets(vector<vector<float>>& buckets) {
	for (int i = 0; i < buckets.size(); i++)
	{
		cout << i << ": ";
		for (int j = 0; j < buckets[i].size(); j++)
			cout << buckets[i][j] << " ";
		cout << endl;
	}
}

// 다른 정렬을 사용해도 됩니다.
void InsertionSort(vector<float>& bucket) {
	for (int i = 1; i < bucket.size(); ++i) {
		float key = bucket[i];
		int j = i - 1;
		while (j >= 0 && bucket[j] > key) {
			bucket[j + 1] = bucket[j];
			j--;
		}
		bucket[j + 1] = key;
	}
}

void BucketSort(vector<float>& arr, int num_buckets) {
	vector<vector<float>> buckets(num_buckets);

	for (auto& a : arr) buckets[a * 10].push_back(a);

	cout << "Before sorting" << endl;
	PrintBuckets(buckets);

	for (auto& b : buckets) {
		InsertionSort(b);
	}

	cout << "After sorting" << endl;
	PrintBuckets(buckets);

	//int pos = 0;
	//for (int i = 0; i < buckets.size(); i++) {
	//	while (!buckets[i].empty()) {
	//		arr[pos] = buckets[i].front();
	//		buckets[i].erase(buckets[i].begin());
	//		pos++;
	//	}
	//}

	int i = 0;
	for (auto& b : buckets) {
		if (b.size() > 0) {
			memcpy(&arr[i], &b[0], sizeof(b[0]) * b.size());
			i += int(b.size());
		}
	}
}

int main() {
	vector<float> arr = { 0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.67f };

	Print(arr);

	BucketSort(arr, 10);

	Print(arr);

	return 0;
}
