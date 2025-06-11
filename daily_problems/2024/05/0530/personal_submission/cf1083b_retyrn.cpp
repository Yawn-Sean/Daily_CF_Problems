int n, k;
string s, t;

void solve() {
    cin >> n >> k;
    int cnt = 1;
    ll res = 0;
    cin >> s >> t;
    for (int i = 0; i < n; i ++) {
        cnt = cnt * 2 - (s[i] == 'b') - (t[i] == 'a');
        res += min(k, cnt);
        cnt = min(cnt, k + 1);
    }
    cout << res << endl;
}