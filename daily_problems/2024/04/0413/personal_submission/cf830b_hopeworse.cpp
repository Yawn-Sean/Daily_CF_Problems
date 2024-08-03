//link :https://codeforces.com/contest/830/submission/256424959

void solve() {
    int n;
    cin >> n;
    bit.init(n);
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[a[i]].insert(i + 1);
    }
    int q = 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        auto next = s[a[i]].lower_bound(q);
        if (next == s[a[i]].end()) {
//            debug(n - q + 1, bit.query(q, n));
            ans += n - q + 1 - bit.query(q, n);
            q = 1;
            next = s[a[i]].lower_bound(q);
        }
//        debug(*next, q, *next - q + 1, bit.query(q, *next));
        ans += *next - q + 1 - bit.query(q, *next);
        bit.add(*next, 1);
        q = *next + 1;
        s[a[i]].erase(next);
        debug(ans);
    }
    cout << ans << endl;
}
