void Solve() {
    int n, q;cin >> n >> q;
    vector<vector<int>> cun(n + 1);
    for (int i = 1;i <= q;i++) {
        int l, r;cin >> l >> r;
        for (int j = l;j <= r;j++) cun[j].push_back(i);
    }
    int res = 0;
    for (int i = 1;i <= n;i++) {
        if (cun[i].size()) res += 1;
        if (cun[i].size() >= 3) {
            //res += 1;
        }
        else {
            if (cun[i].size() == 2) {
                cnt2[cun[i][0]][cun[i][1]] += 1;
                cnt2[cun[i][1]][cun[i][0]] += 1;
            }
            else if (cun[i].size() == 1) {
                cnt1[cun[i][0]] += 1;
            }
        }
    }
    int mn = 1e9;
    for (int i = 1;i <= q;i++) {
        for (int j = i + 1;j <= q;j++) {
            mn = min(mn, cnt2[i][j] + cnt1[i] + cnt1[j]);
        }
    }
    cout << res - mn << endl;

}
