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

double fact(int n) {
    return n == 0 ? 1 : (double)n * fact(n - 1);
}

double nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int N, V1, V2, W;
        cin >> N >> V1 >> V2 >> W;
        int win = N / 2 + 1;
        if (V1 >= win) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        if (V2 >= win) {
            cout << "RECOUNT!" << endl;
            continue;
        }
        double prob = 0;
        int rem = N - V1 - V2;
        for (int j = win - V1; j <= rem; ++j) {
//            cout << rem << " " << j << " ";
//            printf("%.14f\n", prob * 100);
            prob += nCr(rem, j) * pow(0.5, j) * pow(0.5, rem - j);
        }
//        printf("%.10f\n", prob * 100);
        if (prob == 0) {
            cout << "RECOUNT!" << endl;
        } else if (prob * 100 > W) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        } else {
            cout << "PATIENCE, EVERYONE!" << endl;
        }
    }

    return 0;
}