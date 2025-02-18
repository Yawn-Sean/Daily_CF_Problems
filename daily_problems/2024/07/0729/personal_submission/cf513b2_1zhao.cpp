void solve() {
    long long n, m;
    cin >> n >> m;
    m --;
    vector<int> ans(n);
    int l=0, r=n-1;
    long long cnt = 1ll << (n-2);
    for(int i=1; i<=n; i++) {
        if(m < cnt) {
            ans[l] = i;
            l ++;
        } else {
            ans[r] = i;
            r --;
            m -= cnt;
        }
        cnt >>= 1;
    }
    for(int i: ans) cout << i << ' ';
    cout << endl;
}
