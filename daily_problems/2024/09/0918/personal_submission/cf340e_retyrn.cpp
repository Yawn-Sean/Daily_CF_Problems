int n;
int D[2010], fact[2010];

void solve() {
    cin >> n;
    // 计算出有多少可以随便选 有多少不可以选自己
    vector<int> a(n + 1);
    vector<int> st(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] >= 0) st[a[i]] = true;
    }
    
    int A = 0, B = 0;
    for (int i = 1; i <= n; i ++) {
        if (st[i]) continue;
        if (a[i] >= 0) A += 1;
        else B += 1;
    }
    D[0] = 0, D[1] = 0, D[2] = 1, D[3] = 2, D[4] = 9;
    for (int i = 5; i <= n; i ++) {
        D[i] = 1LL * (i - 1) * (D[i - 1] + D[i - 2]) % mod;
    }
    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i <= n; i ++) {
        fact[i] = (ll)fact[i - 1] * i % mod;
    }
    
    vector<vector<int>> f(A + 1, vector<int>(B + 1, 0));
    vector<vector<int>> seen(A + 1, vector<int>(B + 1, false));
    
    auto dfs = [&](auto&& self, int u, int v) -> int {
        if (u == 0) return D[v];
        if (v == 0) return fact[u];
        if (seen[u][v]) return f[u][v];
        seen[u][v] = true;
        ll res = 0;
        // 从A里拿一个放在B
        res += (ll)v * self(self, u, v - 1);
        res %= mod;
        res += (ll)u * self(self, u - 1, v);
        res %= mod;
        
        return f[u][v] = (int)res;
    };
    
    cout << dfs(dfs, A, B) << endl;
}