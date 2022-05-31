//
// Created by keanej on 5/30/2022.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int wins[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
};

void simulate_games(const string & game, map<string, pii> & scores, char next_move) {
    for (auto win: wins) {
        if (game[win[0]] != '.' && game[win[0]] == game[win[1]] && game[win[1]] == game[win[2]]) {
            scores[game] = mp(game[win[0]] == 'X' ? 1 : 0, game[win[0]] == 'O' ? 1 : 0);
            return;
        }
    }
    pii score = mp(0, 0);
    for (int i = 0; i < 9; ++i) {
        if (game[i] == '.') {
            string next(game);
            next[i] = next_move;
            simulate_games(next, scores, next_move == 'X' ? 'O' : 'X');
            score.first += scores[next].first;
            score.second += scores[next].second;
        }
    }
    scores[game] = score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, pii> scores;
    simulate_games(".........", scores, 'X');

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string game;
        cin >> game;
        if (scores.find(game) == scores.end()) {
            cout << "-1 -1" << endl;
        } else {
            pii res = scores[game];
            cout << res.first << " " << res.second << endl;
        }
    }

    return 0;
}