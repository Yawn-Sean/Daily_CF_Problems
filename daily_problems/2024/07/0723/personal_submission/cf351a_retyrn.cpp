int n;

void solve() {
    cin >> n;
    vector<int> a(n << 1);
    ll sum = 0;
    int zero = 0;
    for (int i = 0; i < (n << 1); i ++) {
        string s;
        cin >> s;
        int idx = s.find('.');
        string s1 = s.substr(idx + 1);
        a[i] = stoi(s1);
        sum -= a[i];
        zero += (a[i] == 0);
    }
    
    int l = max(0, n - zero), r = min(n, (n * 2 - zero));
    ll res = inf2;
    for (int i = l; i <= r; i ++) {
        ll cur = sum + 1000LL * i;
        chmin(res, abs(cur));
    }
    cout << (res / 1000) << '.';
    res %= 1000;
    string s = to_string(res);
    reverse(all(s));
    while (sz(s) < 3) s += '0';
    reverse(all(s));
    cout << s << endl;
}