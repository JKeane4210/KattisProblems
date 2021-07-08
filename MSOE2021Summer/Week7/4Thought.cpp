//
// Created by Jonny Keane on 7/4/21.
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

char ops[4] = {'/', '*', '+', '-'};

int performOps(vector<char> currOps, vector<int> chunks) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, vector<char>> solutions;

    for (char & i : ops) {
        for (char & j : ops) {
            for (char & k : ops) {
                vector<char> solution = {i, j, k};
                int res = performOps(solution, {4, 4, 4, 4});
                solutions[res] = solution;
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        if (solutions.find(n) != solutions.end()) {
            vector<char> sol = solutions[n];
            printf("4 %c 4 %c 4 %c 4 = %i\n", sol[0], sol[1], sol[2], n);
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}