#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n);
    vector<vector<int>> path(n);
    for (int i = 1; i < n; i ++) {
        cin >> parent[i];
        parent[i] --;
        path[parent[i]].emplace_back(i);
    }

    vector<int> depth(n), order, stk = {0};
    while (stk.size()) {
        int u = stk.back();
        stk.pop_back();
        order.emplace_back(u);
        for (auto &v: path[u]) {
            depth[v] = depth[u] + 1;
            stk.emplace_back(v);
        }
    }

    vector<int> size(n, 1), chains(n);
    iota(chains.begin(), chains.end(), 0);

    for (int i = n - 1; i > 0; i --)
        size[parent[order[i]]] += size[order[i]];

    for (auto &u: order) {
        if (path[u].size()) {
            int mx = -1;
            for (auto &v: path[u]) {
                if (mx == -1 || size[v] >= size[mx])
                    mx = v;
            }
            chains[mx] = chains[u];
        }
    }

    function<int(int, int)> lca = [&] (int u, int v) -> int {
        while (chains[u] != chains[v]) {
            if (depth[chains[u]] < depth[chains[v]])
                v = parent[chains[v]];
            else
                u = parent[chains[u]];
        }
        return (depth[u] < depth[v] ? u : v);
    };

    function<int(int, int)> dis = [&] (int u, int v) -> int {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    };

    while (q --) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --, c --;
        int ans = 0, mi = n;

        int x;
        x = dis(a, b);
        ans += x, mi = min(mi, x);
        x = dis(b, c);
        ans += x, mi = min(mi, x);
        x = dis(a, c);
        ans += x, mi = min(mi, x);

        cout << ans / 2 - mi + 1 << '\n';
    }

    return 0;
}