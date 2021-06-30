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

pair<int, int> rotatedCoord(pair<int, int> coord, int n) {
    return make_pair(coord.second, n - 1 - coord.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    char grid[n][n];
    char mask[n][n];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > currRotation;
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 0;
            mask[i][j] = line[j];
            if (mask[i][j] == '.') {
                currRotation.push(make_pair(i, j));
            }
        }
    }
    string encrypted;
    cin >> encrypted;
    int currChar = 0;
    for (int i = 0; i < 4; ++i) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > nextRotation;
        while (!currRotation.empty()) {
            auto top = currRotation.top();
            currRotation.pop();
            grid[top.first][top.second] = encrypted[currChar++];
            nextRotation.push(rotatedCoord(top, n));
        }
        currRotation = nextRotation;
    }
    string decrypted;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                cout << "invalid grille" << endl;
                return 0;
            } else {
                decrypted += grid[i][j];
            }
        }
    }
    cout << decrypted << endl;

    return 0;
}