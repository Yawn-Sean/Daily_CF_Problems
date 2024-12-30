void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> corX(n), corY(m);
    for (int i = 0; i < n; i ++ ) cin >> corX[i];
    for (int i = 0; i < m; i ++ ) cin >> corY[i];

    vector<unordered_map<int, int>> perX(n - 1), perY(m - 1);
    for (int i = 0; i < k; i ++ ) {
        int x, y;
        cin >> x >> y;
        int locX = lower_bound(corX.begin(), corX.end(), x) - corX.begin();
        if (x != corX[locX]) perX[locX - 1][y] ++;
        int locY = lower_bound(corY.begin(), corY.end(), y) - corY.begin();
        if (y != corY[locY]) perY[locY - 1][x] ++; 
    }
    i64 ans = 0;
    for (auto t: perX) {
        if (t.size() <= 1) continue;
        i64 cnt = 0;
        for (auto [_, x]: t) {
            ans += cnt * x;
            cnt += x;
        }
    }

    for (auto t: perY) {
        if (t.size() <= 1) continue;
        i64 cnt = 0;
        for (auto [_, x]: t) {
            ans += cnt * x;
            cnt += x;
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt --) {
        solve();
    }
    return 0;
}
