#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 9901;
const int inf = 0x3f3f3f3f;
const long long INF = LLONG_MAX;
//#define int long long

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int vis[1005][1005][12];

void solve() {
    int n, m;
    cin >> n >> m;
    int s_i, s_j;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                s_i = i, s_j = j;
            }
        }
    }
    bool flag = false;
    auto dfs = [&](this auto&& self, int turn, int dire, int i, int j) -> void {
        int index = turn * 4 + (dire + 1);
        if (turn > 2 || vis[i][j][index]) return;
        vis[i][j][index] = true;
        if (g[i][j] == 'T') {
            flag = true;
            return;
        }
        for (int d = 0; d < 4; ++d) {
            int dx = dir[d].first, dy = dir[d].second;
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*') {
                if (dire != -1 && d != dire) {
                    self(turn + 1, d, x, y);
                } else {
                    self(turn, d, x, y);
                }
            }
        }
    };
    dfs(0, -1, s_i, s_j);
    cout << (flag ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}