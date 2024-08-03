const int N = 1e5 + 10;
void solve(int _) 
{
    int n;
    cin >> n;
    vector<PII> a(n);
    vector<int> idx(n);
    iota(all(idx), 0);
    vector<string> s(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> s[i];
        int m = SZ(s[i]);
        int cnt = 0;
        for (auto &ch: s[i]) {
            cnt += (ch == 's');
        }
        a[i] = {cnt, m-cnt};
    }

    sort(all(idx), [&](int c, int d) {
        return a[c].x * a[d].y > a[c].y * a[d].x;
    });

    string res;
    for (int i = 0; i < n; i ++ ) {
        res += s[idx[i]];
    }

    int ans = 0, cnt = 0;
    for (auto &ch: res) {
        if (ch == 'h') ans += cnt;
        cnt += (ch == 's');
    }

    cout << ans << endl;

} 