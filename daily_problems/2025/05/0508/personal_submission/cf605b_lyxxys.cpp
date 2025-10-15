void solve(){
    int n, m;
    cin >> n >> m;
    vector<array<int,2>> edgs, ans(m);
    for (int i = 0,w,b; i < m; ++ i){
        cin >> w >> b;
        edgs.push_back({w, b});
    }
    vector <int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return edgs[u][0] != edgs[v][0] ? edgs[u][0] < edgs[v][0] : edgs[u][1] > edgs[v][1];
    });
    
    vector <int> stk;
    for (int i = n; i > 1; -- i){
        stk.push_back(i);
    }
    vector<array<int,2>> store;
    int cnt = 0;

    int u = 1;
    for (auto &id : idx){  // 模拟最小生成树的过程，根据是否是最小生成树的边来向外扩展
        if (edgs[id][1] == 1){
            int v = stk.back();
            stk.pop_back();
            ans[id] = {u, v};
            u = v;
            for (int i = 1; i < u-1 && cnt < m; ++ i){
                store.push_back({i, u});
                cnt += 1;
            }
        } else {
            if (store.empty()){
                cout << -1 << "\n";
                return;
            }
            ans[id] = store.back();
            store.pop_back();
        }
    }

    for (auto &[u, v] : ans){
        cout << u << " " << v << "\n";
    }
}
