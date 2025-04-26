/**
 * https://codeforces.com/problemset/problem/616/C
 * C. The Labyrinth
 * Solver: nhant
 * 2025-04-26 15:43:35
 * https://codeforces.com/problemset/submission/616/317275859, 93 ms, 1500 KB
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> d;
int get(int x) {
    return d[x] < 0 ? x : (d[x] = get(d[x]));
}
bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (-d[x] < -d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
}

void solve() {
    const int dirs[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int n, m;
    cin >> n >> m;
    d = vector<int>(n * m);
    fill(d.begin(), d.end(), -1);
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (s[r][c] == '*') continue;
            int x = r * m + c;
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k][0], nc = c + dirs[k][1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || s[nr][nc] == '*') continue;
                unite(x, nr * m + nc);
            }
        }
    }
    string res(m, '.');
    vector<int> had(4, -1);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (s[r][c] == '.') {
                res[c] = '.';
                continue;
            }
            fill(had.begin(), had.end(), -1);
            int sz = 1, i = 0;
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k][0], nc = c + dirs[k][1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || s[nr][nc] != '.') continue;
                int px = get(nr * m + nc);
                bool dup = false;
                for (int j = i - 1; j >= 0; j--) {
                    if (px == had[j]) {
                        dup = true;
                        break;
                    }
                }
                if (!dup) {
                    sz += -d[px];
                    had[i++] = px;
                }
            }
            res[c] = (char) ('0' + (sz % 10));
        }
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
