//
// Created by Jonny Keane on 5/27/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string puzzle[r];
    for (int i = 0; i < r; ++i) {
        cin >> puzzle[i];
    }
    map<string, pair<set<pair<int, int>>, pair<int, int>>> words; // name, filled, emptied -> want to have keys of sets of coordinates???
    // want a range array that I can just subtract from I'm thinking
    int clueNumber = 0, empties = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) { // for every char row-wise in puzzle
            if (puzzle[i][j] != '#') { // if not a blocked square
                // if constitutes a new clue
                if (j == 0 || puzzle[i][j - 1] == '#' || i == 0 || puzzle[i - 1][j] == '#') {
                    ++clueNumber; // increment clue number
                    if (j == 0 || puzzle[i][j - 1] == '#') { // across
                        set<pair<int, int>> coords;
                        int total = 0;
                        int filledTotal = 0;
                        int currJ = j;
                        while (currJ < c && puzzle[i][currJ] != '#') {
                            total += currJ - j + 1;
                            coords.insert(make_pair(i, currJ));
                            ++currJ;
                        } // see where this word goes and create total
                        --currJ;
                        for (int k = currJ; k >= j; --k) {
                            if (puzzle[i][k] != '.') {
                                filledTotal += currJ - k + 1;
                            }
                        } // add to the filled total
                        words[to_string(clueNumber) + "A"] = make_pair(coords, make_pair(filledTotal, total));
                    }
                    if (i == 0 || puzzle[i - 1][j] == '#') { // down
                        set<pair<int, int>> coords;
                        int total = 0;
                        int filledTotal = 0;
                        int currI = i;
                        while (currI < r && puzzle[currI][j] != '#') {
                            total += currI - i + 1;
                            coords.insert(make_pair(currI, j));
                            ++currI;
                        }
                        --currI;
                        for (int k = currI; k >= i; --k) {
                            if (puzzle[k][j] != '.') {
                                filledTotal += currI - k + 1;
                            }
                        }
                        words[to_string(clueNumber) + "D"] = make_pair(coords, make_pair(filledTotal, total));
                    }
                }
                if (puzzle[i][j] == '.') {
                    ++empties;
                }
            }
        }
    }
//    for (auto const& word: words) {
//        for (auto p: word.second.first) {
//            cout << "(" << p.first << "," << p.second << ") ";
//        }
//        cout << endl;
//        cout << word.first << " " << word.second.second.first << " " << word.second.second.second << endl;
//    }
    while (empties != 0) { // while not filled
        double max = -1; // calculate max that can be changed
        set<pair<int, int>> removals;
        string removalClue;
        for (auto& word: words) {
            double wordRatio = (double)(word.second.second.first) / (word.second.second.second);
            if (word.second.second.first != word.second.second.second && wordRatio >= max) {
                if (removalClue.empty() || wordRatio > max ||
                    word.first[word.first.n() - 1] < removalClue[removalClue.size() - 1] ||
                    (word.first[word.first.n() - 1] == removalClue[removalClue.size() - 1] && stoi(word.first.substr(0, word.first.n() - 1)) <
                                                                                              stoi(removalClue.substr(0, removalClue.size() - 1)))) { // checks if greater, if
//                    if (!removalClue.empty())
//                        cout << stoi(removalClue.substr(0, removalClue.n() - 1));
//                    cout << "*" << stoi(word.first.substr(0, word.first.n() - 1)) << endl;
                    removalClue = word.first;
                    removals = word.second.first;
                    max = wordRatio;
                }
            }
        }
        cout << removalClue << endl;
        for (pair<int, int> removal: removals) {
            for (auto& word: words) {
                if (word.second.first.count(removal) != 0 && puzzle[removal.first][removal.second] == '.') {
                    word.second.second.first += word.second.first.n() - distance(word.second.first.begin(), word.second.first.find(removal));
                }
            }
            if (puzzle[removal.first][removal.second] == '.') {
                --empties;
                puzzle[removal.first][removal.second] = '*';
            }
        }
//        for (int i = 0; i < r; ++i) {
//            cout << puzzle[i] << endl;
//        }
    }

    return 0;
}

