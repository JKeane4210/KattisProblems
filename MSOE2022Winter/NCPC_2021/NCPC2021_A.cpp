//
// Created by Jonny Keane on 2/8/22.
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

    long long n, c;
    cin >> n >> c;
    long arr[n];
    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long best_y = LONG_MIN;
    long long best_inv_y = LONG_MIN;
    for (long long i = 0; i < n; ++i) {
        // updating best j term
        if (-arr[i] + c * i > best_y) {
            best_y = -arr[i] + c * i;
        }
        if (arr[i] + c * i > best_inv_y) {
            best_inv_y = arr[i] + c * i;
        }
        long long res = max(arr[i] - c * i + best_y, -arr[i] - c * i + best_inv_y);
        cout << res << " ";
    }
    cout << endl;


    return 0;
}