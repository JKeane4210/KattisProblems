//
// Created by Jonny Keane on 1/18/22.
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

    int p, d;
    cin >> p >> d;
    // want to track total votes, total a, total b
    int totals[d][3];
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < 3; ++j) {
            totals[i][j] = 0;
        }
    }
    int all = 0;
    for (int i = 0; i < p; ++i) {
        int district, a, b;
        cin >> district >> a >> b;
        all += a + b;
        totals[district - 1][0] += a + b;
        totals[district - 1][1] += a;
        totals[district - 1][2] += b;
    }
    int wa = 0;
    int wb = 0;
    for (int i = 0; i < d; ++i) {
        cout << (totals[i][1] > totals[i][2] ? 'A' : 'B') << " ";
        if (totals[i][1] > totals[i][2]) {
            wa += totals[i][1] - ((totals[i][0]) / 2 + 1);
            wb += totals[i][2];
            cout << totals[i][1] - ((totals[i][0]) / 2 + 1) << " " << totals[i][2] << endl;
        } else {
            wa += totals[i][1];
            wb += totals[i][2] - ((totals[i][0]) / 2 + 1);
            cout << totals[i][1] << " " << totals[i][2] - ((totals[i][0]) / 2 + 1) << endl;
        }
    }
    cout.precision(10);
    cout << (double)(abs(wa - wb))/ (double)all << endl;

    return 0;
}