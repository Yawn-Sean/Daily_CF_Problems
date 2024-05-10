void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<array<int, 2>>> a(m + 1), tmp;
    vector<array<int, 3>> evt(n + 1);
    for (int i = 1;i <= n;i++) {
        int ren, cost;cin >> ren >> cost;
        evt[i] = { cost,ren,i };
    }
    sort(evt.begin() + 1, evt.end(), greater<array<int, 3>>());
    for (int i = 1;i <= n;i++) {
        auto [cost, ren, id] = evt[i];
        a[ren].push_back({ cost,id });
    }
    auto check = [&](int x)->ll {
        tmp = a;
        int cnt = tmp[1].size();
        int res = 0;
        vector<int> vis(n + 1);
        for (int i = 2;i <= m;i++) {
            if (tmp[i].size() >= x) {
                while (tmp[i].size() >= x) {
                    auto [cost, id] = tmp[i].back();
                    res += cost;
                    tmp[i].pop_back();
                    vis[id] = 1;
                    cnt += 1;
                }
            }
        }
        if (cnt > x) return 1e18;
        else {
            int d = x - cnt;
            for (int i = n;i >= 1;i--) {
                if (d == 0) break;
                auto [cost, ren, id] = evt[i];
                if (vis[id] || ren == 1) continue;
                res += cost;
                d--;
            }
            return res;
        }
        };
    int res = 1e18;
    for (int i = 1;i <= n;i++) {
        res = min(res, check(i));
    }
    cout << res << endl;
}
