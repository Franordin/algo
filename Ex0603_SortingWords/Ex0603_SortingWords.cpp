#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr) {
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d) {
	vector<string> temp = arr; // 복사
	//std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의

	vector<int> count(k, 0);
	for (int i = 0; i < temp.size(); i++) {
		//cout << temp[i][d] << " ";
		count[temp[i][d] - 'A']++;
	}
	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = temp.size() - 1; i >= 0; i--) {
		count[temp[i][d] - 'A']--;
		arr[count[temp[i][d] - 'A']] = temp[i];

		cout << "Count: ";
		Print(count);

		cout << "Output: ";
		Print(arr);
	}
}


void RadixSort(vector<string>& arr) {
	int k = 26;

	for (int d = 2; d >= 0; d--) {
		cout << endl;
		for (int i = 65; i < 65 + k; i++)
			cout << (char)i << " ";

		cout << "Digit = " << d << endl;
		cout << "k = " << k << endl;
		CountingSort(arr, k, d);
	}
}

int main() {
	// CLRS 8.3-1
	vector<string> arr = { "COW", "DOG", "SEA", "RUG",
		"ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
		"DIG", "BIG", "TEA", "NOW", "FOX" };

	//for (int i = 0; i < arr.size(); i++) {
	//	for (int j = 0; j < 3; j++)
	//		cout << arr[i][j] - 65 << " ";
	//	cout << endl;
	//}

	Print(arr);

	RadixSort(arr);

	Print(arr);

	return 0;
}