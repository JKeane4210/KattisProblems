//
// Created by Jonny Keane on 7/26/21.
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
    string vals[n];
    for (int i= 0; i < n; ++i) {
        cin >> vals[i];
    }
    // edge case around 0?
    for (int i = 0; i < n - 1; ++i) {
        if (vals[i].size() == vals[i + 1].size() && vals[i] != "0") {
            if (!(vals[i][0] == '1' && vals[i + 1][0] == '9') || vals[i].substr(1) > vals[i + 1].substr(1)) {
                if (vals[i][0] == '1') {
                    vals[i][0] = '9';
                } else {
                    vals[i + 1][0] = '1';
                }
                for (auto &s: vals) {
                    cout << s << " ";
                }
                cout << endl;
                return 0;
            } else if (vals[i] == "1" && vals[i + 1] == "9") {
                vals[i + 1] = "0";
                for (auto &s: vals) {
                    cout << s << " ";
                }
                cout << endl;
                return 0;
            }
        } else if (vals[i] == "0") {
            if (vals[i + 1].size() == 1 && vals[i + 1] < "9") {
                vals[i] = "9";
                for (auto &s: vals) {
                    cout << s << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}