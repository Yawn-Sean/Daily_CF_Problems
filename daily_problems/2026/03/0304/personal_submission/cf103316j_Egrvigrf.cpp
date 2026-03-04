#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int ksm(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

struct DSU {
    int n;
    vector<int> f, sz;

    void init() {
        f.resize(n+1);
        sz.assign(n+1,1);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }

    DSU(int _n) : n(_n) {
        init();
    }

    int fd(int x) {
        if (f[x] != x) {
            return f[x] = fd(f[x]);
        }
        return f[x];
    }

    void merge(int x, int y) {
        int fx = fd(x);
        int fy = fd(y);
        if (fx != fy) {
            sz[fy] += sz[fx];
            f[fx] = fy;
        }
    }

    int S(int x) {
        return sz[fd(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n+1);
    vector<pair<int,int>> w(n);
    
    for (int i = 0; i < n; i++) {
        cin >> w[i].first;
        w[i].second = i+1;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    sort(w.begin(),w.end());
    DSU dsu(n);
    
    vector<int> vis(n+1,0);
    int ans = 0;
    for (auto i : w) {
        for (auto j : G[i.second]) {
            if (vis[j]) {
                ans += dsu.S(j) * dsu.S(i.second) % mod * i.first;
                ans %= mod;
                dsu.merge(i.second,j);
            }
        }
        vis[i.second] = 1;
    }

    reverse(w.begin(),w.end());
    vis.assign(n+1,0);
    dsu.init();
    
    for (auto i : w) {
        for (auto j : G[i.second]) {
            if (vis[j]) {
                ans = ans - dsu.S(j) * dsu.S(i.second) %mod * i.first % mod + mod;
                ans %= mod;
                dsu.merge(i.second,j);
            }
        }
        vis[i.second] = 1;
    }
    int num = n * (n-1) / 2 % mod;
    cout <<ans * ksm(num,mod-2) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}