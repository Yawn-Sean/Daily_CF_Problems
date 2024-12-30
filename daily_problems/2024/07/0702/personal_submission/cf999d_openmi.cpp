void solve() {
    int n, m, len;
    cin >> n >> m;
    len = n / m;
    priority_queue<pii, vector<pii>, less<>> pq;
    vc<vi> r_idx(m);
    // moves: i 处操作了多少次，正数移走，负数补上
    vi moves(m), a(n);
    vc<vc<pii>> ops(m);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i] = x;
        r_idx[x % m].push_back(i);
    }
    ll ans = 0, t;
    rep (j, 0, 2 * m) {
        int i = j % m, div_i = r_idx[i].size() - moves[i];
        if (div_i > len) {
            pq.push({j, div_i - len});
        }
        while (div_i < len and !pq.empty()) {
            auto [pre_j, v] = pq.top();
            pq.pop();
            t = min(len - div_i, v);
            v -= t; 
            div_i += t;
            moves[pre_j % m] += t;
            moves[i] -= t;
            ops[pre_j % m].push_back({t, j - pre_j});
            ans += 1LL * (j - pre_j) * t; 
            if (v) pq.push({pre_j, v});
        }
    }
    rep (i, 0, m) if (moves[i] > 0) {
        int j = 0;
        for (auto& [t, add]: ops[i]) {
            auto& v = r_idx[i];
            rep (k, j, j + t) {
                a[v[k]] += add;
            }
            j += t;
        }
    }
    cout << ans << nl;
    printv(a, ' ', false);
}
