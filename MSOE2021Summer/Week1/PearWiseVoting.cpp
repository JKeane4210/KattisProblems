//
// Created by Jonny Keane on 5/23/21.
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

void dfs(int candidate, set<char>* winners, set<char>* visited) {
    visited->insert(candidate + 'A');
    for (char otherCandidate: winners[candidate]) {
        if (visited->count(otherCandidate) == 0) {
            dfs((int)(otherCandidate - 'A'), winners, visited);
        }
    }
}

bool canWin(int currC, set<char>* winners, int n) {
    auto* visited = new set<char>();
    dfs(currC, winners, visited);
    return visited->size() == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    pair<int, string> ballots[m];
    set<char> winners[n];
    for (int i = 0; i < m; ++i) {
        int votes;
        string order;
        cin >> votes >> order;
        ballots[i] = make_pair(votes, order);
    }
    for (char c = 'A'; c < (char)('A' + n); c = (char)(c + 1)) {
        pair<int, int> totals[n]; // current c vs. other total
        fill(totals, totals + n, make_pair(0, 0));
        for (auto ballot: ballots) {
            for (char c2 = 'A'; c2 < (char)('A' + n); c2 = (char)(c2 + 1)) {
                if (c == c2) continue;
                if (ballot.second.find(c) < ballot.second.find(c2)) {
                    totals[c2 - 'A'].first += ballot.first;
                } else {
                    totals[c2 - 'A'].second += ballot.first;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (c - 'A' == i) continue;
            if (totals[i].second < totals[i].first) {
                winners[c - 'A'].insert((char)'A' + i);
            } else {
                winners[i].insert(c);
            }
        }
    }

//    for (int j = 0; j < n; ++j) {
//        cout << (char)('A' + j) << ": ";
//        for (auto v: winners[j]) {
//            cout << v << " ";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < n; ++i) {
        if (canWin(i, winners, n)) {
            cout << (char)('A' + i) << ": can win" << endl;
        } else {
            cout << (char)('A' + i) << ": can't win" << endl;
        }
    }
    return 0;
}