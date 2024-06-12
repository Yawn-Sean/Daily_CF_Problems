using pli = pair<ll, int>;
int n;

void solve() {
    cin >> n;
    vector<ll> w(n), t(n);
    for (int i = 0; i < n; i ++) {
        cin >> t[i] >> w[i];
    }
    // 枚举让前面几个队飞走
    priority_queue<pli> suf;
    priority_queue<ll, vector<ll>, greater<ll>> pre;
    for (int i = 1; i < n; i ++) {
        if (t[i] > t[0]) pre.push(w[i] + 1 - t[i]);
        else {
            suf.push({t[i], i});
        }
    }
    int res = sz(pre) + 1;
    
    while (sz(pre) and pre.top() <= t[0]) {
        auto need = pre.top();
        pre.pop();
        t[0] -= need;
        while (sz(suf) and suf.top().fi > t[0]) {
            auto [_, who] = suf.top();
            suf.pop();
            pre.push(w[who] - t[who] + 1);
        }
        res = min(res, sz(pre) + 1);
    }
    cout << res << endl;
}