//
// Created by Jonny Keane on 3/2/22.
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

int K_DELTAS[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {1, -2}, {-1, 2}, {2, -1}, {-2, -1}, {-1, -2}};

pii R, T;

// giving search a heuristic
struct Compare
{
    bool operator()(const pii& a, const pii&b)
    {
        return abs(a.first - T.first) + abs(a.second - T.second) > abs(b.first - T.first) + abs(b.second - T.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    V<string> grid(r);
    bool knights[r][c];
    bool vert_seen[r][c];
    bool horiz_seen[r][c];
    int block_count[r][c];
    // fill grid and preprocess data structures
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
        for (int j = 0; j < c; ++j) {
            block_count[i][j] = 0;
            knights[i][j] = false;
            vert_seen[i][j] = false;
            horiz_seen[i][j] = false;
            if (grid[i][j] == 'R') {
                R = mp(i, j);
            }
            if (grid[i][j] == 'T') {
                T = mp(i, j);
            }
            if (grid[i][j] == 'K') {
                knights[i][j] = true;
            }
        }
    }
    // mark off blocked squares
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (knights[i][j]) {
                for (auto delta: K_DELTAS) {
                    int r2 = i + delta[0];
                    int c2 = j + delta[1];
                    if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c) {
                        ++block_count[r2][c2];
                    }
                }
            }
        }
    }
    // BFS with heuristic
    priority_queue<pii, vector<pii>, Compare> q;
    q.push(R);
    while (!q.empty()) {
        auto front = q.top();
        q.pop();
        if (front == T) {
            cout << "yes" << endl;
            return 0;
        }
        // add anything new that hasn't been seen start from this square, noting of blockings and visibility in each direction
        for (int i = front.first + 1; i < r; ++i) {
            if (vert_seen[i][front.second]) { break; }
            vert_seen[i][front.second] = true;
            if (block_count[i][front.second] == 0) {
                q.push(mp(i, front.second));
            }
            if (knights[i][front.second]) {
                if (block_count[i][front.second] != 0) {
                    break;
                }
                knights[i][front.second] = false;
                for (auto delta: K_DELTAS) {
                    int r2 = i + delta[0];
                    int c2 = front.second + delta[1];
                    if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c) {
                        --block_count[r2][c2];
                        if (block_count[r2][c2] == 0){
                            // if can access a square in same row or col, can go there again here and visit this cell
                            if (vert_seen[r2][c2] || horiz_seen[r2][c2]) {
                                q.push(mp(r2, c2));
                            }
                        }
                    }
                }
                break;
            }
        }
        for (int i = front.first - 1; i >= 0; --i) {
            if (vert_seen[i][front.second]) { break; }
            vert_seen[i][front.second] = true;
            if (block_count[i][front.second] == 0) {
                q.push(mp(i, front.second));
            }
            if (knights[i][front.second]) {
                if (block_count[i][front.second] != 0) {
                    break;
                }
                knights[i][front.second] = false;
                for (auto delta: K_DELTAS) {
                    int r2 = i + delta[0];
                    int c2 = front.second + delta[1];
                    if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c) {
                        --block_count[r2][c2];
                        if (block_count[r2][c2] == 0){
                            // if can access a square in same row or col, can go there again here and visit this cell
                            if (vert_seen[r2][c2] || horiz_seen[r2][c2]) {
                                q.push(mp(r2, c2));
                            }
                        }
                    }
                }
                break;
            }
        }
        for (int i = front.second + 1; i < c; ++i) {
            if (horiz_seen[front.first][i]) { break; }
            horiz_seen[front.first][i] = true;
            if (block_count[front.first][i] == 0) {
                q.push(mp(front.first, i));
            }
            if (knights[front.first][i]) {
                if (block_count[front.first][i] != 0) {
                    break;
                }
                knights[front.first][i] = false;
                for (auto delta: K_DELTAS) {
                    int r2 = front.first + delta[0];
                    int c2 = i + delta[1];
                    if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c) {
                        --block_count[r2][c2];
                        if (block_count[r2][c2] == 0){
                            // if can access a square in same row or col, can go there again here and visit this cell
                            if (vert_seen[r2][c2] || horiz_seen[r2][c2]) {
                                q.push(mp(r2, c2));
                            }
                        }
                    }
                }
                break;
            }
        }
        for (int i = front.second - 1; i >= 0; --i) {
            if (horiz_seen[front.first][i]) { break; }
            horiz_seen[front.first][i] = true;
            if (block_count[front.first][i] == 0) {
                q.push(mp(front.first, i));
            }
            if (knights[front.first][i]) {
                if (block_count[front.first][i] != 0) {
                    break;
                }
                knights[front.first][i] = false;
                for (auto delta: K_DELTAS) {
                    int r2 = front.first + delta[0];
                    int c2 = i + delta[1];
                    if (r2 >= 0 && r2 < r && c2 >= 0 && c2 < c) {
                        --block_count[r2][c2];
                        if (block_count[r2][c2] == 0){
                            // if can access a square in same row or col, can go there again here and visit this cell
                            if (vert_seen[r2][c2] || horiz_seen[r2][c2]) {
                                q.push(mp(r2, c2));
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    cout << "no" << endl;

    return 0;
}
