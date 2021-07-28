//
// Created by Jonny Keane on 7/18/21.
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

vector<string> perms;

void makePerms(bitset<10> config, string s) {
    if (config.all()) { perms.emplace_back(s); return; }
    for (int i = 0; i < 10; ++i) {
        if (!config[i]) {
            bitset<10> newConfig(config);
            newConfig[i] = true;
            makePerms(newConfig, s + to_string(i + 1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
//    makePerms(bitset<10>(), "");
//    ofstream cout("/Users/jkeane/Desktop/out.txt");
//    sort(perms.begin(), perms.end());
    bool* vals = (bool *)malloc((n + 1) * sizeof(bool));
    memset(vals, 0, (n + 1) * sizeof(bool));
    vector<int> curr;
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        vals[val] = true;
        curr.emplace_back(val);
    }
    for (int i = 1; i <= n; ++i) {
        if (vals[i]) continue;
        string next = to_string(i);
        auto it = curr.begin();
        while (it != curr.end()) {

            if (i < *it) {
                break;
            } else {
                ++it;
            }
        }
        curr.insert(it, i);
    }
    for (auto val: curr) {
        cout << val << endl;
    }

    return 0;
}