//
// Created by Jonny Keane on 7/10/21.
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
        i = (i + a) % mod;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    PModInt total = 1;
    int step = 0;
    while (step < n) {
        ++step;
        total = total + total;
        if (total.i < data[step - 1]) {
            cout << "error" << endl;
            return 0;
        }
        total = total + -data[step - 1];
    }
    cout << total.toString() << endl;

    return 0;
}