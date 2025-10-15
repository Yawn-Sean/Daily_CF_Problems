#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> path(n);
    vector<int> parent_eid(n);
    vector<int> us(n - 1), vs(n - 1), ts(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> us[i] >> vs[i] >> ts[i];
        us[i]--, vs[i]--;
        path[us[i]].push_back(i); // store edge id
        path[vs[i]].push_back(i);
    }

    vector<int> dep(n), dfs_order;
    vector<vector<int>> pa(20, vector<int>(n, -1));

    function<void(int,int)> dfs = [&](int u, int p) {
        dfs_order.push_back(u);
        for (auto& eid : path[u]) {
            int v = us[eid] + vs[eid] - u; // find the other vertex of the edge
            if (v == p) continue;
            parent_eid[v] = eid;
            dep[v] = dep[u] + 1;
            pa[0][v] = u; // parent of v is u
            dfs(v, u);
        }
    };

    dfs(0, -1);
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            int p = pa[j - 1][i];
            if (p != -1) {
                pa[j][i] = pa[j - 1][p];
            }
        }
    }

    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int diff = dep[u] - dep[v];
        for (int j = 0; j < 20; j++) {
            if (diff & (1 << j)) {
                u = pa[j][u];
            }
        }

        if (u == v) return u;
        
        for (int j = 19; j >= 0; j--) {
            if (pa[j][u] != pa[j][v]) {
                u = pa[j][u];
                v = pa[j][v];
            }
        }

        return pa[0][u];
    };

    int k;
    cin >> k;

    vector<i64> pw2(k + 1, 0);
    pw2[0] = 1;
    for (int i = 1; i <= k; i++) {
        pw2[i] = (pw2[i - 1] * 2) % mod;
    }

    int u = 0;
    vector<int> up(n), down(n);
    while (k--) {
        int v;
        cin >> v;
        --v;

        int l = lca(u, v);
        up[u]++;
        up[l]--;
        down[v]++;
        down[l]--;
        u = v;
    }

    reverse(dfs_order.begin(), dfs_order.end());
    for (auto& idx: dfs_order) {
        if (idx > 0) {
            up[pa[0][idx]] += up[idx];
            down[pa[0][idx]] += down[idx];
        }
    }

    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        if (ts[parent_eid[i]]) {
            int num = (i == us[parent_eid[i]]) ? down[i]: up[i];
            ans = (ans + pw2[num] - 1) % mod;
        }
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}
