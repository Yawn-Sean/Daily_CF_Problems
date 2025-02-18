void solve() {
    LL n, k;
    // sum -> n
    // count -> k
    cin >> n >> k;
    vector<LL> can;
    for (int i = 0; i < 63; i ++) {
        if (n >> i & 1) can.push_back(i);
    }
    vector<int> ans;
    for (int i = -62; i <= 62; i ++) {
        ans.clear();
        bool ok = 1;
        for (int x: can) {
            if (x <= i) {
                ans.push_back(x);
            } else {
                if (x - i > 18) {
                    ok = 0;
                    break;
                }
                if ((1 << (x - i)) > k) {
                    ok = 0;
                    break;
                }
                for (int _ = 1; _ <= 1 << (x - i); _ ++) {
                    ans.push_back(i);
                }
            }
            if (ans.size() > k) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        ranges::sort(ans, greater<int>());
        while (ans.size() < k) {
            auto t = ans.rbegin();
            int now = *t - 1;
            *t = now;
            ans.push_back(now);
        }
        cout << "Yes\n";
        for (int x: ans) {
            cout << x << ' ';
        }
        return;
    }
    cout << "No\n";
}
