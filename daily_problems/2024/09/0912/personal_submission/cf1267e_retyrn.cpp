int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    cin >> a;
    
    vector<int> res;
    int mn = inf;
    for (int i = 0; i < n - 1; i ++) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int sum = 0;
        for (int j = 0; j < m; j ++) {
            int val = a[j][i] - a[j][n - 1];
            q.emplace(val, j + 1);
            sum += val;
        }
        vector<int> ans;
        while (sum < 0) {
            ans.push_back(q.top().se);
            sum -= q.top().fi;
            q.pop();
        }
        if (sz(ans) < mn) {
            mn = sz(ans);
            res = move(ans);
        }
    }
    cout << mn << endl;
    cout << res << endl;
}