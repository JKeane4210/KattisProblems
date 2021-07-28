//
// Created by Jonny Keane on 7/20/21.
//

#include <bits/stdc++.h>

#include <utility>

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

class Trie;
class Edge;

class Node {
public:
    bool isWord;
    bool canChoose;
    bool inSequence;
    int value;
    map<char, Node> conns;
    Node() : isWord(false), canChoose(false), inSequence(false), value(0) {}
    Node(bool isWord, bool canChoose, bool inSequence, int value) :
        isWord(isWord), canChoose(canChoose), inSequence(inSequence), value(value) {}
};

class Trie {
public:
    Node root;
    explicit Trie() : root(Node()) {}
    Node Add(const string& word, bool canChoose, bool inSequence, int value) {
        return Add(root, word, canChoose, inSequence, value);
    }

    Node Add(Node node, const string& word, bool canChoose, bool inSequence, int value) {
        if (word.size() == 1) {
            if (node.conns.find(word[0]) == node.conns.end()) {
                node.conns[word[0]] = Node(true, canChoose, inSequence, value);
            } else {
                node.conns[word[0]].isWord = true;
                node.conns[word[0]].canChoose = canChoose;
                node.conns[word[0]].inSequence = inSequence;
                node.conns[word[0]].value = value;
            }
            return node.conns[word[0]];
        } else {
            if (node.conns.find(word[0]) == node.conns.end()) {
                node.conns[word[0]] = Node();
            }
            return Add(node.conns[word[0]], word.substr(1), canChoose, inSequence, value);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    Node nodes[m];
    Trie trie;
    bitset<10001> inSubsequence;
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        inSubsequence[v] = true;
        nodes[i] = trie.Add(to_string(v), i == 0, true, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (inSubsequence[i]) continue;
        trie.Add(to_string(i), true, false, i);
    }
    int curr = 0;

    return 0;
}