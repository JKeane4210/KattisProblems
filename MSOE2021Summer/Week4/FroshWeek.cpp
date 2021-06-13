//
// Created by Jonny Keane on 6/13/21.
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

    int n, m;
    cin >> n >> m;
    int tasks[n];
    int intervals[m];
    for (int  i= 0; i < n; ++i) {
        cin >> tasks[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> intervals[j];
    }
    sort(tasks, tasks + n);
    sort(intervals, intervals + m);
    int taskPoint = n - 1;
    int intervalPoint = m - 1;
    int res = 0;
    while (taskPoint != -1 && intervalPoint != -1) {
//        cout << tasks[taskPoint] << " " << intervals[intervalPoint] << endl;
        if (tasks[taskPoint] <= intervals[intervalPoint]) {
            ++res;
            --intervalPoint;
        }
        --taskPoint;
    }
    cout << res << endl;

    return 0;
}