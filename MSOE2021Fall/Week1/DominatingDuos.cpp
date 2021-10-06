//
// Created by Jonny Keane on 9/5/21.
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
//    int n = 1000000;
    int d[n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
//        if (i % 2 == 1) {
//            d[i] = n - i;
//        } else {
//            d[i] = i;
//        }
//        cout << d[i] << " ";
    }
//    cout << endl;
    long res = 0;
    int l_p = 0;
    int r_p = 1;
    int inner_max = -1;
    while (l_p != n - 1) {
//        cout << l_p << " " << r_p;

        if (d[l_p] > inner_max && d[r_p] > inner_max && r_p != n) {
//            cout << "*" << endl;
            ++res;
            inner_max = max(inner_max, d[r_p]);
            ++r_p;
        } else {
//            cout << endl;
            ++l_p;
            r_p = l_p + 1;
            inner_max = -1;
        }
    }
    cout << res << endl;
    return 0;
}