//
// Created by Jonny Keane on 7/5/21.
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

int polyVal(const int* vals, int size, int x) {
    int in = 1;
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += vals[i] * in;
        in *= x;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int vals[n + 1];
    int res = 0;
    for (int i = 0; i < n + 1; ++i) {
        cin >> vals[n - i];
        res += vals[n - i];
    }

    int polyVals[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        polyVals[i] = polyVal(vals, n + 1, i);
    }

    int C_vals[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        C_vals[i] = 0;
    }
    C_vals[0] = polyVals[0];

    int t_vals[n + 1][n + 1];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            t_vals[i][j] = 0;
        }
    }
    t_vals[0][0] = 1;

    for (int i = 1; i < n + 1; ++i) {
        t_vals[i][0] = 1;
        for (int j = 0; j < i - 1; ++j) {
            t_vals[i][j + 1] = t_vals[i - 1][j] + t_vals[i - 1][j + 1];
        }
        t_vals[i][i] = 1;
        int nextC_val = polyVals[i];
        for (int j = 0; j < n + 1; ++j) {
            nextC_val -= C_vals[j] * t_vals[i][j];
        }
        C_vals[i] = nextC_val;
    }

    for (int C_val : C_vals) {
        cout << C_val << " ";
    }
    cout << endl;

    return 0;
}