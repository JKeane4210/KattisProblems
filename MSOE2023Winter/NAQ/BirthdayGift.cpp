//
// Created by keanej on 2/22/2023.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

ll MOD = 1000000007;

struct Matrix {
public:
    int n, m;
    V<vll> data;
    Matrix(int n, int m) : n(n), m(m) {
        data = V<vll>(n, vll(m, 0));
    }

    Matrix mult(const Matrix & b) {
        Matrix res(n, b.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    res.data[i][k] += data[i][j] * b.data[j][k];
                    res.data[i][k] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix exp(Matrix a, ll e) {
    if (e == 1) return a;
    Matrix res(1, 1); // just a placeholder
    bool res_set = false;
    while (e > 0) {
        if (e % 2 == 1) {
            if (!res_set) {
                res_set = true;
                res = a;
            } else {
                res = res.mult(a);
            }
        }
        e /= 2;
        a = a.mult(a);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    int residue = 9;

    Matrix mat(residue * 10, residue * 10);

    // by going up to 90, we cover all digits with all mods
    // exponentiation matrix meant to have rows [mod_dig_n] -> rows [mod_dig_{n+1}]
    for (int i = 0; i < 90; ++i) {
        int dig = i % 10;
        int mod = i / 10;
        for (int d = 0; d < 10; ++d) {
            if (dig == d) continue; // don't add to relation if breaks adjacent number rule
            // because if we know that our current mod is mod, and we are adding d to it,
            // we can calculate the new mod by multiplying by 10 and adding digit
            int new_mod = (mod * 10 + d) % 9;
            mat.data[i][new_mod * 10 + d]++;
        }
    }

    // case a=1
    if (a == 1) {
        cout << ((b < 10) ? 1 : 0) << endl;
        return 0;
    }
    // case a=2
    if (a == 2) {
        cout << ((b < 100 && b >= 10 && (b / 10) != (b % 10)) ? 1 : 0) << endl;
        return 0;
    }

    Matrix e = exp(mat, a - 2); // matrix starts already having processed the cases of the first two digits

    ll res = 0;
    ll b_25 = b % 25;
    ll b_9 = b % 9;

    for (int i = 0; i < 100; ++i) {
        // only things with same base 25 residue and different first two digits are allowed through
        if (i % 25 != b_25 || i / 10 == i % 10) continue;
        // examine digits 1-9 because we can't have leading 0's
        for (int d = 1; d < 10; ++d) {
            // row: the mod 25's mod for mod 9 + the second digit it should be (i / 10)
            // col: values that have modulus b_9 and end in each of the possible digits
            res += e.data[(i % 9) * 10 + (i / 10)][b_9 * 10 + d];
            res %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}
