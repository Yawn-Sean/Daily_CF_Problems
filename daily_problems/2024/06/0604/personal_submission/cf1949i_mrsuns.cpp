void Solve() {
    int n;cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1;i <= n;i++) {
        int x, y, r;cin >> x >> y >> r;
        a[i] = { x,y,r };
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            int dis2 = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
            if ((a[i][2] + a[j][2]) * (a[i][2] + a[j][2]) == dis2) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> vis(n + 1);
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            auto check = [&]() {
                int ok = 1;
                array<int, 2> cnt = { 0,0 };
                q.push(i);vis[i] = 1;cnt[0]++;
                while (q.size()) {
                    auto u = q.front();q.pop();
                    for (auto v : g[u]) {
                        if (vis[v]) {
                            if (vis[u] == vis[v]) ok = 0;
                            continue;
                        }
                        q.push(v);vis[v] = 3 - vis[u];
                        cnt[vis[v] - 1]++;
                    }
                }
                return ok && cnt[0] != cnt[1];
                };
            if (check()) {
                return cout << "YES" << endl, void();
            }
        }
    }
    cout << "NO" << endl;
}
