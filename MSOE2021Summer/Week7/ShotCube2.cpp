//
// Created by Jonny Keane on 7/8/21.
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

unordered_map<bitset<49>, int> gridResults;

bitset<49> flipGrid(bitset<49> grid) {
    bitset<49> res;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            res[i * 7 + 6 - j] = grid[i * 7 + j];
        }
    }
    return res;
}

bitset<49> rotateGrid(bitset<49> grid) {
    bitset<49> res;
//    coord.second, n - 1 - coord.first
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            res[i * 7 + j] = grid[j * 7 + 6 - i];
        }
    }
    return res;
}

void memoizeAllConfigs(bitset<49> resultGrid, int res) {
    bitset<49> configGrid(resultGrid);
    for (int i = 0; i < 4; ++i) {
        gridResults[bitset<49>(configGrid)] = res;
        gridResults[flipGrid(configGrid)] = res;
        configGrid = rotateGrid(configGrid);
    }
}

pair<int, int> topCorner(bitset<49> currGrid) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (currGrid[i * 7 + j]) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool winningGrid(bitset<49> currGrid) {
    pair<int, int> upperLeft = topCorner(currGrid);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int r = upperLeft.first + i;
            int c = upperLeft.second + j;
            if (r >= 7 || c >= 7 || !currGrid[r * 7 + c]) return false;
        }
    }
    return true;
}

bool validDown(bitset<49> currGrid, pair<int, int> move) {
    while (currGrid[move.first] && move.first < 49) {
        move.first += 7;
    }
    while (!currGrid[move.first] && move.first < 49) {
        move.first += 7;
    }
    return move.first < 49;
}

bool validUp(bitset<49> currGrid, pair<int, int> move) {
    while (currGrid[move.first] && move.first >= 0) {
        move.first -= 7;
    }
    while (!currGrid[move.first] && move.first >= 0) {
        move.first -= 7;
    }
    return move.first >= 0;
}

bool validRight(bitset<49> currGrid, pair<int, int> move) {
    int end = move.first + 7;
    while (currGrid[move.first] && move.first < end) {
        move.first += 1;
    }
    while (!currGrid[move.first] && move.first < end) {
        move.first += 1;
    }
    return move.first < end;
}

bool validLeft(bitset<49> currGrid, pair<int, int> move) {
    int end = move.first - 6;
    while (currGrid[move.first] && move.first >= end) {
        move.first -= 1;
    }
    while (!currGrid[move.first] && move.first >= end) {
        move.first -= 1;
    }
    return move.first >= end;
}

vector<pair<int, int>> validMoves(bitset<49> currGrid) { // move is location, direction (7 = down, -7 = up, -1 = left, 1 = right)
    vector<pair<int, int>> res;
    for (int i = 0; i < 7; ++i) {
        if (!currGrid[i]) continue;
        pair<int, int> move = make_pair(i, 7);
        if (validDown(currGrid, move)) { res.push_back(move); }
    }
    for (int i = 0; i < 7; ++i) {
        if (!currGrid[42 + i]) continue;
        pair<int, int> move = make_pair(42 + i, -7);
        if (validUp(currGrid, move)) { res.push_back(move); }
    }
    for (int i = 0; i < 49; i += 7) {
        if (!currGrid[i]) continue;
        pair<int, int> move = make_pair(i, 1);
        if (validRight(currGrid, move)) { res.push_back(move); }
    }
    for (int i = 6; i < 49; i += 7) {
        if (!currGrid[i]) continue;
        pair<int, int> move = make_pair(i, -1);
        if (validLeft(currGrid, move)) { res.push_back(move); }
    }
    return res;
}

bitset<49> makeMove(bitset<49> currGrid, pair<int, int> moveLoc) {
    bitset<49> res(currGrid);
    int connected = 0;
    int loc = moveLoc.first;
    while (res[loc]) {
        ++connected;
        loc += moveLoc.second;
    }
    while (!res[loc]) {
        loc += moveLoc.second;
    }
    for (int i = 0; i < connected; ++i) {
        res[moveLoc.first + i * moveLoc.second] = false;
        res[loc - moveLoc.second - i * moveLoc.second] = true;
    }
    return res;
}

int minimalGame(bitset<49> currGrid, int currMove) {
//    if (res != -1 && currMove >= res) { return -1; }
    int res = -1;
    if (gridResults.find(currGrid) != gridResults.end()) {
//        cout << "grid memoized" << endl;
        if (gridResults[currGrid] == -1) { return -1; }
        return currMove + gridResults[currGrid];
    }
    if (winningGrid(currGrid)) {
        memoizeAllConfigs(currGrid, 0);
//        gridResults[currGrid] = 0;
        return currMove;
    }
    for (auto move: validMoves(currGrid)) {
        int moveRes = minimalGame(makeMove(currGrid, move), currMove + 1);
        if (moveRes != -1) {
            if (res == -1) {
                res = INT_MAX;
            }
            res = min(res, moveRes);
        }
    }
    if (res != -1) {
//        gridResults[currGrid] = res - currMove;
        memoizeAllConfigs(currGrid, res - currMove);
    } else {
//        gridResults[currGrid] = -1;
        memoizeAllConfigs(currGrid, -1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("/Users/jkeane/Downloads/test_data-4/shotcube/data/secret/big2.in");
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        bitset<49> grid;
        grid.reset();
        for (int j = 0; j < 7; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < 7; ++k) {
                if (line[k] == 'X') {
                    grid[j * 7 + k] = true;
                }
            }
        }
        cout << minimalGame(grid, 0) << endl;
//        gridResults.clear();
    }

    return 0;
}
