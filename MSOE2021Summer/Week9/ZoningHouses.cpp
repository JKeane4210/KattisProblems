//
// Created by Jonny Keane on 7/24/21.
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

//
// Created by Jonny Keane on 7/17/21.
//

class MaxSparseTable { // with indexes
private:
    int* data;
    int size;
    int levels;
public:
    MaxSparseTable(int size) : size(size) {
        levels = (int)floor(log2(size));
        data = (int *)malloc(size * (levels + 2) * sizeof(int));
        memset(data, 0, size * (levels + 2) * sizeof(int));
        for (int i = 0; i < size; ++i) {
            data[size + i] = i;
        }
    }

    int& operator[] (int index) {
        return data[index];
    }

    void populate() {
        int delta = 1;
        for (int level = 2; level <= levels + 1; ++level) { // extra level because of indices
            for (int i = 0; i < size - delta; ++i) {
                data[size * level + i] = data[data[size * (level - 1) + i]] > data[data[size * (level - 1) + i + delta]] ?
                                         data[size * (level - 1) + i] : data[size * (level - 1) + i + delta];
            }
            delta <<= 1;
        }
    }

    int maxRange(int start, int end, bool giveIndex = true) {
        if (start > end) return maxRange(end, start, giveIndex);
        int level = (int)log2(end - start + 1);
        int pow = 1 << level;
        if (giveIndex) {
            return data[data[(level + 1) * size + start]] > data[data[(level + 1) * size + end - pow + 1]] ?
                data[(level + 1) * size + start] : data[(level + 1) * size + end - pow + 1];
        } else {
            return max(data[data[(level + 1) * size + start]], data[data[(level + 1) * size + end - pow + 1]]);
        }
    }

    int maxRange(int start, int end, int exclude, bool giveIndex = true) {
        if (exclude == start)
            return maxRange(start + 1, end, giveIndex);
        if (exclude == end)
            return maxRange(start, end - 1, giveIndex);
        return maxRange(start, exclude - 1, false) > maxRange(exclude + 1, end, false) ?
            maxRange(start, exclude - 1, giveIndex) : maxRange(exclude + 1, end, giveIndex);
    }

    string toString() {
        string res;
        for (int i = 1; i < levels + 2; ++i) {
            for (int j = 0; j < size; ++j) {
                res += to_string(data[i * size + j]) + "(" + to_string(data[data[i * size + j]]) + ") ";
            }
            res += "\n";
        }
        return res;
    }
};

class MinSparseTable { // with indexes
private:
    int* data;
    int size;
    int levels;
public:
    MinSparseTable(int size) : size(size) {
        levels = (int)floor(log2(size));
        data = (int *)malloc(size * (levels + 2) * sizeof(int));
        memset(data, 0, size * (levels + 2) * sizeof(int));
        for (int i = 0; i < size; ++i) {
            data[size + i] = i;
        }
    }

    int& operator[] (int index) {
        return data[index];
    }

    void populate() {
        int delta = 1;
        for (int level = 2; level <= levels + 1; ++level) { // extra level because of indices
            for (int i = 0; i < size - delta; ++i) {
                data[size * level + i] = data[data[size * (level - 1) + i]] < data[data[size * (level - 1) + i + delta]] ?
                                         data[size * (level - 1) + i] : data[size * (level - 1) + i + delta];
            }
            delta <<= 1;
        }
    }

    int minRange(int start, int end, bool giveIndex = true) {
        if (start > end) return minRange(end, start, giveIndex);
        int level = (int)floor(log2(end - start + 1));
        int pow = 1 << level;
        if (giveIndex) {
            return data[data[(level + 1) * size + start]] < data[data[(level + 1) * size + end - pow + 1]] ?
                   data[(level + 1) * size + start] : data[(level + 1) * size + end - pow + 1];
        } else {
            return min(data[data[(level + 1) * size + start]], data[data[(level + 1) * size + end - pow + 1]]);
        }
    }

    int minRange(int start, int end, int exclude, bool giveIndex = true) {
        if (exclude == start)
            return minRange(start + 1, end, giveIndex);
        if (exclude == end)
            return minRange(start, end - 1, giveIndex);
        return minRange(start, exclude - 1, false) < minRange(exclude + 1, end, false) ?
               minRange(start, exclude - 1, giveIndex) : minRange(exclude + 1, end, giveIndex);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    MinSparseTable xMinSparse(n);
    MinSparseTable yMinSparse(n);
    MaxSparseTable xMaxSparse(n);
    MaxSparseTable yMaxSparse(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xMinSparse[i] = x;
        xMaxSparse[i] = x;
        yMinSparse[i] = y;
        yMaxSparse[i] = y;
    }
    xMinSparse.populate();
    yMinSparse.populate();
    xMaxSparse.populate();
    yMaxSparse.populate();
//    cout << xMaxSparse.toString() << endl;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int min_ = INT_MAX;
        int removals[4];
        removals[0] = xMinSparse.minRange(a, b);
        removals[1] = xMaxSparse.maxRange(a, b);
        removals[2] = yMinSparse.minRange(a, b);
        removals[3] = yMaxSparse.maxRange(a, b);
        for (int & removal: removals) {
            int right = xMaxSparse.maxRange(a, b, removal, false);
            int left = xMinSparse.minRange(a, b, removal, false);
            int top = yMaxSparse.maxRange(a, b, removal, false);
            int bottom = yMinSparse.minRange(a, b, removal, false);
            int horizontal = xMaxSparse.maxRange(a, b, removal, false) - xMinSparse.minRange(a, b, removal, false);
            int vertical = yMaxSparse.maxRange(a, b, removal, false) - yMinSparse.minRange(a, b, removal, false);
            min_ = min(max(horizontal, vertical), min_);
        }
        cout << min_ << endl;
    }
    return 0;
}