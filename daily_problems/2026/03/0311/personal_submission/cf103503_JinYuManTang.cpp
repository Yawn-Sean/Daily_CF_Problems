void solve() {
    i64 n, s;
    cin >> n >> s;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 tot = reduce(a.begin(), a.end(), 0LL);
    if (tot >= s) {
        cout << n << '\n';
        return;
    }
    // 当前子数组长度为v
    auto check = [&](i64 v) -> bool {
        i64 cnt = v - n, pre = 0;
        i128 sum = tot;
        for (i64 x: a) {
            if (cnt == 0) {
                break;
            }
            if (x - pre > 1) {
                i64 gap = x - pre - 1;
                chmin(gap, cnt);
                sum += (i128)(pre + 1 + pre + gap) * gap / 2;
                cnt -= gap;
            }
            pre = x;
        }
        if (cnt) {
            sum += (i128)(pre + 1 + pre + cnt) * cnt / 2;
        }
        return sum < s;
    };
    i64 left = n - 1, right = 1e18;
    while (left + 1 < right) {
        i64 mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << right << '\n';
}
