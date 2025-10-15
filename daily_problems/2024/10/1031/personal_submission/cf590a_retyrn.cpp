int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    vector<pii> segs;
    for (int i = 0, last = 0; i < n; i ++) {
        if (i == n - 1 or (a[i] == a[i + 1])) {
            segs.emplace_back(last, i);
            last = i + 1;
        }
    }
    int mx = 0;
    for (auto [l, r] : segs) {
        int len = r - l + 1;
        chmax(mx, (len - 1) / 2);
        
        for (int i = 0;i < len / 2; i ++) {
            a[l+i] = a[l];
            a[r-i] = a[r];
        }
        if (len & 1) a[l + len / 2] = a[l];
    }
    
    cout << mx << endl;
    cout << a << endl;
}