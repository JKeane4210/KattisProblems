//
// Created by Jonny Keane on 7/1/21.
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

struct File {
public:
    int r;
    int c;
    bool remove;
    File(int r, int c, bool remove) : r(r), c(c), remove(remove) {}

    bool operator==(const File &other) const
    { return (r == other.r && c == other.c); }
};

namespace std {
    template <>
    struct hash<File> {
        size_t operator()(const File& f) const
        {
            return ((hash<int>()(f.r) ^ (hash<int>()(f.c) << 1)) >> 1);
        }
    };
}

bool compRow(File a, File b) {
    return a.r < b.r;
}

bool compCol(File a, File b) {
    return a.c < b.c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nr, nc, n, m;
    cin >> nr >> nc >> n >> m;
    vector<File> filesHorizontal;
    vector<File> filesVertical;
    int moveNeeded = 0;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        File f(r + 7, c + 4, true);
        if (f.r >= nr || f.c >= nc) {
            ++moveNeeded;
        } else {
            filesHorizontal.emplace_back(f);
            filesVertical.emplace_back(f);
        }
    }
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        File f(r + 7, c + 4, false);
        filesHorizontal.emplace_back(f);
        filesVertical.emplace_back(f);
    }
    sort(filesVertical.begin(), filesVertical.end(), compRow);
    sort(filesHorizontal.begin(), filesHorizontal.end(), compCol);

    int min_ = INT_MAX;
    int left = 0, leftVal = -1;
    unordered_set<File> leftGood, leftBad;
    while (left < filesHorizontal.size() && leftGood.size() < min_) {                            // for every left configuration
        if (filesHorizontal[left].c > leftVal) { // if have new left move
            leftVal = filesHorizontal[left].c;   // update left val
            int right = filesHorizontal.size() - 1, rightVal = INT_MAX;
            unordered_set<File> rightGood(leftGood), rightBad(leftBad);
            while (left <= right && rightGood.size() < min_) {                               // for every right configuration
                if (filesHorizontal[right].c < rightVal) {  // if have new right move
                    rightVal = filesHorizontal[right].c;    // update right val
                    int top = 0, topVal = -1;
                    unordered_set<File> topGood(rightGood), topBad(rightBad);
                    while (top < filesVertical.size() && topGood.size() < min_) {                        // for every top configuration
                        if (filesVertical[top].r > topVal) { // if have new top move
                            topVal = filesVertical[top].r;   // update top val
                            int bottom = filesVertical.size() - 1, bottomVal = INT_MAX;
                            unordered_set<File> bottomGood(topGood), bottomBad(topBad);
                            while (top <= bottom && bottomGood.size() < min_) {                              // for every bottom configuration
                                if (filesVertical[bottom].r < bottomVal) {   // if have new bottom val
                                    bottomVal = filesVertical[bottom].r;     // update bottom val
                                    int boxRes = bottomGood.size() + m - bottomBad.size();
                                    min_ = min(min_, boxRes);
                                }
                                if (filesVertical[bottom].remove) {
                                    bottomGood.insert(filesVertical[bottom]);
                                } else {
                                    bottomBad.insert(filesVertical[bottom]);
                                }
                                --bottom;
                            }
                        }
                        if (filesVertical[top].remove) {
                            topGood.insert(filesVertical[top]);
                        } else {
                            topBad.insert(filesVertical[top]);
                        } // update top count
                        ++top;
                    }
                }
                if (filesHorizontal[right].remove) {
                    rightGood.insert(filesHorizontal[right]);
                } else {
                    rightBad.insert(filesHorizontal[right]);
                } // update right count
                --right;
            }
        }
        if (filesHorizontal[left].remove) {
            leftGood.insert(filesHorizontal[left]);
        } else {
            leftBad.insert(filesHorizontal[left]);
        } // update left count
        ++left;
    }

    cout << min_ + moveNeeded << endl;

    return 0;
}