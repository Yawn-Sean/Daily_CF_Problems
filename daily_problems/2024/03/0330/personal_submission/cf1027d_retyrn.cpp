int n;

//-----------------------function-----------------------

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i ++) {
        cin >> cost[i];
    }
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] --;
    }
    
    // 拓扑排序 选择环上的点最小值
    vector<int> d(n, 0);
    for (int i = 0; i < n; i ++) {
        d[a[i]] += 1;
    }
    // dbg(d);
    queue<int> q;
    for (int i = 0; i < n; i ++) {
        if (d[i] == 0) q.emplace(i);
    }
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        if (-- d[a[t]] == 0) {
            q.emplace(a[t]);
        }
    }
    
    // dbg(d);
    function<int(int)> dfs = [&](int u) {
        if (d[u] <= 0) return inf;
        d[u] = 0;
        return min(dfs(a[u]), cost[u]);
    };
    
    int res = 0;
    for (int i = 0; i < n; i ++) {
        if (d[i] > 0) res += dfs(i);
    }
    cout << res << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}