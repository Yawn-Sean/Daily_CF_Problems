void solve() {
    vector<int> up(4);
    for (auto &x: up) cin >> x, x--;
    cout << 50 << ' ' << 50 << endl;
    vector<string> ans(50);
    for (int i = 0; i < 50; i ++ ) {
        for (int j = 0; j < 50; j ++ ) {
            if (i < 25) ans[i] += j < 25 ? 'A': 'B';
            else ans[i] += j < 25 ? 'C': 'D';
        }
    }
    vector<PII> start;
    start.emplace_back(25, 25);
    start.emplace_back(25, 0);
    start.emplace_back(0, 25);
    start.emplace_back(0, 0);
    string test = "ABCD";
    for (int k = 0; k < 4; k ++ ) {
        int cnt = up[k];
        auto [x, y] = start[k];
        for (int i = x + 1; i < x + 25; i += 2) {
            if (cnt == 0) break;
            for (int j = y + 1; j < y + 25; j += 2) {
                if (cnt == 0) break;
                ans[i][j] = k + 'A';
                cnt --;
            }
        }
    }
    cerr << test << endl;
    for (auto str: ans) {
        cout << str << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
