struct Trade {
    int x, y, z;
    int a, b;
};

void solve() {
    int n, m;
    ll v_long;
    cin >> n >> m >> v_long;
    
    ld v = (ld)v_long;

    string s;
    cin >> s;

    vector<Trade> trades;
    for (int i = 0; i < m; ++i) {
        int a, x, b, y, c, z;
        cin >> a >> x >> b >> y >> c >> z;
        trades.push_back({x - 1, y - 1, z - 1, a, b});
    }

    vector<ld> cost(n, INF);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            cost[i] = 1.0;
        }
    }

    for (int iter = 0; iter < n; ++iter) {
        bool changed = false;
        for (const auto& t : trades) {
            if (cost[t.x] >= INF || cost[t.y] >= INF) continue;

            ld new_cost = (ld)t.a * cost[t.x] + (ld)t.b * cost[t.y];
            
            if (new_cost < cost[t.z]) {
                cost[t.z] = new_cost;
                changed = true;
            }
        }
        if (!changed) break;
    }

    if (cost[0] >= INF) {
        cout << fixed << setprecision(10) << 0.0 << "\n";
    } else {
        ld ans = v / cost[0];
        cout << fixed << setprecision(10) << ans << "\n";
    }
}
