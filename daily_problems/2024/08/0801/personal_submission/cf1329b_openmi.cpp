// 递推写法
void solve() {
    ll d, m;
    cin >> d >> m;
    ll cur = 0, i = 0, dp = 0;
    for (; (cur << 1 | 1) < d; cur = cur << 1 | 1, ++i) {
        dp = (dp * (1 << i | 1) + (1 << i)) % m;
    }
    int delt = d - cur;
    cout << (dp * (delt + 1) + delt) % m << nl;
}

// 正常递归
void solve() {
    ll d, m;
    cin >> d >> m;
    int cur = d; 
    auto dfs = [&](auto& self, ll cur) {
        if (cur == 0) return 0;
        ll pre = (1 << hbll(cur)) - 1;
        int delt = cur - pre;
        return ((delt + 1) * self(self, pre) + delt) % m;
    };
    cout << dfs(dfs, d) % m << nl; 
}

// 记忆化 （记忆了个寂寞
void solve() {
    ll d, m;
    cin >> d >> m;
    int cur = d;
    map<int, ll> mem;
    mem[0] = 0; 
    auto dfs = [&](auto& self, ll cur) {
        ll pre = (1 << hbll(cur)) - 1;
        if (mem.count(cur)) {
            return mem[cur];
        } 
        mem[pre] = self(self, pre);
        int delt = cur - pre;
        return mem[cur] = ((delt + 1) * mem[pre] + delt) % m;
    };
    cout << dfs(dfs, d) % m << nl; 
}
