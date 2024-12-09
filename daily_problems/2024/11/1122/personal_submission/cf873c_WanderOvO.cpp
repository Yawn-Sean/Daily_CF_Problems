void meibao() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }    
    vector<int> s(n + 1, 0);
    int maxsum = 0, mincnt = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i][j];
        }
        int sum = 0, cnt = 0, curcnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) {
                int t = min(i + k - 1, n);
                if (sum < s[t] - s[i - 1]) {
                    sum = s[t] - s[i - 1];
                    cnt = curcnt;
                }
                curcnt++;
            }
        }
        maxsum += sum;
        mincnt += cnt;
    }
    cout << maxsum << " " << mincnt << "\n";
}
