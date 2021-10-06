//
// Created by Jonny Keane on 9/12/21.
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
    map<int, int> people_counts;
    int message_count = 0;
    for (int i = 0; i < m; ++i) {
        ++message_count;
        for (auto & p: people_counts) {
            ++p.second;
        }
        int person;
        cin >> person;
        people_counts[person] = 0;
        unsigned long total = ((unsigned long)n - people_counts.size()) * message_count;
        for (auto p: people_counts) {
            total += p.second;
        }
        cout << total << endl;
    }

    return 0;
}