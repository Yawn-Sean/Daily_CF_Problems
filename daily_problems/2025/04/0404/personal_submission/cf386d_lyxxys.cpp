void solve(){
    int n, s0, s1, s2;
    cin >> n >> s0 >> s1 >> s2;
    auto id = [&](int x, int y, int z)->int{
        return x*n*n + y*n + z;
    };
    s0 -= 1, s1 -= 1, s2 -= 1;
    set<array<int,3>> tars = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
    vector<array<int,3>> pre(n*n*n, {-1,-1,-1});
    vector <int> f(n*n*n, inf_int);

    vector<vector<int>> g(n,vector<int>(n));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            char ch;
            cin >> ch;
            if (ch == '*') g[i][j] = -1;
            else g[i][j] = ch-'a';
        }
    }
    priority_queue <array<int,2>, vector<array<int,2>>, greater<>> pq;

    f[id(s0, s1, s2)] = 0;
    pq.push({0, id(s0,s1,s2)});
    while (!pq.empty()){
        auto [dis, u] = pq.top();
        pq.pop();
        if (dis > f[u]) continue;
        int i1 = u/(n*n), i2 = u%(n*n)/n, i3 = u%n;
        // cout << i1 << " " << i2 << " "<< i3 << "\n";
        for (int to = 0; to < n; ++ to){
            if (to == i1 || to == i2 || to == i3) continue;
            if (g[i1][to] == g[i2][i3]){
                int nxt = id(to, i2, i3);
                if (f[nxt] > f[u]+1){
                    f[nxt] = f[u]+1;
                    pre[nxt] = {i1, i2, i3};
                    pq.push({f[nxt], nxt});
                }
            }
            if (g[i2][to] == g[i1][i3]){
                int nxt = id(i1, to, i3);
                if (f[nxt] > f[u]+1){
                    f[nxt] = f[u]+1;
                    pre[nxt] = {i1, i2, i3};
                    pq.push({f[nxt], nxt});
                }
            }
            if (g[i3][to] == g[i1][i2]){
                int nxt = id(i1, i2, to);
                if (f[nxt] > f[u]+1){
                    f[nxt] = f[u]+1;
                    pre[nxt] = {i1, i2, i3};
                    pq.push({f[nxt], nxt});
                }
            }
        }
    }

    // return;
    vector<array<int,2>> ans;
    int res = inf_int;
    int i, j, k;
    for (auto &[t1,t2,t3] : tars){
        if (res > f[id(t1,t2,t3)]){
            res = f[id(t1,t2,t3)];
            i = t1, j = t2, k = t3;
        }
    }

    if (res == inf_int){
        cout << -1 << "\n";
    } else {
        while (pre[id(i,j,k)][0] != -1){
            auto [x,y,z] = pre[id(i,j,k)];
            if (x != i){
                ans.push_back({x+1, i+1});
            } else if (y != j){
                ans.push_back({y+1, j+1});
            } else {
                ans.push_back({z+1, k+1});
            }
            i = x, j = y, k = z;
        }
        reverse(ans.begin(), ans.end());
        cout << res << "\n";
        assert(res == ans.size());
        for (auto &[u, v] : ans){
            cout << u << " " << v << "\n";
        }
    }
}
