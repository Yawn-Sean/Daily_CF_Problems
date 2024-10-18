#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> s(p + 1);
    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }
    vector<string> g(n);
    queue<pii> boundary[10];
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '.' && g[i][j] != '#') {
                int pid = g[i][j] - '0';
                boundary[pid].push({i, j});
            }
        }
    }
    auto check = [&](int r, int c) -> bool {
        if (r < 0 || r >= n || c < 0 || c >= m) return false;
        if (g[r][c] == '.') return true;
        return false;
    };
    while (true) {
        bool has_move = false;
        for (int i = 1; i <= p; i++) {
            queue<pair<pii, int>> que;
            while (!boundary[i].empty()) {
                pii tmp = boundary[i].front();
                boundary[i].pop();
                que.push({tmp, 0});
            }
            set<pii> vis;
            while (!que.empty()) {
                auto top = que.front(); que.pop();
                auto [r, c] = top.first;
                vis.insert({r, c});
                int dis = top.second;
                g[r][c] = '0' + i;
                if (dis == s[i]) {
                    boundary[i].push({r, c});
                    continue;
                }
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (check(nr, nc) && vis.find({nr, nc}) == vis.end()) {
                        vis.insert({nr, nc});
                        que.push(make_pair(make_pair(nr, nc), dis + 1));
                    }
                }
            }
            has_move |= (!boundary[i].empty());
        }
        if (!has_move) break;
    }
    vector<int> cnt(p + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '#' && g[i][j] != '.') {
                int pid = g[i][j] - '0';
                cnt[pid]++;
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
