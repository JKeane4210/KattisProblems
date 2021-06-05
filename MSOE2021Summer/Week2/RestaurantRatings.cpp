//
// Created by Jonny Keane on 5/30/21.
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

long perms(int sum, int n) {
    if (n == 1) {
        return sum + 1;
    } else {
        long res = 0;
        for (int i = 0; i <= sum; ++i) {
            res += perms(sum - i, n - 1);
        }
        return res;
    }
}

void solve(const int* ratings, int n, int sum) {
    long res = 0;
    res += perms(sum - 1, n);
    for (int i = 0; i < n - 1; ++i) {
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n != 0) {
        int ratings[n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> ratings[i];
            sum += ratings[i];
        }
        solve(ratings, n, sum);
        cin >> n;
    }

    return 0;
}