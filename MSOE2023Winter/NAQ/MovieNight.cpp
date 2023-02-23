//
// Created by keanej on 2/22/2023.
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

ll MOD = 1000000007;

ll tree_poss(int curr, const vi * b_conns) {
    ll res = 1;
    for (auto c: b_conns[curr]) {
        res = (res * tree_poss(c, b_conns)) % MOD;
    }
//    cout << curr << " " << res + 1 << endl;
    return res + 1;
}

void solve(vi & colors, const vi & conns, const vi * b_conns) {
    set<int> processed;
    int cycles = -1;
    for (int i = 0; i < colors.size(); ++i) {
        if (colors[i] == 0) {
            set<int> comp_processed;
            int curr = i;
            bool new_cycle = false;
            while (colors[curr] >= 0) {
                comp_processed.insert(curr);
                if (processed.find(curr) != processed.end()) break;
                if (colors[curr] == 0) colors[curr] = 1;
                else if (colors[curr] == 1) { new_cycle = true; colors[curr] = cycles; }
                else break;
                curr = conns[curr];
            }
            processed.insert(comp_processed.begin(), comp_processed.end());
            if (new_cycle) cycles--;
        }
    }
    cycles = -cycles - 1;
    V<vi> cycle_starts(cycles, vi());
    for (int i = 0; i < colors.size(); ++i) {
        if (colors[i] == 1 && colors[conns[i]] < 0) {
            cycle_starts[-colors[conns[i]] - 1].pb(i);
        }
    }
    ll res = 1;
    for (int i = 0; i < cycles; ++i) {
        ll comp_res = 1;
        for (auto v: cycle_starts[i]) {
            comp_res = (comp_res * tree_poss(v, b_conns)) % MOD;
//            cout << endl;
        }
        comp_res++;
        res = (res * comp_res) % MOD;
    }
    cout << (res - 1 + MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi b_conns[n];
    vi conns(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        conns[i] = a;
        b_conns[a].pb(i);
    }

    vi colors(n, 0);
    solve(colors, conns, b_conns);

    return 0;
}