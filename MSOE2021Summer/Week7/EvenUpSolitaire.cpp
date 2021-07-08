//
// Created by Jonny Keane on 7/4/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int data[n];

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    while (true) {
        if (n == 0) {
            cout << 0 << endl;
            return 0;
        }
        bool done = true;
        for (int i = 0; i < n - 1; ++i) {
            if (((data[i] + data[i + 1]) & 1) == 0) {
                for (int j = i + 2; j < n; ++j) {
                    data[j - 2] = data[j];
                }
                n -= 2;
                done = false;
                break;
            }
        }
        if (!done) continue;
        cout << n << endl;
        return 0;
    }
    return 0;
}

// 1 2 3 3 2 1