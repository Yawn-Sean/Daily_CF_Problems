int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        int cnt = 0;
        vector<string> mp(n);
        int ans = n * n;
        for (int i = 0; i < n; i ++) {
            cin >> mp[i];
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mp[i][j] == '1') {
                    cnt ++;
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            int now = 0;
            for (int r = n - 1 - i, l = 0; r < n && l < n; r ++, l ++) {
                if (mp[r][l] == '1') now ++;
            }
            for (int r = 0, l = 1 + i; r < n && l < n; r ++, l ++) {
                if (mp[r][l] == '1') now ++;
            }
            ans = min(cnt - now + n - now, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
