
void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector <int> edgs, degs(n), ans(n-1);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(i);
        g[v].push_back(i);
        edgs.push_back(u+v);
    }
    for (int i = 0; i < n; ++ i){
        degs[g[i].size()] += 1;
    }
    int m = n-1;
    for (int i = n-1, cur = 0; i >= 0; -- i){
        if (cur <= k){
            m = i;
        }
        cur += degs[i];
    }

    auto dfs_find = [&](auto &&self, int u, int presor, int last)->void{
        vector <int> curs;
        for (auto &id : g[u]){
            int v = edgs[id]-u;
            if (v == presor) continue;
            curs.push_back(id);
        }

        if (g[u].size() <= m){
            int tot = last==1 ? 2 : 1;
            for (auto &id : curs){
                ans[id] = tot;
                ++ tot;
                if (tot == last) ++ tot;
            }
        } else {
            for (auto &id : curs){
                ans[id] = 1;
            }
        }

        for (auto &id : g[u]){
            int v = edgs[id]-u;
            if (v == presor) continue;
            self(self, v, u, ans[id]);
        }
    };
    dfs_find(dfs_find, 0, -1, -1);
    cout << m << "\n";
    print(ans);
}

