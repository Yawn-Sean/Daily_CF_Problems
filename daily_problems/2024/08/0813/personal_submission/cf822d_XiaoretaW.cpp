int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    auto ck = [&](ll mx) -> pair<int, vector<int>> {
        vector<int> ans(n);
        set<int> used;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (x) {
                if (x <= mx && !used.count(x)) {
                    ans[i] = x;
                    used.insert(x);
                    break;
                }
                x >>= 1;
            }
            if (!x) {
                return mp(0, vector<int>{});
            }
        }
        return mp(1, ans);
    };

    ll l = 1, r = ll(1e9);
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (ck(mid).fi) r = mid;
        else l = mid + 1;
    }
    
    auto ans = ck(l).se;
    for (int i : ans) cout << i << ' ';
    cout << '\n';

    return 0;
}
