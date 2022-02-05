//
// Created by Jonny Keane on 2/5/22.
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

    int m, n;
    cin >> m >> n;
    if (m < 8) {
        cout << "unsatisfactory" << endl;
    } else {
        cout << "satisfactory" << endl;
    }
//        int clauses[m][3];
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < 3; ++j) {
//                cin >> clauses[i][j];
//            }
//        }
//        for (int i = 0; i < 1 << n; ++i) {
//            bool passes = true;
//            for (auto clause: clauses) {
//                bool clause_pass = false;
//                for (int j = 0; j < 3; ++j) {
//                    cout << clause[j] << endl;
//                    if ((clause[j] < 0 && ~i & (1 << (-clause[j] - 1))) || (clause[j] > 0 && i & (1 << (clause[j] - 1)))) {
//                        clause_pass = true;
//                        break;
//                    }
//                }
//                if (!clause_pass) {
//                    passes = false;
//                    break;
//                }
//            }
//            if (passes) {
//                cout << "satisfactory" << endl;
//                return 0;
//            }
//        }
//        cout << "unsatisfactory" << endl;
//    }

    return 0;
}