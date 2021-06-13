//
// Created by Jonny Keane on 6/12/21.
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

    // code here
    int N, M;
    cin >> N >> M;
    int stages[N][M];
    int ans[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> stages[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i > 0 && j > 0) {
                ans[i][j] = stages[i][j] + max(ans[i][j - 1], ans[i - 1][j]);
            } else if (i > 0) {
                ans[i][j] = stages[i][j] + ans[i - 1][j];
            } else if (j > 0) {
                ans[i][j] = stages[i][j] + ans[i][j - 1];
            } else {
                ans[i][j] = stages[i][j];
            }
        }
        cout << ans[i][M - 1] << " ";
    }
    cout << endl;
    return 0;
}