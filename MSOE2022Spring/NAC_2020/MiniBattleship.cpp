//
// Created by Jonny Keane on 3/29/22.
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

int search(const vector<int> & sizes, int n, bitset<25> marked, const vpii & hits, int curr) {
//    cout << curr << " " << sizes[curr] << " " << " " << marked.count() << endl;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - sizes[curr] + 1; ++j) {
            bool all_open = true;
            for (int k = j; k < j + sizes[curr]; ++k) {
                if (marked[i * n + k]) {
                    all_open = false; break;
                }
            }
            if (all_open) {
                bitset<25> next(marked);
                for (int k = j; k < j + sizes[curr]; ++k) {
                    next[i * n + k] = true;
                }
                if (curr == sizes.size() - 1) {
                    bool all_hit = true;
                    for (auto p : hits) {
                        if (!next[p.first * n + p.second]) {
                            all_hit = false;
                        }
                    }
                    if (all_hit) {
                        ++res;
                    }
                } else {
                    res += search(sizes, n, next, hits, curr + 1);
                }
            }
        }
    }
    if (sizes[curr] != 1) {
        for (int i = 0; i < n - sizes[curr] + 1; ++i) {
            for (int j = 0; j < n; ++j) {
                bool all_open = true;
                for (int k = i; k < i + sizes[curr]; ++k) {
                    if (marked[k * n + j]) {
                        all_open = false;
                        break;
                    }
                }
                if (all_open) {
                    bitset<25> next(marked);
                    for (int k = i; k < i + sizes[curr]; ++k) {
                        next[k * n + j] = true;
                    }
                    if (curr == sizes.size() - 1) {
                        bool all_hit = true;
                        for (auto p : hits) {
                            if (!next[p.first * n + p.second]) {
                                all_hit = false;
                            }
                        }
                        if (all_hit) {
                            ++res;
                        }
                    } else {
                        res += search(sizes, n, next, hits, curr + 1);
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<25> base; base.reset();
    vpii hits;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            if (line[j] == 'X') {
                base[i * n + j] = true;
            } else if (line[j] == 'O') {
                hits.pb(mp(i, j));
            }
        }
    }

    vector<int> ship_sizes(k);
    for (int i = 0; i < k; ++i) {
        cin >> ship_sizes[i];
    }

    cout << search(ship_sizes, n, base, hits, 0) << endl;

    return 0;
}