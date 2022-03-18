#include <bits/stdc++.h>

using namespace std;

bool valid(string x, string y, string z, string op) {
    if (x.size() > 10 || y.size() > 10 || z.size() > 10) {
        return false;
    }
    if (op == "*") {
        if (stol(x) * stol(y) == stol(z)) {
            cout << x << " " << op << " " << y << " = " << z << endl;
            return true;
        } else {
            return false;
        }
    } else {
        if (stol(x) + stol(y) == stol(z)) {
            cout << x << " " << op << " " << y << " = " << z << endl;
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    string x, op, y, e, z;
    cin >> x >> op >> y >> e >> z;
    for (int i = 1; i < x.size(); ++i) {
        for (int j = 1; j < y.size(); ++j) {
            if (valid(y.substr(0, j) + x.substr(i), x.substr(0, i) + y.substr(j), z, op)) {
                return 0;
            }
        }
    }

    for (int i = 1; i < y.size(); ++i) {
        for (int j = 1; j < z.size(); ++j) {
            if (valid(x, z.substr(0, j) + y.substr(i), y.substr(0, i) + z.substr(j), op)) {
                return 0;
            }
        }
    }

    for (int i = 1; i < x.size(); ++i) {
        for (int j = 1; j < z.size(); ++j) {
            if (valid(z.substr(0, j) + x.substr(i), y, x.substr(0, i) + z.substr(j), op)) {
                return 0;
            }
        }
    }
    return 0;
}