void solve() {
    int n, k;
    cin >> n >> k;
    map<pii, int> cnt;
    auto calc = [&](auto&& calc, int l, int r) -> int {
        if (r - l == 1) {
            cnt[{l, r}] = 1;
            return 1;
        }
        int mid = l + (r - l) / 2;
        int left = calc(calc, l, mid);
        int right = calc(calc, mid, r);
        cnt[{l, r}] = left + right + 1;
        return left + right + 1;
    }; 
    int ub = calc(calc, 0, n);
    if (k > ub || k % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i + 1;
    auto calc2 = [&](auto&& calc2, int l, int r, int k) {
        k -= 1;
        if (k == 0) {
            return;
        }
        int mid = l + (r - l) / 2;
        int leftCnt = cnt[{l, mid}];
        if (leftCnt >= k - 1) {
            swap(ans[mid], ans[mid - 1]);
            calc2(calc2, l, mid, k - 1);
        } else {
            swap(ans[mid], ans[mid - 1]);
            calc2(calc2, l, mid, leftCnt);
            calc2(calc2, mid, r, k - leftCnt);
        }
    };
    calc2(calc2, 0, n, k);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
