//
// Created by Jonny Keane on 6/30/21.
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

//vector<vector<pair<int,int>>> deltas = {{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}},
//                                   {{1, 0}, {2, 0}}, {{0, 1}, {0, 2}},
//                                   {{-2, 0}, {-1, 0}}, {{0, -1}, {0, -2}}};
const int WIDTH = 3;
int deltas[3][2] = {{0, 0}, {1, 0}, {0, 1}};

//int trayCoverings(pair<int, int> curr, bitset<72> open, int m, int total) {
//    if (open.none()) return 1;
//    for (vector<pair<int, int>> delta: deltas) {
//        bool valid = true;
//        for (auto deltaPoint: delta) {
//            int dr = curr.first + deltaPoint.first;
//            int dc = curr.second + deltaPoint.second;
//            if (dr < 0 || dr >= WIDTH || dc < 0 || dc >= m || !open[dr * m + dc]) {
//                valid = false;
//                break;
//            }
//        }
//        if (valid) {
//            for (auto deltaPoint: delta) {
//                int dr = curr.first + deltaPoint.first;
//                int dc = curr.second + deltaPoint.second;
//                bitset<72> newOpen(open);
//                newOpen[dr * m + dc] = false;
//            }
//            return trayCoverings()
//        }
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    int sumGrid[WIDTH][m];
    int numPathsGrid[WIDTH][m];
    bitset<72> open;

    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < m; ++j) {
            sumGrid[i][j] = 0;
            numPathsGrid[i][j] = 0;
            open[i * m + j] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        float x, y;
        cin >> x >> y;
        open[(int)y * m + (int)x] = false;
    }

    numPathsGrid[0][0] = 1;
    numPathsGrid[0][1] = 1;
    numPathsGrid[1][0] = 1;
    int sum = 0;
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto & delta: deltas) {
                int dr = i + delta[0];
                int dc = j + delta[1];
                if (dr < WIDTH && dc < m) {
                    if (i > 0) {
                        numPathsGrid[dr][dc] += numPathsGrid[i - 1][j]; // how many paths from 0,0 to i,j
                    }
                    if (j > 0) {
                        numPathsGrid[dr][dc] += numPathsGrid[i][j - 1];
                    }
                }
                sum += numPathsGrid[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}