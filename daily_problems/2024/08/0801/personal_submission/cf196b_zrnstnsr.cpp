#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int r, c;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        size_t pos = grid[i].find_first_of('S');
        if (pos != string::npos) c = pos, r = i;
    }
    vector<pair<int, int>> vis(n * m, {0x3f3f3f3f, 0x3f3f3f3f});
    queue<tuple<int, int, int, int>> q;
    q.push({r, c, 0, 0});
    vis[r*m+c] = {0, 0};
    bool suc = false;
    while (!q.empty()) {
        auto [x, y, dx, dy] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int rr = (x + n + d[i][0]) % n, cc = (y + m + d[i][1]) % m;
            if (grid[rr][cc] != '#') {
                int v = rr * m + cc;
                int dr = dx + rr - x - d[i][0], dc = dy + cc - y - d[i][1];
                if (vis[v].first == 0x3f3f3f3f) {
                    vis[v] = {dr, dc};
                    q.push({rr, cc, dr, dc});
                } else if (vis[v].first != dr || vis[v].second != dc) {
                    suc = true;
                    goto res;
                }
            }
        }
    }
    res: cout << (suc ? "Yes\n" : "No\n");
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
