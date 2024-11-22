void solve()
{
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i ++) mp[i].push_back(i);
    for(int i = 1 ;i <= m; i ++) {
        int x, y; cin >> x >> y;
        mp[x].pb(i + n);//新的一列，在行加
        mp[y].pb(i + n);
    } 
    vector<vector<int>> res(n + 1);
    int st = 1, ed = 1;
    for(int i = 1; i <= n; i ++) {
        cout << mp[i].size() << endl;
        for(auto y : mp[i]) {
            cout << i << ' ' << y << endl;
        }
    }
}
