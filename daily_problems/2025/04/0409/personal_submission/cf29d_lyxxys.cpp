void solve(){
    int n, num;
    cin >> n;
    vector<vector<int>> g(n);
    vector<set<int>> st(n);
    vector <int> order, leaf(n), cnts(n);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string line;
    cin.ignore();
    getline(cin, line);
    stringstream sin;
    sin << line;
    while (sin >> num){
        num -= 1;
        order.push_back(num);
    }

    int m = order.size();
    function<void(int,int)> dfs_find, dfs_go;
    dfs_find = [&](int u, int presor)->void{
        cnts[u] = g[u].size()-1;
        if (!u) cnts[u] += 1;

        st[u].insert(u);
        for (auto &v : g[u]){
            if (v == presor) continue;
            dfs_find(v, u);
            for (auto &j : st[v]){
                st[u].insert(j);
            }
        }

    };
    dfs_find(0, -1);
    
    vector <int> ans;
    int j = 0;
    bool jug = 1;
    dfs_go = [&](int u, int presor)->void{
        ans.push_back(u);
        if (j < m && order[j] == u) j += 1;
        while (cnts[u] && jug){
            int nxt = -1;
            for (auto &v : g[u]){
                if (v == presor) continue;
                if (st[v].count(order[j])){
                    nxt = v;
                    break;
                }
            }

            if (nxt == -1){
                jug = 0;
                break;
            }

            dfs_go(nxt, u);
            if (!jug) break;

            ans.push_back(u);
            cnts[u] -= 1;
        }
    };
    dfs_go(0, -1);

    if (jug){
        print(ans, 1);
    } else {
        cout << -1 << "\n";
    }
}
