void solve() {
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<i64> a(n);
    int cntN = 0;
    for (auto &y: a) cin >> y, cntN += (y < 0);
    auto cmp = [&] (int x, int y) {
        return abs(a[x]) > abs(a[y]);
    };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

    for (int i = 0; i < n; i ++) q.push(i);
    if (cntN % 2 == 0) {
        auto t = q.top();
        q.pop();
        i64 cnt = (abs(a[t]) + x - 1) / x;
        if (cnt * x == abs(a[t])) cnt ++;
        if (a[t] >= 0) a[t] -= min(k, cnt) * x;
        else a[t] += min(k, cnt) * x;
        k -= min(k, cnt);
        q.push(t);
    }
    while (k --) {
        auto t = q.top();
        q.pop();
        if (a[t] < 0) a[t] -= x;
        else a[t] += x;
        q.push(t);
    }
    for (int i = 0; i < n; i ++ ) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
