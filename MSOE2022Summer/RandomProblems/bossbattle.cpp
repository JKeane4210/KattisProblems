#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 3) { 
		cout << 1 << endl;
		return 0;
	}
	int u = 0;
	int b = n - 1;
	int bombs = 0;
	while (b - u > 1) {
		u += 2;
		b++;
		++bombs;
	}
	cout << bombs << endl;
	return 0;
}