void solve(){
    using ary3 = array<i64,3>;
    using ary2 = array<i64,2>;
    const i64 inf = 1e9;

    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector<ary3> edgs;
    vector<ary2> leader;
    vector <int> chuk(n, -1);
    vector<vector<int>> g(n);

    for (int i = 0,u,v,l; i < m; ++ i){
        cin >> u >> v >> l;
        u -= 1, v -= 1;
        edgs.push_back({u,v,l});
        g[u].push_back(i);
        g[v].push_back(i);
    }

    int leader_tot = -1;
    auto dfs_find_leader = [&](auto &&self, int u, int lead)->void{
        chuk[u] = lead;
        for (auto &id : g[u]){
            int v = edgs[id][0]+edgs[id][1] - u;
            if (chuk[v] != -1) continue;
            self(self, v, lead);
        }
    };
    for (int i = 0; i < n; ++ i){
        if (chuk[i] == -1){
            leader_tot += 1;
            leader.push_back({0, i});
            dfs_find_leader(dfs_find_leader, i, leader_tot);
        }
    }


    for (auto &[u, v, l] : edgs){
        assert(chuk[u] == chuk[v]);
        leader[chuk[u]][0] += l;
    }

    leader_tot += 1;
    if (leader_tot < q || p < leader_tot-q){
        cout << "NO\n";
        return;
    }

    vector <ary2> ans;
    int cnt1 = leader_tot - q, cnt2 = p - cnt1;
    priority_queue <ary2,vector<ary2>,greater<ary2>> pq;
    for (auto &u : leader){
        pq.push(u);
    }

    while (cnt1 > 0){
        auto u = pq.top();
        pq.pop();
        auto v = pq.top();
        pq.pop();

        i64 d = u[0]+v[0], dis = d + min(inf, d+1);
        ans.push_back({u[1], v[1]});
        edgs.push_back({u[1], v[1], dis});
        pq.push({dis, u[1]});

        cnt1 -= 1;
    }

    int tot = edgs.size();
    if (tot == 0 && cnt2 > 0){  // 至少存在一条活边，否则不能够覆盖任意一条边
        cout << "NO\n";
        return;
    }

    vector <int> idx(tot);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return edgs[u][2] > edgs[v][2];
    });

    bool jug = 0;
    ary2 last;
    for (int id = 0; id < tot && cnt2; ++ id){  // 贪心的选择更大的大于1000的边去覆盖
        int i = idx[id];
        auto &[u, v, l] = edgs[i];
        if (l >= 1000){
            ans.push_back({u, v});
            last = {u, v}, jug = 1;
            cnt2 -= 1;
        } else {
            if (!jug){
                last = {u, v};
            }
            break;
        }
    }
    while (cnt2 > 0){
        ans.push_back(last);
        cnt2 -= 1;
    }

    assert(ans.size() == p);
    
    cout << "YES\n";
    for (auto &[u, v] : ans){
        cout << u+1 << " " << v+1 << "\n";
    }
}
