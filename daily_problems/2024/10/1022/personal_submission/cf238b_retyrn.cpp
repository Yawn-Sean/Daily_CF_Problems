int n, h;

void solve() {
    cin >> n >> h;
    vector<int> a(n);
    cin >> a;
    vector<int> id(n);
    iota(all(id), 0);
    
    sort(all(id), [&](int x, int y) {
        return a[x] < a[y];
    });
    
    // 最大的两个数最好在同一侧
    // 最小的两个数在反向
    // 最小的分出来1个 放在一边 其他的在另外一边
    vector<int> res(n, 1);
    int ans1 = a[id[n - 1]] + a[id[n - 2]] - a[id[0]] - a[id[1]];
    int ans2 = max(a[id[n-1]] + a[id[n-2]], a[id[0]] + a[id[n-1]] + h) - min(a[id[0]] + a[id[1]] + h, (n > 2 ? a[id[1]] + a[id[2]] : inf));
    if (ans1 > ans2) {
        res[id[0]] = 2;
    }
    cout << min(ans1, ans2) << endl;
    cout << res << endl;
}