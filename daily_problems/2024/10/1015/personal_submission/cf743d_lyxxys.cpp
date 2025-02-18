#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    vector <vector<int>> g(n);
    for (auto &x : A) cin >> x;
    for (int i = 0, a,b; i < n-1; ++ i){
        cin >> a >> b;
        a -= 1, b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool jg = 0;
    if (g[0].size() > 1) jg = 1;
    for (int i = 1; i < n; ++ i){
        if (g[i].size() > 2) jg = 1;
    }
    if (!jg){
        cout << "Impossible\n";
        return;
    }

    const long long inf = 1e18;
    vector <long long> f(n, -inf), ft(n);
    auto dfs_find = [&](auto &&self, int u, int fa)->void{
        ft[u] = A[u];
        long long Max = -inf;
        for (auto &x : g[u]){
            if (x == fa) continue;
            self(self, x, u);
            ft[u] += ft[x];
            Max = max(Max, f[x]);
        }
        f[u] = max(Max, ft[u]);
    };

    dfs_find(dfs_find, 0, -1);
    // for (auto &x : f) cout << x << " ";
    long long res = -inf;
    // reco 记录父节点链 子树 不包括 子树 u 的 最大值
    auto dfs_root = [&](auto &&self, int u, int fa, long long reco)->void{
        long long m1 = -inf, m2 = -inf, p = -1;
        for (auto &x : g[u]){
            if (x == fa) continue;
            if (m1 < f[x]){
                p = x;
                m2 = m1, m1 = f[x];
            } else if (m2 < f[x]){
                m2 = f[x];
            }
        }
        if (g[u].size() > 2 || (g[u].size() > 1 && (fa==-1 || reco != -inf))){
            vector <long long> tmps = {reco, m1, m2};
            sort(tmps.begin(), tmps.end(), greater<long long>());
            res = max(res, tmps[0]+tmps[1]);
        }
        for (auto &x : g[u]){
            if (x == fa) continue;
            if (p == x){
                self(self, x, u, max(reco, m2));
            } else {
                self(self, x, u, max(reco, m1));
            }
        }
    };

    dfs_root(dfs_root, 0, -1, -inf);

    cout << res << "\n";
}
