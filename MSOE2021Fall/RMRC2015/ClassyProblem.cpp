//
// Created by Jonny Keane on 9/2/21.
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

void solve() {
//    ifstream cin("/Users/jkeane/Desktop/class-02.in.txt");
    int n;
    cin >> n;
    pair<int, int> status_nums_lens[n];
    string names[n];
    map<int, set<string>> mappings;
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        string status, extra;
        cin >> names[i] >> status >> extra;
        int num = 0;
        int len = 1;
        int pow = 1;
        if (status[0] == 'u') {
            num = 2;
        } else if (status[0] == 'm') {
            num = 1;
        }
        for (int j = 0; j < status.size() - 1; ++j) {
            if (status[j] == '-') {
                ++len;
                pow *= 3;
                if (status[j + 1] == 'u') {
                    num += pow * 2;
                } else if (status[j + 1] == 'm') {
                    num += pow * 1;
                }
            }
        }
        status_nums_lens[i] = make_pair(num, len);
        max_len = max(max_len, len);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < max_len - status_nums_lens[i].second; ++j) {
            status_nums_lens[i].first *= 3; // base 3 shift
            status_nums_lens[i].first += 1; // OR-ing the first bit
        }
        if (mappings.find(status_nums_lens[i].first) == mappings.end()) {
            mappings[status_nums_lens[i].first] = set<string>();
        }
        mappings[status_nums_lens[i].first].insert(names[i].substr(0, names[i].size() - 1));

    }
    for (auto it = mappings.rbegin(); it != mappings.rend(); it++) {
        for (const string& name: it->second) {
            cout << name << "\n";
        }
    }
    cout << "==============================" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}