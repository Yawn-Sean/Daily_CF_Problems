void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i], a[i]++;
    int inv = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < i;j++) {
            if (a[j] > a[i]) inv++;
        }
    }
    int res = 1e9, res_cnt = 0;
    for (int i = 1;i <= n;i++) {
        BIT tr(n);
        for (int j = i + 1;j <= n;j++) {
            int sum = inv;
            if (a[i] < a[j]) sum++;
            else sum--;
            sum -= tr.query(a[j] + 1, n);
            sum += tr.query(1, a[j] - 1);
            sum += tr.query(a[i] + 1, n);
            sum -= tr.query(1, a[i] - 1);
            tr.add(a[j], 1);
            if (sum < res) {
                res = sum;
                res_cnt = 1;
            }
            else if (sum == res) {
                res_cnt++;
            }
        }
    }
    cout << res << " " << res_cnt << endl;
}
