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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

//    ifstream cin("/Users/jkeane/Desktop/3-3.in.txt");
    bitset<100000> visited;
    visited.reset();
    int N, s, t;
    cin >> N >> s >> t;
    pair<bool, vector<int>> flights[N];
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        int n;
        cin >> n;
        vector<int> portFlights;
        for (int j = 0; j < n; ++j) {
            int dest;
            cin >> dest;
            portFlights.push_back(dest);
        }
        sort(portFlights.begin(), portFlights.end());
        flights[i] = make_pair(c == 'N', portFlights);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    visited[s] = true;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (flights[top.first].first) {
            for (int dest: flights[top.first].second) {
                if (!visited[dest]) {
                    if (dest == t) {
                        cout << top.second + 1 << endl;
                        return 0;
                    }
                    visited[dest] = true;
                    q.push(make_pair(dest, top.second + 1));
                }
            }
        } else {
            auto it = flights[top.first].second.begin();
            for (int i = 0; i < N; ++i) {
                if (it != flights[top.first].second.end() && i == *it) {
                    ++it;
                    continue;
                }
                if (i == top.first) continue;
                if (!visited[i]) {
                    if (i == t) {
                        cout << top.second + 1 << endl;
                        return 0;
                    }
                    visited[i] = true;
                    q.push(make_pair(i, top.second + 1));
                }
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}