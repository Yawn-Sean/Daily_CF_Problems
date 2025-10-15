/*
每个植物至多被重新种植一次
事实上好像是求一个 LIS，LIS 上的都不动，其他的需要动
好像坐标完全没用
*/

int a[N], n, m;
int tr[N], dp[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        double d;
        cin >> d;
    }

    dp[1] = 1;
    modify(a[1], 1);
    int res = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = query(a[i]) + 1;
        modify(a[i], dp[i]);
        res = max(res, dp[i]);
    }
    cout << n - res << "\n";
}   
