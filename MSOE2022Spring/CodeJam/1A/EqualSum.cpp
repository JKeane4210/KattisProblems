//
// Created by Jonny Keane on 4/8/22.
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

void solve() {
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < 29; ++i) {
        if (i != 0) {
            cout << (1 << i) << " " << (1 << i) + 1 << " ";
            pq.push((1 << i));
            pq.push((1 << i) + 1);
        } else {
            cout << (1 << i) << " ";
            pq.push((1 << i));
        }
    }
    for (int i = 0; i < 100 - 57; ++i) {
        cout << 100000000 - i;
        pq.push(100000000 - i);
        if (i != 100 - 57 - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    vector<int> a;
    vector<int> b;
    long sumA = 0;
    long sumB = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
    }
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        if (sumA < sumB) {
            sumA += top;
            a.pb(top);
        } else {
            sumB += top;
            b.pb(top);
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i != a.size() - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
//    if (sumA == sumB) {
//        cout << "Smile" << endl;
//    } else {
//        cout << "Talk to the duck" << sumA << " " << sumB << endl;
//    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}