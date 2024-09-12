int n, x ,y;

void solve() {
    cin >> n >> x >> y;
    vector<pii> a(n);
    cin >> a;
    sort(all(a));
    multiset<int> S;
    ll res = 0;
    
    for (auto [l, r] : a) {
        bool ok = false;
        ll c = x + (ll)y * (r - l);
        if (!em(S) and *S.begin() < l) {
            auto it = S.lower_bound(l);
            it --;
            if ((ll)y * (r - *it) < c) {
                res += (ll)y * (r - *it);
                res %= mod;
                ok = true;
                S.erase(it);
            }
        }
        if (!ok) {
            res += c;
            res %= mod;
        }
        S.insert(r);
    }
    
    cout << res << endl;
    
}