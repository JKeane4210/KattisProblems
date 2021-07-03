//
// Created by Jonny Keane on 6/27/21.
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

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    if (t == 0) {
        cout << 0 << endl;
        return 0;
    }
    long* currSquawks = (long *)malloc(n * sizeof(long));
    vector<int> graph[n];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        currSquawks[i] = 0;
    }
    currSquawks[s] = 1;
    int time = 0;
    while (time < t) {
        long* nextSquawks = (long*)malloc(n * sizeof(long));
        for (int i = 0; i < n; ++i) {
            nextSquawks[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (currSquawks[i] != 0) {
                for (int connUser : graph[i]) {
                    nextSquawks[connUser] += currSquawks[i];
                }
            }
        }
        currSquawks = nextSquawks;
        ++time;
    }
    long res = 0;
    for (int i = 0; i < n; ++i ) {
        res += currSquawks[i];
    }
    cout << res << endl;
//    __m128i;
//    uint_21t;
// school boy algorithm -> multiplication
// f-sanitize = unsigned/signed integer overflow in clang tests (oops and)
// implementation -> creating an algorithm (tough to do -> scared)
// div 2 saturday 8:05, wednesday, 10th, 11th

    return 0;
}