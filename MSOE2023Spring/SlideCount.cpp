//
// Created by keanej on 5/10/2023.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    int s = 1, e = 1;
    int arr[n + 1];
    for (int i = 0; i < n; ++i) cin >> arr[i + 1];
    int curr_sum = 0;
    curr_sum += arr[s] + arr[e + 1];
    int starts[n];
    for (int i =0;  i<n; ++i) {
        starts[i] = -1;
    }
    starts[1] = 0;
    int curr_window = 0;
    while (s <= n) {
//        cout << curr_window << " " << s << " " << e << endl;
        if (e + 1 > n || curr_sum > c) {
            cout << curr_window - starts[s] + 1 << endl;
            curr_sum -= arr[s++];
        } else {
            e++;
            starts[e] = curr_window + 1;
            curr_sum += arr[e + 1];
        }
        curr_window++;
    }

    return 0;
}

