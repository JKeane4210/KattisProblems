#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string num;
		cin >> num;
		int dig_sum = 0;
		bool has_even = false;
		bool has_zero = false;
		for (char c: num) {
			dig_sum += c - '0';
			if (c == '0' && !has_zero) { has_zero = true; }
			else if ((c == '0' && has_zero) || (c != '0' && (c - '0') % 2 == 0)) {
				has_even = true;
			}
		}
		if (has_even && has_zero && dig_sum % 3 == 0) {
			cout << "red" << endl;
		} else {
			cout << "cyan" << endl;
		}
	}
	return 0;
}