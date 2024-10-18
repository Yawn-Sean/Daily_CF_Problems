int n, S;

void solve() {
    cin >> n >> S;
    vector<int> s(n), a(n), b(n);
    ll sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> s[i] >> a[i] >> b[i];
        sum += s[i];
    }
    
    sum = (sum + S - 1) / S;
    ll na = 0, nb = 0;
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        if (b[i] > a[i]) nb += s[i];
        else if (a[i] > b[i]) na += s[i];
        res += (ll)s[i] * max(a[i], b[i]);
    }
    
    if ((na + S - 1) / S + (nb + S - 1) / S <= sum) {
        cout << res << endl;
        return;
    }
    // 没办法到最大 想办法调整了一部分要a的 或者一部分要b的
    
    // 先把a变成b
    int need = na - max(na - 1, 0ll) / S * S;
    priority_queue<pii> q;
    for (int i = 0; i < n; i ++) {
        if (a[i] > b[i]) {
            q.emplace(b[i] - a[i], s[i]);
        }
    }
    ll ans1 = res;
    while (sz(q) and need > 0) {
        auto cur = min(need, q.top().se);
        ans1 += (ll)q.top().fi * cur;
        q.pop();
        need -= cur;
    }
    
    while (!em(q)) q.pop();
    
    // 把b变成a
    need = nb - max(nb - 1, 0ll) / S * S;
    for (int i = 0; i < n; i ++) {
        if (b[i] > a[i]) {
            q.emplace(a[i] - b[i], s[i]);
        }
    }
    ll ans2 = res;
    while (sz(q) and need > 0) {
        auto cur = min(need, q.top().se);
        ans2 += (ll)q.top().fi * cur;
        q.pop();
        need -= cur;
    }
    
    cout << max(ans1, ans2) << endl;
    
}