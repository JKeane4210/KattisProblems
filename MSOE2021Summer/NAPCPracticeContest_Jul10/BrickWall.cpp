//
// Created by Jonny Keane on 7/10/21.
//

#include <bits/stdc++.h>

#define ll long long

#define V vector
#define vi V<int>
#define pii pair<int, int>
#define pll pair<ll,ll>

using namespace std;

set<int> layer;
vector<int> threePoints;

bool canBuild(int sum, int length, int c1, int c2, int c3, int threes, int threeInd) {
    if (threes != 0 && length > threePoints[threeInd]) {
        --threes;
        threeInd++;
    }
    if (c3 < threes) return false;
    if (length > sum) return false;
    if (c1 == -1 || c2 == -1 || c3 == -1) return false;
    if (length == sum) return true;
    if (layer.count(length) != 0) return false;
    if (canBuild(sum, length + 1, c1 - 1, c2, c3, threes, threeInd)) {
        return true;
    } else if (canBuild(sum, length + 2, c1, c2 - 1, c3, threes, threeInd)) {
        return true;
    } else {
        return canBuild(sum, length + 3, c1, c2, c3 - 1, threes, threeInd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, c1, c2, c3;
    cin >> N >> c1 >> c2 >> c3;
    int sum = 0;
    int threes = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (i != 0 && i != N - 1 && x == 1) {
            ++threes;
            threePoints.push_back(sum);
        }
        sum += x;
        layer.insert(sum);
    }

    if (c1 + c2 * 2 + c3 * 3 >= sum && canBuild(sum, 0, c1, c2, c3, threes, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}