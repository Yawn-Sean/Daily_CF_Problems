int n, q;
LL a[N], pre[N];
map<LL, int> vis;

LL ask(int l, int r) {
    return pre[r] - pre[l - 1];
}

void dfs(int l, int r) {
    if (l == r) {
        vis[a[l]] = 1;
        return;
    }
    if (a[l] == a[r]) {
        vis[ask(l, r)] = 1;
        return;
    }
    // cout << l << ' ' << r << endl;
    vis[ask(l, r)] = 1;
    LL mid = (a[l] + a[r]) >> 1;
    auto k = upper_bound(a + 1, a + 1 + n, mid) - a;
    dfs(l, k - 1);
    dfs(k, r);
}


void solve() {
    vis.clear();
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) {
        pre[i] = a[i];
        pre[i] += pre[i - 1];
    }
    dfs(1, n);
    while (q --) {
        LL x; cin >> x;
        if (vis.count(x)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
