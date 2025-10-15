int n, m;

int cal(int x1, int y1, int x2, int y2) {
    if (x1 > x2 or y1 > y2) return 0;
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++) {
            a[i][j] = (s[j] - '0');
        }
    }
    
    PrefixSum2D<int, int> ps(n, m, a);
    
    int res = 20;
    
    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = i1 + 4; i2 < n; i2 ++) {
            // 记录前缀的全变0的代价-当前列变1的代价 + 上下两行 前缀全变黑的代价
            vector<int> pre(m);
            for (int j = 0; j < m; j ++) {
                int cur = ps.sum(i1+1, 0, i2-1, j) - cal(i1+1, j, i2-1, j) + ps.sum(i1+1, j, i2-1, j) + cal(i1, 0, i1, j) - ps.sum(i1, 0, i1, j) + cal(i2, 0, i2, j) - ps.sum(i2, 0, i2, j);
                pre[j] = cur;
            }
            for (int j = 1; j < m; j ++) {
                pre[j] = max(pre[j], pre[j-1]);
            }
            for (int j = 3; j < m; j ++) {
                int cost = ps.sum(i1+1, 0, i2-1, j-1) + cal(i1+1, j, i2-1, j) - ps.sum(i1+1, j, i2-1, j) + cal(i1, 0, i1, j-1) - ps.sum(i1, 0, i1, j-1) + cal(i2, 0, i2, j-1) - ps.sum(i2, 0, i2, j-1);
                chmin(res, cost - pre[j-3]);
            }
        }
    }
    
    cout << res << endl;
    
}