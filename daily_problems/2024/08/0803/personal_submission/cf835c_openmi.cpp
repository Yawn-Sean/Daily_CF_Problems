void solve() {
    int n, q, c;
    cin >> n >> q >> c;
    vector<vector<vector<int>>> g(100, vvi (100)), sum(11, vector<vector<int>>(101, vi(101)));
    rep (i, 0, n) {
        int x, y, s;
        cin >> x >> y >> s;
        x--, y--;
        g[x][y].push_back(s);
    }

    rb (t, 0, c) {
        rep (i, 0, 100) {
            rep (j, 0, 100) {
                int temp = 0;
                for (int x: g[i][j]) {
                    temp += (t + x) % (c + 1);
                }
                sum[t][i + 1][j + 1] = temp + sum[t][i][j + 1] + sum[t][i + 1][j] - sum[t][i][j];
            }
        }
    }
    auto cal = [&](auto& v, int x1, int y1, int x2, int y2, int t) {
        return v[t][x2 + 1][y2 + 1] - v[t][x2 + 1][y1] - v[t][x1][y2 + 1] + v[t][x1][y1];
    };
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        cout << cal(sum, x1, y1, x2, y2, t % (c + 1)) << nl;
    }
}
