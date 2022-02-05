//
// Created by Jonny Keane on 2/5/22.
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


const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    int w, h;
    cin >> h >> w;
    V<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    set<string> needed_prefs;
    set<string> words;
    set<string> found;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.insert(s);
        for (int j = 1; j <= s.length(); ++j) {
            needed_prefs.insert(s.substr(0, j));
        }
    }
    queue<pair<string, pii>> q;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            string start(1, grid[i][j]);
            if (words.find(start) != words.end()) {
                found.insert(start);
            }
            q.push(mp(start, mp(i, j)));
        }
    }
    set<string> all;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        all.insert(top.first);
        if (top.first.size() >= 10) continue;
        for (auto delta: deltas) {
            int nr = top.second.first + delta[0];
            int nc = top.second.second + delta[1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                string step = top.first + string(1, grid[nr][nc]);
                if (needed_prefs.find(step) == needed_prefs.end()) continue;
                if (words.find(step) != words.end()) {
                    found.insert(step);
                }
                q.push(mp(top.first + string(1, grid[nr][nc]), mp(nr, nc)));
            }
        }
    }
    cout << found.size() << endl;

    struct TrieNode *root = getNode();
    insert(root, )

    return 0;
}