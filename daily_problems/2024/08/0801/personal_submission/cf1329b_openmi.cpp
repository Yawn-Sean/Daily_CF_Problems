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
