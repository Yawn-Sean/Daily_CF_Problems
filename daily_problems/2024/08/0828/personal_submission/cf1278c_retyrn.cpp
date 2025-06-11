int n;

void solve() {
    cin >> n;
    vector<int> a(n << 1);
    cin >> a;
    
    map<int, int> mp;
    int cnt = 0;
    mp[0] = n;
    for (int i = 0; i < n; i ++) {
        cnt += (a[i] == 2 ? 1 : -1);
        mp[cnt] = n - i - 1;
    }
    cnt = 0;
    
    int res = mp[0] + n;
    for (int i = n * 2 - 1; i >= n; i --) {
        cnt += (a[i] == 2 ? 1 : -1);
        if (mp.count(-cnt)) chmin(res, mp[-cnt] + i - n);
    }
    cout << res << endl;
}