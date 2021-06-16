//
// Created by Jonny Keane on 6/15/21.
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

int minimize(const int* data, int start, int level, int n) {
    for (int i = start; i < (1 << n); i += (1 << level)) {
        if (data[i] != data[start]) {
            return 1 + minimize(data, start | (1 << level), level + 1, n) + minimize(data, start, level + 1, n);
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int data[1<<n];

    for (int i = 0; i < (1 << n); ++i) {
        cin >> data[i];
    }

    int res = minimize(data, 0, 0, n);
    cout << res << endl;

    return 0;
}