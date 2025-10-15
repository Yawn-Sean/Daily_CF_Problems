void solve(){
    int n;
    cin >> n;
    vector<unordered_set<int>> g(n);
    for (int i = 0,u,v; i < 2*n; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 0; i < n; ++ i){
        if (g[i].size() != 4){
            cout << -1 << "\n";
            return;
        }
    }

    auto find = [&](int u, int v)->bool{
        vector <int> vis(n);
        vector <int> order = {u, 0, v};
        vis[u] = 1, vis[v] = 1, vis[0] = 1;

        for (int i = 0; i < n-3; ++ i){
            int x = order.back(), y = order[order.size()-2];
            for (auto &z : g[x]){
                if (g[z].count(y) && !vis[z]){
                    order.push_back(z);
                    vis[z] = 1;
                    break;
                }
            }
        }

        if (order.size() != n) return false;
        
        print(order, 1);
        return true;
    };

    for (auto &u : g[0]){
        for (auto &v : g[0]){
            if (u != v && g[v].count(u)){
                if (find(u, v)){
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
}
