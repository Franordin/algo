#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Add(string str1, string str2) {
	string temp;
	if (str1.length() > str2.length()) {
		temp = string(str1.length() - str2.length(), '0');
		str2.insert(0, temp);
	}
	else if (str1.length() < str2.length()) {
		temp = string(str2.length() - str1.length(), '0');
		str1.insert(0, temp);
	}

	string result;

	int tmp = 0;

	for (int i = str1.length(); i > 0; i--) {
		int sum = 0;

		cout << "str1 : " << stoi(str1.substr(i - 1, i)) << endl;
		sum += stoi(str1.substr(i - 1, i));
		cout << "str2 : " << stoi(str2.substr(i - 1, i)) << endl;
		sum += stoi(str2.substr(i - 1, i));
		sum += tmp;

		cout << "sum : " << sum << ", tmp : " << tmp << endl;

		if (sum / 10) tmp = 1;
		else tmp = 0;

		result.insert(0, to_string(sum % 10));

		sum = 0;
	}

	return result;
}

int main() {
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		//, {"54544", "44545", to_string(54544 + 44545)}
		//, {"5555", "55", to_string(5555 + 55)}
		//, {"5555", "5555", to_string(5555 + 5555)}
		//, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests) {
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
