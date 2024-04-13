struct BIT {
    int n;
    vector<int> tr;
    BIT(int n) : n(n), tr(n + 1) {}

    inline int lbt(int x) { return x & -x; }

    void add(int i, int val) {
        for (; i <= n; i += lbt(i)) {
            tr[i] += val;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= lbt(i)) {
            res += tr[i];
        }
        return res;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
    int kth(int k) {
        int x = 0;
        int res = 0;
        for (int i = 1 << __lg(n); i > 0; i /= 2) {
            if (x + i <= n && k >= tr[x + i]) {
                x += i;
                k -= tr[x];
                res += tr[x];
            }
        }
        return (k ? -1 : res);
    }
};

void Solve(int TIME) {

    int n;cin >> n;
    vc<ai2> a(n + 1);
    vi v;
    for (int i = 1;i <= n;i++) {
        cin >> a[i][0] >> a[i][1];
        v.push_back(a[i][0]);
        v.push_back(a[i][1]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    debugsq(v);
    map<int, int> mp, val;
    for (int i = 1;i < v.size();i++) {
        int x = v[i - 1], y = v[i];
        mp[x] = 1, mp[y] = 1;val[x] = val[y] = 1;
        if (y - x > 1) mp[x + 1] = 1, val[x + 1] = y - x - 1;
    }
    vi value(mp.size() + 1);
    int tot = 0;for (auto& [i, j] : mp) j = ++tot, value[j] = val[i];
    vi arr(tot + 1);for (int i = 1;i <= tot;i++) arr[i] = i;

    for (int i = 1;i <= n;i++) {
        auto [x, y] = a[i];
        x = mp[x], y = mp[y];
        swap(arr[x], arr[y]);
    }

    BIT tr(tot + 10);
    int res = 0;
    for (int i = 1;i <= tot;i++) {
        res += tr.query(arr[i], tot) * value[arr[i]];
        tr.add(arr[i], value[arr[i]]);
    }
    cout << res << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    //cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
