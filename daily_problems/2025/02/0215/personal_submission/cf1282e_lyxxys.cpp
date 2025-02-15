void solve(){
    int n;
    cin >> n;
    
    auto ID = [&](const int &x, const int &y)->i64{
        if (x > y){
            return 1ll*y*n + x;
        } else {
            return 1ll*x*n + y;
        }
    };
    unordered_map <i64, int> mps;
    int tot = 0;
    auto idx = [&](const int &x, const int &y)->int{
        i64 key = ID(x, y);
        if (!mps.count(key)) mps[key] = tot++;
        return mps[key];
    };
    auto normal = [&](int x, int y, int z)->tuple<int,int,int>{
        if (z < y) swap(y, z);
        if (y < x) swap(x, y);
        if (z < y) swap(y, z);
        return make_tuple(x, y, z);
    };

    vector <int> cnts(3*n), degs(n, 3);  // 拓扑排序的初始度数是3，表示3条边，度小于等于1入队
    vector<vector<int>> g(n), own(3*n);
    vector<array<int,3>> tris;

    for (int i = 0, u,v,t; i < n-2; ++ i){
        cin >> u >> v >> t;
        u -= 1, v -= 1, t -= 1;
        tie(u, v, t) = normal(u, v, t);
        cnts[idx(u, v)] += 1;
        cnts[idx(u, t)] += 1;
        cnts[idx(v, t)] += 1;
        own[idx(u, v)].push_back(i);
        own[idx(u, t)].push_back(i);
        own[idx(v, t)].push_back(i);

        tris.push_back({u,v,t});
    }
    for (auto &[u, id] : mps){
        int x = u/n, y = u%n;
        if (cnts[id] == 1){
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    for (int i = 0; i < n; ++ i){
        assert(g[i].size() == 2);
    }

    vector <int> vts = {0};
    {
        int u = 0, presor = -1;
        while (vts.size() < n){
            for (auto &v : g[u]){
                if (v == presor) continue;
                else {
                    vts.push_back(v);
                    presor = u, u = v;
                    break;
                }
            }
        }
    }

    vector <int> ans, dels(n);
    queue <int> Q;
    for (int i = 1; i <= n; ++ i){
        int id = idx(vts[i-1], vts[i%n]);
        for (auto &j : own[id]){
            degs[j] -= 1;
        }
    }
    for (int i = 0; i < n-2; ++ i){
        if (degs[i] <= 1){
            Q.push(i);
        }
    }

    while (!Q.empty()){
        int i = Q.front();
        Q.pop();
        if (dels[i]) continue;

        ans.push_back(i);
        dels[i] = 1;

        auto [u,v,t] = tris[i];  // 松弛某一个三角形，直到度数小于等于 1
        for (auto &x : own[idx(u,v)]){
            if (dels[x]) continue;
            degs[x] -= 1;
            if (degs[x] <= 1){
                Q.push(x);
            }
        }
        for (auto &x : own[idx(u,t)]){
            if (dels[x]) continue;
            degs[x] -= 1;
            if (degs[x] <= 1){
                Q.push(x);
            }
        }
        for (auto &x : own[idx(v,t)]){
            if (dels[x]) continue;
            degs[x] -= 1;
            if (degs[x] <= 1){
                Q.push(x);
            }
        }
    }

    assert(ans.size() == n-2);
    assert(vts.size() == n);
    for (auto &x : vts){
        x += 1;
    }
    for (auto &x : ans){
        x += 1;
    }
    print(vts);
    print(ans);
}

