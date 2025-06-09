/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector gr(n + 1, vector(0, 0));
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    vector st(n + 1, vector(20, 0));
    vector depth(n + 1, 0);

    function<void(int, int)> dfs = [&] (int x, int p) {
        st[x][0] = p;
        depth[x] = depth[p] + 1;
        for (auto u : gr[x]) {
            if (u == p) continue;
            dfs(u, x);
        }
    };
    dfs(1, 0);

    for (int j = 1; j < 20; j ++) {
        for (int i = 1; i <= n; i ++) st[i][j] = st[st[i][j - 1]][j - 1];
    }

    auto LCA = [&] (int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        int dif = depth[y] - depth[x];
        for (int i = 0, pw = 1; i < 20; i ++, pw *= 2) {
            if ((dif & pw)) y = st[y][i];
        }

        if (y == x) return x;
        for (int i = 19; i >= 0; i --) {
            if (st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }
        return st[x][0];
    };

    auto dis = [&] (int x, int y) {
        int lca = LCA(x, y);
        return depth[x] + depth[y] - 2 * depth[lca];
    };

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int lca = LCA(x, i);
        if (dis(1, lca) > dis(x, lca)) ans = max(ans, dis(1, i));
    }

    cout << ans * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
