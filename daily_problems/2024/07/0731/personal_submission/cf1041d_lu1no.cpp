int pre[N], n, h;
array<int, 2> seg[N];

bool check(int L, int R) {
    int d = seg[R][1] - seg[L][0] - (pre[R] - pre[L - 1]);
    return d < h;
}

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        seg[i] = {l, r};
        pre[i] = r - l;
        pre[i] += pre[i - 1];
    }
    if (n == 1) {
        auto [l, r] = seg[1];
        int ans = r - l + h;
        cout << ans << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        int l = i, r = n;
        int j = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
                j = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int d = seg[j][1] - seg[i][0] - (pre[j] - pre[i - 1]);
        int rest = h - d;
        int res = seg[j][1] - seg[i][0] + rest;
        ans = max(res, ans);
    }
    cout << ans << endl;
}
