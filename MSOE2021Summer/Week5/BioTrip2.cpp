//
// Created by Jonny Keane on 6/26/21.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

template<typename T>
class Arr3D {
public:
    int *dim;
    Arr3D(int x, int y, int z) {
        dim = new int[3];
        dim[0] = x; dim[1] = y; dim[2] = z;
        data = (T *) malloc(x * y * z * sizeof(T));
    }
    T& operator() (int x, int y, int z) {
        return data[x + dim[0] * (y + dim[1] * z)];
    }
private:
    T* data;
};

int leftAngleDelta(int in, int out) {
    if (out >= in) {
        return out - in;
    } else {
        return 360 - in + out;
    }
}

int rightAngleDelta(int in, int out) {
    if (in >= out) {
        return in - out;
    } else {
        return 360 - out + in;
    }
}

class DijkstrasStep {
public:
    int nodeID;
    int totalDist;
    bool headingThere;
    int incomingAngleInd;

    DijkstrasStep(int nodeID, int totalDist, bool headingThere, int incomingAngleInd) :
        nodeID(nodeID), totalDist(totalDist), headingThere(headingThere), incomingAngleInd(incomingAngleInd) {};

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

class Dijkstras {
public:
    Arr3D<int> graph; // nodeID, totalDist, incomingAngle
    bool *visitedEdge;
    int *shortestPathTable;
    int numNodes;

    Dijkstras(Arr3D<int> graph, int numNodes) : graph(graph), numNodes(numNodes) {
        shortestPathTable = new int[2 * numNodes];
        visitedEdge = (bool *) malloc(2 * numNodes * 5 * sizeof(bool));
        for (int i = 0; i < 2 * numNodes; ++i) { shortestPathTable[i] = INT_MAX; }
        for (int i = 0; i < numNodes * 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                visitedEdge[i * 5 + j] = false;
            }
        }
    }

    void dijkstras(int start, int dest, int leftAngle, int rightAngle) {
        priority_queue<DijkstrasStep> pq;
        pq.push(DijkstrasStep(start, 0, true, -1));
        //MAIN LOOP
        while (!pq.empty()) {
            DijkstrasStep shortest = pq.top();
            pq.pop();
            int nodeLoc = shortest.headingThere ? shortest.nodeID : numNodes + shortest.nodeID;
            if (shortest.incomingAngleInd != -1 && visitedEdge[nodeLoc * 5 + shortest.incomingAngleInd]) {
                continue;
            }
            visitedEdge[nodeLoc * 5 + shortest.incomingAngleInd] = true;
            shortestPathTable[nodeLoc] = min(shortestPathTable[nodeLoc], shortest.totalDist);
            for (int i = 0; i < 5; ++i) {
                if (graph(shortest.nodeID, i, 0) == -1) break;
                if (shortest.incomingAngleInd == -1 ||
                    leftAngleDelta((graph(shortest.nodeID, shortest.incomingAngleInd, 2) + 180) % 360, graph(shortest.nodeID,i,2)) <= leftAngle ||
                    rightAngleDelta((graph(shortest.nodeID, shortest.incomingAngleInd, 2) + 180) % 360, graph(shortest.nodeID,i,2)) <= rightAngle) {
                    pq.push(DijkstrasStep(graph(shortest.nodeID,i,0),
                                            shortest.totalDist + graph(shortest.nodeID,i,1),
                                        shortest.headingThere && (shortest.nodeID != dest),
                                     graph(shortest.nodeID, i, 3)));
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, a_1, a_2;
    cin >> n >> d >> a_1 >> a_2;
    Arr3D<int> graph(n, 5, 4);
    // for each connection in matrix (at IN_ANGLE_IND): [DEST, TIME, ANGLE, OUT_ANGLE_IND]
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int d_j, t_j, a_j;
            cin >> d_j >> t_j >> a_j;
            graph(i,j,0) = d_j - 1;
            graph(i,j,1) = t_j;
            graph(i,j,2) = a_j;
            if (i > d_j - 1) {
                for (int k = 0; k < 5; ++k) {
                    int test = graph(d_j - 1,k,0);
                    if (graph(d_j - 1,k,0) == i) {
                        graph(d_j - 1,k, 3) = j;
                        graph(i,j,3) = k;
                        break;
                    }
                }
            }
        }
        if (m < 5) {
            graph(i, m,0) = -1;
        }
    }

    Dijkstras dij(graph, n);
    dij.dijkstras(0, d - 1, a_1, a_2);
    if (dij.shortestPathTable[n] != INT_MAX) {
        cout << dij.shortestPathTable[n] << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}