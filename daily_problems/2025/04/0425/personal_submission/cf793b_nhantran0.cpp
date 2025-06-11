/**
 * https://codeforces.com/problemset/problem/793/B
 * B. Igor and his way to work
 * Solver: nhant
 * 2025-04-25 18:31:58
 * https://codeforces.com/problemset/submission/793/317160973, 124 ms, 14400 KB
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    const int MAX_TURN = 4;
    const int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<array<int,4>>> turn(n, vector<array<int,4>>(m, array<int,4>()));
    int sr = -1, sc = -1, tr = -1, tc = -1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            fill(turn[i][j].begin(), turn[i][j].end(), MAX_TURN);
            if (s[i][j] == 'S') {
                sr = i;
                sc = j;
            } else if (s[i][j] == 'T') {
                tr = i;
                tc = j;
            }
        }
    }
    queue<array<int,3>> q;
    for (int i = 0; i < 4; i++) {
        q.push({sr, sc, i});
        turn[sr][sc][i] = 0;
    }
    bool yes = false;
    while (q.size() > 0) {
        array<int,3> u = q.front();
        q.pop();
        int r = u[0], c = u[1], d = u[2];
        if (r == tr && c == tc) {
            yes = true;
            break;
        }
        if (turn[r][c][d] < 2) {
            for (int i = 0; i < 4; i++) {
                if (i == d) continue;
                if (turn[r][c][d] + 1 < turn[r][c][i]) {
                    turn[r][c][i] = turn[r][c][d] + 1;
                    q.push({r, c, i});
                }
            }
        }
        int nr = r + dirs[d][0], nc = c + dirs[d][1];
        if (0 <= nr && nr < n && 0 <= nc && nc < m && s[nr][nc] != '*' && turn[r][c][d] < turn[nr][nc][d]) {
            turn[nr][nc][d] = turn[r][c][d];
            q.push({nr, nc, d});
        }
    }
    cout << (yes ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
