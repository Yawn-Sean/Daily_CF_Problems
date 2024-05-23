/*
url: 
    question: https://codeforces.com/problemset/problem/1132/C
    submission: https://codeforces.com/contest/1132/submission/262094091
time: 359 ms
*/

void solve() {
    // 空间最拉满的一集: 192900kb
    int n, q;
    cin >> n >> q;
    vector<PII> qs;
    for (int i = 0; i < q; i ++ ) { 
        int l, r;
        cin >> l >> r;
        qs.emplace_back(l, r);
    }
    sort(qs.begin(), qs.end());
    vector<int> s(n + 2);
    for (auto [l, r]: qs) {
        s[r + 1] --, s[l] ++;
    }
    for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];
    vector<vector<PII>> cnt(n + 1, vector<PII> (n + 1));
    int tot = 0;
    for (int i = 1; i <= n; i ++ ) {
        tot += s[i] >= 1;
        for (int j = i; j <= n; j ++ ) {
            cnt[i][j].first = cnt[i][j - 1].first;
            cnt[i][j].second = cnt[i][j - 1].second;
            if (s[j] == 1) cnt[i][j].first ++;
            if (s[j] == 2) cnt[i][j].second ++;
        }
    }
    int ans = 0;
    for (int i = 0; i < q; i ++) {
        for (int j = i + 1; j < q; j ++ ) {
            auto [l0, r0] = qs[i];
            auto [l1, r1] = qs[j];
            int res = tot;
            if (l1 > r0) res -= cnt[l0][r0].first + cnt[l1][r1].first;
            else {
                res -= cnt[l1][min(r0, r1)].second;
                if (l0 != l1) res -= cnt[l0][l1 - 1].first;
                if (r0 != r1) res -= cnt[min(r0, r1) + 1][max(r1, r0)].first;
            }
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
}
