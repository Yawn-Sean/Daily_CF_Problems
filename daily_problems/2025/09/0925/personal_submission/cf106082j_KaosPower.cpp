#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);
    for (auto &[x, y]: pts) cin >> x >> y;

    vector<int> vis(n, 0), prev(n, -1);
    long long inf = 1e15;
    vector<long long> cur_mi(n, inf);

    int cur = 0;
    vis[cur] = 1, cur_mi[cur] = 0;

    auto dis = [&] (int i, int j) -> long long {
        return 1ll * (pts[i].first - pts[j].first) * (pts[i].first - pts[j].first) +
               1ll * (pts[i].second - pts[j].second) * (pts[i].second - pts[j].second);
    };

    vector<vector<pair<int, long long>>> path(n);

    for (int i = 0; i < n - 1; i ++) {
        int ncur = -1;
        for (int j = 0; j < n; j ++) {
            if (!vis[j]) {
                long long nd = dis(cur, j);
                if (nd < cur_mi[j]) {
                    cur_mi[j] = nd;
                    prev[j] = cur;
                }
                if (ncur == -1 || cur_mi[j] < cur_mi[ncur])
                    ncur = j;
            }
        }

        cur = ncur;
        vis[cur] = 1;
        path[cur].emplace_back(prev[cur], cur_mi[cur]);
        path[prev[cur]].emplace_back(cur, cur_mi[cur]);
    }

    vector<vector<long long>> ans(n, vector<long long>(n));

    auto dfs = [&] (auto &self, int start, int u, int p, long long cur) -> void {
        ans[start][u] = cur;
        for (auto &[v, w]: path[u]) {
            if (v != p) {
                self(self, start, v, u, max(cur, w));
            }
        }
    };

    for (int i = 0; i < n; i ++)
        dfs(dfs, i, i, -1, 0);

    int q;
    cin >> q;

    cout << fixed << setprecision(12);
    while (q --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        cout << sqrtl(ans[u][v]) << '\n';
    }

    return 0;
}
