int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        if (sz(g[x]) > 4 or sz(g[y]) > 4) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    vector<pii> res(n, mpr(inf, inf));
    res[0] = mpr(0, 0);
    map<pii, int> mp;
    
    queue<pii> q;
    q.emplace(0, 1 << 29);
    
    while (!em(q)) {
        auto [ver, len] = q.front();
        q.pop();
        for (auto x : g[ver]) {
            if (res[x].fi != inf) continue;
            for (int i = 0; i < 4; i ++) {
                if (mp[res[ver]] >> i & 1) continue;
                mp[res[ver]] |= (1 << i);
                pii p = mpr(len * dx[i] + res[ver].fi, len * dy[i] + res[ver].se);
                res[x] = p;
                mp[res[x]] |= (1 << (i ^ 2));
                q.emplace(x, len >> 1);
                break;
            }
        }
    }
    
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
}