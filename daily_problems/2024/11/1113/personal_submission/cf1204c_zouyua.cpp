void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n), dis(n, vector<int> (n, 1e7));
    for(int i = 0; i < n;i ++) {
        string s; cin >> s;
        dis[i][i] =0;
        for(int j = 0; j < n; j ++) {
            if(s[j] == '1') {
                g[i].pb(j);
                dis[i][j] = 1;
            }
        }
    }
    for(int k = 0; k < n; k ++) 
        for(int i = 0; i < n; i ++) 
            for(int j = 0; j < n; j ++) 
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int m; cin >> m;
    vector<int> p(m);
    for(auto &x : p) {
        cin >> x;
        x --;
    }
    vector<int> res;
    res.pb(p[0]);
    int pre = p[0]; 
    for(int i = 1; i + 1 < m; i ++) {
        int x = p[i], nxt = p[i + 1];
        if(dis[pre][x] + dis[x][nxt] > dis[pre][nxt]) {//不是最优的点不会被优化点，一定被选，pre一定是选过的前一个，不是原序列的前一个
            res.pb(x);
            pre = x;
        }
    }
    res.pb(p.back());
    cout << res.size() << endl;
    for(auto &x : res) cout << ++ x << ' ';
}
