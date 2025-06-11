int n;
string s;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    cin >> s;
    int res = 0, cur = 0;
    for (int i = n - 1; i >= 0; i --) {
        if (s[i] == '0') continue;
        chmax(res, cur + sum[i]);
        cur += a[i];
    }
    chmax(res, cur);
    
    cout << res << endl;
}