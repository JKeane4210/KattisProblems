//
// Created by Jonny Keane on 10/23/21.
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

    int Q, M, S, L;
    cin >> Q >> M >> S >> L;

    priority_queue<int, vector<int>, greater<int> > pq;
    int big_div = L / M;
    L -= big_div * M;
    for (int i = 0; i < M; ++i) {
        pq.push(big_div * Q);
    }
    for (int i = 0; i < L; ++i) {
        int top = pq.top();
        pq.pop();
        pq.push(top + Q);
    }
    for (int i = 0; i < S; ++i) {
        int top = pq.top();
        pq.pop();
        pq.push(top + 1);
    }
    int max_ = 0;
    while (!pq.empty()) {
        max_ = max(max_, pq.top());
        pq.pop();
    }
    cout << max_ << endl;

    return 0;
}
