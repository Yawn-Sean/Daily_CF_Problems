// https://codeforces.com/contest/1158/submission/255142561

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> nxt(n);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; ++i) {
        int &x = nxt[i];
        cin >> x, x--;
        if (x < 0) x = i + 1;
        g[x].emplace_back(i);
    }
    vector<int> ans(n);
    int cur = 1;
    for (auto p: g) {
        for (int i: p | views::reverse) {
            ans[i] = cur++;
        }
    }
    vector<int> check(n, n);
    stack<int> S;
    for (int i = 0; i < n; ++i) {
        while (!S.empty() && ans[S.top()] < ans[i]) {
            check[S.top()] = i;
            S.pop();
        }
        S.emplace(i);
    }
    if (check == nxt) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    } else {
        cout << -1 << endl;
    };
}
