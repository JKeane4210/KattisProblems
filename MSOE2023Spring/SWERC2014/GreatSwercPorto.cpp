//
// Created by keysers on 5/7/23.
//

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define V vector
#define vi V<int>
#define pii pair<int, int>
#define graph V<vi>
#define wgraph V<V<pii>>
#define nl '\n'
using namespace std;

//char mappings[26];
bitset<10> nonzero;
vector<string> lines;
map<char, int> ind_mappings;
vector<vector<int>> line_vals;
int char_ind = 0;

int solve(bitset<10> & used, int ind, int max_len, vector<int> & mappings) {
    if (ind == char_ind) { // max_len is wrong
        int sum = 0;
        int res = 0;
        for (int i =0; i < line_vals.size(); ++i) {
            int val = 0;
            for (int j = 0; j < max_len; ++j){
                if (line_vals[i][j] == -1) continue;
                val += mappings[line_vals[i][j]];
                if (j != max_len - 1) val *= 10;
            }
            if (i != line_vals.size() - 1)
                sum += val;
            else
                res = val;
        }
        return sum == res;
    }
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        if (i == 0 && nonzero[ind]) continue;
        if (!used[i]) {
            used[i] = true;
            mappings[ind] = i;
            res += solve(used, ind + 1, max_len, mappings);
            mappings[ind] = -1;
            used[i] = false;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int max_len = 0;
    bitset<26> seen;
    for (int i = 0;i < n; ++i) {
        string line;
        cin >> line;
        max_len = max(max_len, (int)line.size());
        for (char c: line) {
            if (!seen[c - 'A']) {
                seen[c-'A'] = true;
                ind_mappings[c] = char_ind++;
            }
        }
        nonzero[ind_mappings[line[0]]] = true;
        lines.push_back(line);
    }

    for (int i = 0; i < n; ++i) {
        vector<int> line_map;
        for (int j = 0; j < max_len - lines[i].size(); ++j) line_map.push_back(-1);
        for (auto c: lines[i]) line_map.push_back(ind_mappings[c]);
        line_vals.push_back(line_map);
    }

    bitset<10> b;
    vector<int> v(char_ind, -1);
    cout << solve(b, 0, max_len, v) << endl;


    return 0;
}