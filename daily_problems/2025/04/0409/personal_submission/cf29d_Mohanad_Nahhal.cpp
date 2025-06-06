/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector gr(n + 1, vector(0, 0));
    for (int i = 1; i < n; i ++) {
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

    vector sum(n + 1, 0), order(0, 0);
    vector ans(0, 0);
    int last = 1, x;

    while (cin >> x) order.push_back(x);
    order.push_back(1);

    for (auto x : order) {
        int lca = LCA(last, x), y = last;
        while (y != lca) {
            ans.push_back(st[y][0]);
            sum[y] ++;
            y = st[y][0];
        }
        y = x;
        vector rans(0, 0);
        while (y != lca) {
            rans.push_back(y);
            sum[y] ++;
            y = st[y][0];
        }
        while (rans.size()) {
            ans.push_back(rans.back());;
            rans.pop_back();
        }
        last = x;
    }

    for (int i = 2; i <= n; i ++) {
        if (sum[i] != 2) {
            cout << -1 << endl;
            return;
        }
    }

    cout << 1 << ' ';
    for (auto x : ans) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
