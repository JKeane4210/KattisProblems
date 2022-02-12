//
// Created by Jonny Keane on 2/9/22.
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
    pii workers[n + 1];
    long long lines_per_hr = 0;
    long long bugs_per_hr = 0;
    for (int i = 1; i <= n; ++i){
        int l_i, f_i;
        cin >> l_i >> f_i;
        workers[i] = make_pair(l_i, f_i);
        lines_per_hr += l_i;
        bugs_per_hr += f_i;
    }
    cout << lines_per_hr << " " << bugs_per_hr << endl;
    int e;
    cin >> e;
    for (int i = 0; i < e; ++i) {
        string type;
        cin >> type;
        if (type == "q") {
            int worker;
            cin >> worker;
            lines_per_hr -= workers[worker].first;
            bugs_per_hr -= workers[worker].second;
            cout << lines_per_hr << " " << bugs_per_hr << endl;
        } else {
            int t, l, f;
            cin >> t >> l >> f;
            if (lines_per_hr * t >= l && bugs_per_hr * t >= f) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
        }
    }
    return 0;
}