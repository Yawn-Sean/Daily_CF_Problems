int main()
{
    int n; cin >> n;
    int root = 0;
    vector<int> d(n + 1), st(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i ++) {
        int p; cin >> p;
        if(p == 0) {
            root = i;
        } else {
            g[p].push_back(i);
            g[i].push_back(p);
            d[i] ^= 1;
            d[p] ^= 1;
        }
    }
    if(n % 2 == 0) return cout << "NO", 0;
    vector<int> res;
    auto dfs2 = [&](auto &&dfs2, int u, int fa) ->void{
        res.pb(u); 
        st[u] = 1;     
        for(auto v : g[u]) {
            if(v == fa || st[v]) continue;
            dfs2(dfs2, v, u);
        }
    };
    auto dfs1 = [&](auto &&dfs1, int u, int fa) ->void{
        for(auto v : g[u]) {
            if(v == fa || st[v])continue;
            dfs1(dfs1, v, u);
        }
        if(d[u] == 0) {
            d[fa] ^= 1;
            dfs2(dfs2, u, fa);
        }        
    };
    dfs1(dfs1, root, 0);
    cout << "YES" << endl;
    for(auto &x : res) cout << x << endl;
    return 0;
}
