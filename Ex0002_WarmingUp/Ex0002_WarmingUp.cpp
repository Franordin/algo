#include <iostream>
#include <string>
using namespace std;

int main() {
	// 문제 1. 10진수 -> 2진수
	{
		//int decimal = 105;
		//string binary;
		//
		//while (decimal > 0) {
		//	int r = decimal % 2;
		//	binary = string(1, r + '0') + binary;
		//	decimal /= 2;
		//}
		//
		//cout << binary << endl; // 1101001
	}

	// 문제 2. 문자열 뒤집기
	{
		// Option #01
		//string input = "Hello, World!";
		//
		//for (int i = 0; i < input.length() / 2; i++) {
		//	swap(input[i], input[input.length() - 1 - i]);
		//}
		//
		//cout << input << endl; // !dlroW ,olleH

		// Option #02
		//string input = "Hello, World!";
		//int left = 0;
		//int right = input.size() - 1;
		//
		//while (left < right) {
		//	swap(input[left], input[right]);
		//	left++;
		//	right--;
		//}
		//cout << input << endl;
	}

	// 문제 3. 모든 자리 다 더하기
	{
		// Option #01
		//string n = "789789";

		//while (n.length() > 1) {
		//	int sum = 0;
		//	for (char c : n) {
		//		sum += c - '0';
		//	}
		//	n = to_string(sum);
		//}

		//cout << n << endl;

		// Option #02
		//string n = "789789";
		//
		//while (n.size() > 1) {
		//	int sum = 0;
		//	while (n.size() > 0) {
		//		sum += (n[0] - '0') % 10;
		//		n = n.substr(1, n.size() - 1);
		//	}
		//	cout << sum << endl;
		//	n = to_string(sum);
		//}
		//cout << n << endl;
	}

	return 0;
}
