#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int counts[26] = {0};
	for (char c : s) {
		counts[c - 'a']++;
	}
	int evens = 0;
	int odds = 0;
	for (int i: counts) {
		if (i == 0) continue;
		if (i % 2 == 0) {
			evens++;
		} else {
			odds++;
		}
	}
	if (s.size() == 1 || odds == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << min((int)s.size() - 1, odds - 1) << endl;
	return 0;
}