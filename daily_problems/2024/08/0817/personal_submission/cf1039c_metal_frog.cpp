void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n); 
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    unordered_map<ll, unordered_set<int>> hashmap;
    unordered_map<ll, vector<pii>> edges; 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ll w = c[u] ^ c[v];
        hashmap[w].insert(u);
        hashmap[w].insert(v);
        edges[w].emplace_back(u, v);
    }
    ll ans = 0;
    for (auto& [w, Set] : hashmap) {
        vector<int> index;
        for (int u : Set) {
            index.emplace_back(u);
        }
        sort(all(index));
        UF dsu(index.size());
        ll cnt = n;
        for (auto [u, v] : edges[w]) {
            int uid = lower_bound(all(index), u) - index.begin();
            int vid = lower_bound(all(index), v) - index.begin();
            if (!dsu.sameSet(uid, vid)) {
                dsu.join(uid, vid);
                cnt--;
            }
        }
        ans += modpow(2LL, cnt);
        ans %= mod;
    }
    ll remain = ((1LL << k) - ll(edges.size())) % mod;
    ll subsetCnt = modpow(2, n);
    ans += (remain * subsetCnt) % mod;
    ans %= mod;
    cout << ans << "\n";
}
