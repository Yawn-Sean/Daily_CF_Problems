int n;

void solve() {
    // 二分图
    cin >> n;
    vector<ll> x(n), y(n), r(n);
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) == (r[i] + r[j]) * (r[i] + r[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    
    vector<int> color(n, 0);
    
    for (int i = 0; i < n; i ++) {
        if (color[i]) continue;
        queue<int> q;
        color[i] = 1;
        q.push(i);
        bool ok = true;
        int cnt = 1;
        
        while (!em(q)) {
            auto t = q.front();
            q.pop();
            for (auto x : g[t]) {
                if (color[x] == color[t]) ok = false;
                else if (!color[x]) {
                    color[x] = 3 - color[t];
                    q.push(x);
                    if (color[x] == 1) cnt ++;
                    else cnt --;
                }
            }
        }
        
        if (ok and cnt) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}