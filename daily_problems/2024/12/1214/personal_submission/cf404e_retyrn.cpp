int n;
string s;

void solve() {
    // 只可能0/1堵墙
    cin >> s;
    n = sz(s);
    vector<int> st(n * 2 + 10, false);
    auto check = [&](int ban) -> bool {
        fill(all(st), false);
        int x = n;
        for (int i = 0; i < n; i ++) {
            st[x] = true;
            int nx = x + (s[i] == 'R' ? 1 : -1);
            if (ban == nx) continue;
            x = nx;
        }
        return !st[x];
    };
    
    if (check(inf)) {
        cout << 1 << endl;
        return;
    }
    // 如果最后一步是L, 那么一定在原点右侧
    if (s.back() == 'L') {
        int l = n, r = n + n;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l - n << endl;
    }
    else {
        int l = 0, r = n;
        while (l < r) {
            auto mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << n - l << endl;
    }
}