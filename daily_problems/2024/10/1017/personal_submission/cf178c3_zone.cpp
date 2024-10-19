void solve() {
    int h, m, n;
    cin >> h >> m >> n;
    string op;
    map<int, int> idx;

    vector<int> h1(h, -1), h2(h, -1);

    int cnt0 = 0, cnt1;

    for (int i = 0; i < h; i ++ ) {
        if (h2[i] != -1) continue;
        cnt1 = 0;
        while (h2[i] == -1) {
            h1[i] = cnt0;
            h2[i] = cnt1 ++;
            i = (i + m) % h;
        }
        cnt0 ++;
    }

    vector<set<int>> mp(cnt0);
    for (int i = 0; i < cnt0; i ++ ) {
        for (int j = 0; j < cnt1; j ++ ) {
            mp[i].emplace(j);
        }
    }
    i64 ans = 0;

    while (n -- ) {
        cin >> op;
        if (op == "+") {
            int v, hash;
            cin >> v >> hash;

            int t = h1[hash], res = 0; 
            // cout << (t + res * m) % h << endl;
            auto tt = mp[t].lower_bound(h2[hash]);
            if (tt == mp[t].end()) {
                tt = mp[t].begin();
                res = *tt + cnt1 - h2[hash];
            } else {
                res = *tt - h2[hash];
            }
            mp[t].erase(tt);
            idx[v] = (hash + res * m) % h;
            ans += res;
        } else {
            int v;
            cin >> v;
            int t = idx[v];
            mp[h1[t]].emplace(h2[t]);
        }
    }

    cout << ans << endl;
}
