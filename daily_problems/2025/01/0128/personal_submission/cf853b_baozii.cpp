void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<array<i64, 3>> to, from;
    rep(i, 0, m) {
        i64 t, fr, tt, c;
        cin >> t >> fr >> tt >> c;
        if (fr == 0) {
            from.pb({t, tt, c});
        } else {
            to.pb({t, fr, c});
        }
    }
    sort(ALL(to));
    sort(ALL(from));
    map<i64, i64> mn;
    reverse(ALL(from));
    umap<i64, i64> cost;
    i64 tot = 0;
    for (auto [time, dest, c] : from) {
        if (!cost.contains(dest)) {
            cost[dest] = c;
            tot += c;
        } else {
            tot -= cost[dest];
            cost[dest] = min(cost[dest], c);
            tot += cost[dest];
        }
        if (cost.size() == n) mn[time] = tot;
    }
    cost.clear();
    tot = 0;
    i64 ans = LLONG_MAX;
    for (auto [time, fr, c] : to) {
        if (!cost.contains(fr)) {
            cost[fr] = c;
            tot += c;
        } else {
            tot -= cost[fr];
            cost[fr] = min(cost[fr], c);
            tot += cost[fr];
        }
        if (cost.size() == n) {
            auto it = mn.lower_bound(time + k + 1);
            if (it == mn.end()) continue;
            auto [_, co] = *it;
            ans = min(ans, tot + co);
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
}
