//
// Created by Jonny Keane on 5/8/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

class PModInt {
public:
    int i;
    int mod;
    PModInt(int i_, int mod_ = 1000000007) {
        i = i_ % mod_;
        mod = mod_;
    }
    PModInt operator+ (int a) {
        i = abs((i + a) % mod);
        return *this;
    }
    PModInt inline operator+ (PModInt pModInt) {
        return *this + pModInt.i;
    }
    PModInt operator* (int a) {
        i = (i * a) % mod;
        return *this;
    }
    PModInt inline operator* (PModInt pModInt) {
        return *this * pModInt.i;
    }
    PModInt operator/ (PModInt pModInt) {
        int c = pModInt.modInv();
        return *this * c;
    }
    PModInt inline operator/ (int a) {
        return *this / PModInt(a, mod);
    }
    string toString() {
        return to_string(i);
    }
    int modInv() {
        return pow(mod - 2);
    }

private:
    int pow(int n) {
        if (n == 0) return 1;
        int p = pow(n / 2) % mod;
        p = (p * p) % mod;
        return (n % 2 == 0) ? p : (i * p) % mod;
    }
};

int mod_factorial(int n) {
    PModInt res(1);
    while (n > 0) {
        res = res * n;
        --n;
    }
    return res.i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    cin >> line;
    int current1Slide = line.size() - 1;
    PModInt total(0);

    for (int i = line.size() - 1; i >= 0; --i) {
        if (line[i] == '1') {
            total = total + (current1Slide - i);
            for (int j = i; j < current1Slide; ++j) {
                line[j] = line[j + 1];
            }
            line[current1Slide--] = '1';
        }
    }
    vector<int> vars;

    for (int i = current1Slide; i >= 0; --i) {
        if (line[i] == '?') {
            vars.push_back(1); // the space to go back kind of
        }
    }
    total = total + mod_factorial(vars.size());

    cout << total.toString() << endl;

    return 0;
}