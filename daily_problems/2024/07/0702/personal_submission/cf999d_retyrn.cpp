int n, m;

int cal(int from, int to) {
    if (to >= from) return to - from;
    return to + m - from;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> cnt(m);
    vector<int> a(n);
    int base = n / m;
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        int t = a[i] % m;
        cnt[t].push_back(i);
    }
    ll res = 0;
    queue<int> q;
    for (int i = 0; i < m; i ++) {
        while (sz(cnt[i]) < base and !em(q)) {
            auto idx = q.front();
            q.pop();
            auto cost = cal(a[idx] % m, i);
            a[idx] += cost;
            cnt[i].push_back(idx);
            res += cost;
        }
        while (sz(cnt[i]) > base) {
            q.push(cnt[i].back());
            cnt[i].pop_back();
        }
    }
    for (int i = 0; i < m; i ++) {
        while (sz(cnt[i]) < base and !em(q)) {
            auto idx = q.front();
            q.pop();
            auto cost = cal(a[idx] % m, i);
            a[idx] += cost;
            cnt[i].push_back(idx);
            res += cost;
        }
        while (sz(cnt[i]) > base) {
            q.push(cnt[i].back());
            cnt[i].pop_back();
        }
    }
    assert(em(q));
    cout << res << endl;
    cout << a << endl;
}