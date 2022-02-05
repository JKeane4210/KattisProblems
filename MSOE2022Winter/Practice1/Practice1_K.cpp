//
// Created by Jonny Keane on 1/29/22.
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

/**
 * Class that gives us an integer that resides within the given modulus ring
 * - we do not have a subtraction operator although trivial to implement
 *      - instead, use negative addition
 * - for division, only works if modulus is prime
 * @author Jonny Keane
 */
class PModInt {
public:
    int i;
    int mod;
    PModInt(int i_, int mod_ = 1000000009) {
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

void solve() {
    vector<string> s(3);
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }
    PModInt p(0);
    PModInt g21(0);
    for (int i = 0; i < max(s[0].size(), s[1].size()); ++i) {
        if (s[0][i] == '?' && s[1][i] != '?') {
            cout << (s[1][i] - 'a') << endl;
            g21 = g21 * 26 + (s[1][i] - 'a');
        } else if (s[0][i] != '?' && s[1][i] == '?') {
            cout << ('z' - s[0][i]) << endl;
            g21 = g21 * 26 + ('z' - s[0][i]);
        }
    }
    cout << g21.toString() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}