//
// Created by Jonny Keane on 3/1/22.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

long range(int a, int b, long * pre, int n) {
    if (b >= n || b < a) {
        return pre[n - 1] - pre[a - 1] + pre[b % n];
    } else if (a == 0) {
        return pre[b];
    } else {
        return pre[b] - pre[a - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, p, k;
    cin >> n >> p >> k;
    long d[n];
    long pre[2 * n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (i == 0) {
            pre[i] = d[i];
        } else {
            pre[i] = d[i] + pre[i - 1];
        }
    }
    pii day_cache[n]; // {ending concert, number of rehearsal passes}}
    long base_rehearsals = p / pre[n - 1];
    long fill = p % pre[n - 1];
    int right = 0;
    for (int left = 0; left < n; ++left) {
        while (range(left, right, pre, n) <= fill) {
            ++right;
        }
        day_cache[left] = mp((right) % n, base_rehearsals + ((right) % n < left ? 1: 0));
//        cout << i << "->" << day_cache[i].first << " " << day_cache[i].second << endl;
    }
    map<pii, pair<long, int>> visited; // {transition_pair, {passes, day}}
    long passes = 0;
    int curr = 0;
    bool ring_used = false;
    for (int i = 0; i < k; ++i) {
        passes += day_cache[curr].second;
        pii trans = mp(curr, day_cache[curr].first);
        if (visited.find(trans) != visited.end() && !ring_used) {
            ring_used = true;
            passes += (k - 1 - i) / (i - visited[trans].second) * (passes - visited[trans].first);
            i += (i - visited[trans].second) * ((k - 1 - i) / (i - visited[trans].second));
        }
        visited[trans] = mp(passes, i);
//        cout << curr << "->" << day_cache[curr].first << " : " << passes << endl;
        curr = day_cache[curr].first;
    }
    cout << passes << endl;

    return 0;
}