//
// Created by Jonny Keane on 10/21/21.
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

bool hGreater(const vector<long>& v, int h) {
    int count = 0;
    for (long l: v) {
        if (l >= h) {
            ++count;
        }
    }
    return count >= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int left = 0, right = n;
    vector<long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    while (left != right) {
        int center = (left + right + 1) / 2;
        if (hGreater(v, center)) {
            left = center;
        } else {
            right = center - 1;
        }
//        cout << left << " " << right << endl;
    }
    cout << left << endl;

    return 0;
}