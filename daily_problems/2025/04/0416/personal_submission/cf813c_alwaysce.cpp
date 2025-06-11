#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*
        bob能够到达节点的最深叶子是u
        那么alice的步数就是1-u的距离
        总回合数就是2 * dis
    */

    int n, x;
    cin >> n >> x;
    --x;
    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> d1(n, 1e9);
    d1[0] = 0;
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : path[u]) {
            if (v == fa) continue;
            d1[v] = d1[u] + 1;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);

    vector<int> d2(n, 1e9);
    d2[x] = 0;
    queue<int> q;
    q.push(x);
    int ans = d1[x];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : path[u]) {
            if (d2[v] != 1e9) continue;
            d2[v] = d2[u] + 1;
            if (d2[v] < d1[v]) {
                ans = max(ans, d1[v]);
            }
            q.push(v);
        }
    }
    cout << 2 * ans << '\n';
    return 0;
}
