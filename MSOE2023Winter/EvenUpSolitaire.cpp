//
// Created by keanej on 1/17/2023.
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

int moves(vi arr, bool first) {
    int streakSum = arr[0];
    int streak = 1;
    int mod = arr[0] % 2;
    vector<int> next;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] % 2 != mod) {
            if (streak % 2 == 1) {
                next.pb(arr[i - 1]);
            }
            streak = 1;
            mod = arr[i] % 2;
            streakSum = arr[i];
        } else {
            streak++;
            streakSum += arr[i];
        }
    }
    if (streak % 2 == 1) {
        next.pb(arr[arr.size() - 1]);
    }
    if (first) {
        return moves(next, false);
    } else {
        return next.size();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << moves(arr, true) << endl;
    
    return 0;
}
