int n, m, k;

ll cal(vector<int>& xs, vector<pii>& a) {
    // 按照x一条一条算 但是不算在x上的
    ll res = 0;
    sort(all(a));
    map<int, int> mp;
    for (int i = 0; i < sz(xs) - 1; i ++) {
        int x1 = xs[i], x2 = xs[i+1];
        int l = lower_bound(all(a), mpr(x1 + 1, -1)) - a.begin();
        int r = upper_bound(all(a), mpr(x2, -1)) - a.begin() - 1;
        for (int j = l; j <= r; j ++) {
            res += (j - l - mp[a[j].se]);
            mp[a[j].se] += 1;
        }
        mp.clear();
    }
    return res;
}

bool count(vector<int>& v, int val) {
    auto it = lower_bound(all(v), val);
    return it != v.end() and *it == val;
}

void solve() {
    // 交点上的一定不可以
    // 只考虑单在x上或者单在y上
    
    // 两个点都单在x上的话 不能同x 中间不可以有y 是一段一段的
    // 两个点都单在y上的话 不能同y 中间不可以有x
    // 一个在x上 一个在y上 一定不行
    
    cin >> n >> m >> k;
    vector<int> xs(n), ys(m);
    cin >> xs;
    cin >> ys;
    
    // 删除交点的点
    vector<pii> a;
    for (int i = 0; i < k; i ++) {
        int x, y;
        cin >> x >> y;
        
        if (count(xs, x) and count(ys, y)) continue;
        a.push_back({x, y});
    }
    
    ll res = cal(xs, a);
    
    for (auto& [x, y] : a) {
        swap(x, y);
    }
    res += cal(ys, a);
    cout << res << endl;
}