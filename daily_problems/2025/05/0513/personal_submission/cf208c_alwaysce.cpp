#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> d1(n, inf), d2(n, inf);
    vector<i64> cnt1(n, 0), cnt2(n, 0);

    auto bfs = [&](int start, vector<int>& dis, vector<i64>& cnt) {
        queue<int> q;
        q.push(start);
        dis[start] = 0;
        cnt[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : path[u]) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    cnt[v] = cnt[u];
                    q.push(v);
                } else if (dis[v] == dis[u] + 1) {
                    cnt[v] += cnt[u];
                }
            }
        }
    };

    bfs(0, d1, cnt1);
    bfs(n - 1, d2, cnt2);
    i64 ans = 0;
    int target = d1[n - 1];
    for (int u = 0; u < n; u++) {
        if (d1[u] + d2[u] == target) {
            i64 base = (u == 0 || u == n - 1) ? 1 : 2;
            ans = max(ans, base * cnt1[u] * cnt2[u]);
        }
    }
    // cout << ans << ' ' << cnt1[n - 1] << '\n';
    long double tot = 1.0 * ans / cnt1[n - 1];
    cout << fixed << setprecision(10) << tot << '\n';
    return 0;
}
