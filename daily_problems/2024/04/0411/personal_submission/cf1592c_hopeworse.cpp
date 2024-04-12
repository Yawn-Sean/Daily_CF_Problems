//link https://codeforces.com/contest/1592/submission/256061412

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    int xorr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        xorr ^= arr[i];
    }

    VII mp(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);

    }
    if (xorr == 0) {
        cout << "YES" << endl;
        return;
    }
    vector<int> ans(n + 1);
    debug(xorr);
    function<bool(int, int)> dfs = [&](int f, int now) {
        for (auto &i: mp[now]) {
            if (i == f)continue;
            if (dfs(now, i))return true;
            arr[now] ^= arr[i];
            ans[now] += ans[i] != 0;
        }
        debug(now, arr[now], ans[now]);
        if (arr[now] == 0 && ans[now] >= 1)return true;
        if (ans[now] >= 2)return true;
        if (arr[now] == xorr && ans[now] == 0)ans[now]++;
        return false;
    };

    if (k > 2 && dfs(0, 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
