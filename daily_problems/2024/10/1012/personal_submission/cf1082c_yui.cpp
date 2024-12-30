void solve() {
    int n, m;
    cin >> n >> m;
    vec<int> a(n);
    map<int, vec<int>> rec;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s >> a[i];
        rec[s].push_back(a[i]);
    }
    vec<int> ans(n + 1);
    for (auto &[k, v] : rec) {
        ranges::sort(v, greater{});
        int sz = v.size();
        vec<int> s(sz + 1);
        for (int i = 0; i < sz; i++) {
            s[i + 1] = s[i] + v[i];
            if(s[i + 1] >= 0) ans[i + 1] += s[i + 1];
        }
    }

    cout << ranges::max(ans) << '\n';
}
