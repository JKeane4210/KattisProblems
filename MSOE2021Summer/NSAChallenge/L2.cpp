//
// Created by Jonny Keane on 8/5/21.
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

class DijkstrasStep {
public:
    int nodeID;
    int totalDist; // store it and then divide by 2 at the end
    string curr;

    /// Initializes node ID and total distance
    /// \param nodeID Node ID
    /// \param totalDist Total distance
    DijkstrasStep(int nodeID, int totalDist, string curr) : nodeID(nodeID), totalDist(totalDist), curr(curr) {};

    /// Comparator of DijkstrasSteps for use in priority queue
    /// \param a A step
    /// \param b Another step
    /// \return If a is "lesser"
    /// \tparam The type of the weight (int/double)
    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, string> ids;
    map<int, vector<int>> conns;
    map<int, int> shortestPaths;
    map<int, int> parents;

    ifstream cin("/Users/jkeane/Downloads/Student Download Pack/L1/graph.txt");
    string line;
    getline(cin, line);
    while(!line.empty())
    {
        string num_s = line.substr(line.find('(') + 1, line.find(',') - line.find('(') - 1);
        int node = stoi(num_s);
        char id = line[line.find(',') + 1];
//        cout << node << " " << id << endl;
        ids[node] = id;
        shortestPaths[node] = INT_MAX;
        getline(cin, line);
    }
    getline(cin, line);
    while(!line.empty())
    {
        string a_s = line.substr(line.find('(') + 1, line.find(" : ") - line.find('(') - 1);
        string b_s = line.substr(line.find(" : ") + 3, line.find(')') - line.find(" : ") - 3);
        int a = stoi(a_s);
        int b = stoi(b_s);
//        cout << a << " " << b << endl;
        if (conns.find(a) == conns.end()) {
            conns[a] = vector<int>();
        }
        if (conns.find(b) == conns.end()) {
            conns[b] = vector<int>();
        }
        conns[a].emplace_back(b);
        conns[b].emplace_back(a);
        getline(cin, line);
    }


    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(7022, 0, ids[7022]));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.totalDist >= shortestPaths[top.nodeID]) continue;
        shortestPaths[top.nodeID] = top.totalDist;
        if (top.nodeID == 7795) {
            cout << top.curr << endl;
        }
        for (int conn: conns[top.nodeID]) {
            parents[conn] = top.nodeID;
            pq.push(DijkstrasStep(conn, top.totalDist + 1, top.curr + ids[conn]));
        }
    }
//    cout << shortestPaths[7795] << endl;
 
    return 0;
}