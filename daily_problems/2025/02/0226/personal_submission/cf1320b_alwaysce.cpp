#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
    */
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n), rev_path(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        rev_path[v].push_back(u);
        path[u].push_back(v);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (auto&x: p) { cin >> x; --x; }
    int t = p[k - 1];

    int inf = 1e9;
    vector<int> d(n, inf);
    d[t] = 0;

    queue<int> q;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v: rev_path[u]) {
            if (d[v] == inf) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    int mn = 0, mx = 0;
    for (int i = 0; i + 1 < k; i++) {
        int u = p[i], v = p[i + 1];
        if (d[u] <= d[v]) {
            ++mn;
            ++mx;
        } else {
            int cnt = 0;
            for (auto&x: path[u]) {
                if (d[x] < d[u]) {
                    ++cnt;
                }
            }
            // 存在w
            if (cnt > 1) {
                ++mx;
            }
        }
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}
