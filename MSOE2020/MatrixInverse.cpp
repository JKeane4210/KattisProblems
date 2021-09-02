#include <bits/stdc++.h>

using namespace std;

int main() {
    int count = 1;
    int a, b, c, d;
    while (cin >> a) {
        cin >> b >> c >> d;
        int det = a * d - b * c;
        cout << "Case " << count << ":\n";
        cout << d / det << " " << -b / det << "\n";
        cout << -c / det << " " << a / det << endl;
        ++count;
    }
    return 0;
}