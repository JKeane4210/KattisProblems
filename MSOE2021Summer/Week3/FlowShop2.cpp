//
// Created by Jonny Keane on 6/6/21.
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

    /*
     * New Strategy: Just clear out anything that can be removed
     * - Can I go down the diagonal?
     */

    int N, M;
    cin >> N >> M;
    int stages[N][M];
    int overlaps[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> stages[i][j];
            overlaps[i][j] = stages[i][j];
        }
    }
//    long long totalTime = 0;
    for (int i = 0; i < M; ++i) {
        int max_ = stages[0][i];
        for (int j = 0; j < i; ++j) {
            int maxCopy = max_;
            int k = 0;
            while (maxCopy != 0 && k < i - j) {
                int subMin = min(maxCopy, overlaps[j + 1][k]);
                maxCopy -= subMin;
                overlaps[j + 1][k] -= subMin;
                ++k;
            }
            if (i != 0 && j != N - 1) {
                max_ = max(max_, stages[j + 1][i - j - 1]);
            }
        }
    }
    // needs to clear row as if new
    for (int i = 1; i < N; ++i) {
        int max_ = stages[i][M - 1];
        for (int j = i + 1; j < N; ++j) {
            int maxCopy = max_;
            int k = 0;
            while (maxCopy != 0 && k < M - 1) {
                int subMin = min(maxCopy, overlaps[j][k]);
                maxCopy -= subMin;
                overlaps[j][k] -= subMin;
                ++k;
            }
            if (i != 0 && j != N - 1) {
                max_ = max(max_, stages[j + 1][i - j - 1]);
            }
        }
    }
    int totalTime = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            totalTime += overlaps[i][j];
        }
        cout << totalTime << " ";
    }
    cout << endl;
    return 0;
}
