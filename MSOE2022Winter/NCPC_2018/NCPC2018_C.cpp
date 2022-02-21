//
// Created by Jonny Keane on 2/15/22.
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
    int dirtiness = 0;
    int count_dirty = 0;
    int clean_phases = 0;
    int next_dirty = 0;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int day = arr[0]; day < arr[n - 1] + 20; ++day) {
        dirtiness += count_dirty;
        if (next_dirty != n && day == arr[next_dirty]) {
            ++count_dirty;
            ++next_dirty;
//            cout << count_dirty << endl;
        }
        if (dirtiness + count_dirty >= 20) {
//            cout << day << " " << dirtiness << " " << count_dirty << endl;
            ++clean_phases;
            dirtiness = 0;
            count_dirty = 0;
        }
    }
    cout << clean_phases << endl;

    return 0;
}