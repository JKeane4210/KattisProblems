//
// Created by Jonny Keane on 2/23/22.
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
    long n, k;
    cin >> n >> k;
    map<string, long> attrs;
    for (int i = 0; i < n; ++i) {
        string attr;
        long val;
        cin >> attr >> val;
        attrs[attr] = val;
    }
    int l;
    cin >> l;
    map<string, vector<long> > events;
    for (int i = 0; i < l; ++i) {
        string attr;
        long val;
        cin >> attr >> val;
        if (events.find(attr) == events.end()) {
            events[attr] = vector<long>();
        }
        events[attr].pb(val);
        if (attrs[attr] < val) {
            k -= val - attrs[attr];
            attrs[attr] = val;
        }
    }
    if (k < 0) {
        cout << 0 << endl;
        return;
    }

    long score = 0;
    priority_queue<pair<long, string> > pq;
    for (auto & attr: attrs) {
//        cout << attr.first << " " << attr.second << endl;
        long point_addition = 0;
        for (auto event_score: events[attr.first]) {
            if (event_score == attr.second) {
                point_addition += attr.second + 1;
            } else {
                ++point_addition;
                score += attr.second;
            }
        }
        pq.push(make_pair(point_addition, attr.first));
    }
    set<string> visited;
    // maximize by adding to attr that gives most new points (greedy)
    for (long i = k; i > 0; --i) {
        auto top = pq.top();
//        cout << "point to " <<  top.second << endl;
        pq.pop();
        if (visited.find(top.second) != visited.end()) {
//            cout << i << " left" << endl;
            score += i * events[top.second].size();
            break;
        }
        score += top.first;
        long point_addition = events[top.second].size();
        pq.push(make_pair(point_addition, top.second));
        visited.insert(top.second);
    }
    cout << score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}