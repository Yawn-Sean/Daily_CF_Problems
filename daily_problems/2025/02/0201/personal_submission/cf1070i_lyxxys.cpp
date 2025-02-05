struct Edge {
    int to, dis, id;
};
struct Graph {
    vector<vector<Edge>> g;
    vector <int> dep, cur;
    int S, T;
    Graph(){}
    Graph(int n): g(n+1), dep(n+1), cur(n+1) {}
    void set(int s, int t){
        S = s, T = t;
    }
    void add(int a, int b, int c){
        int ra = g[a].size(), rb = g[b].size();
        g[a].push_back({b, c, rb}), g[b].push_back({a, 0, ra});
    }
    bool bfs(){
        fill(dep.begin(), dep.end(), -1);
        queue <int> Q;
        Q.push(S), dep[S] = 0;
        while (!Q.empty()){
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < g[u].size(); ++ i){
                int to = g[u][i].to;
                if (dep[to] == -1 && g[u][i].dis){
                    dep[to] = dep[u] + 1;
                    Q.push(to);
                }
            }
        }
        return (dep[T] != -1);
    }
    int dfs(int u, int limit){
        if (u == T) return limit;
        for (int i = cur[u]; i < g[u].size(); ++ i){
            cur[u] = i;  // 当前弧优化
            int to = g[u][i].to;
            if (dep[to] == dep[u] + 1 && g[u][i].dis){
                int t = dfs(to, min(g[u][i].dis, limit));
                if (t){
                    g[u][i].dis -= t;
                    g[to][g[u][i].id].dis += t;
                    return t;
                } else dep[to] = -1;
            }
        }
        return 0;
    }
    int dinic(){
        int r = 0, flow;
        while (bfs()){
            fill(cur.begin(), cur.end(), 0);
            while (flow = dfs(S, 1e9)){
                r += flow;
            }
        }
        return r;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n+1);
    Graph gs(n+m+2);

    const int src = 0, tar = n+m+1;
    gs.set(src, tar);

    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);   
    }

    for (int i = 0; i < m; ++ i){
        gs.add(n+i+1, tar, 1);
    }
    int tot_f = 0;
    for (int i = 1; i <= n; ++ i){
        int flow = 2*max((int)g[i].size()-k, 0);
        tot_f += flow;
        // cout << flow << "\n";
        gs.add(src, i, flow);
        for (auto &id : g[i]){
            gs.add(i, n+id+1, 1);
        }
    }

    vector <int> ans(m);
    if (gs.dinic() == tot_f){
        int id_tot = 0;
        for (int i = 1; i <= n; ++ i){
            vector <int> colrs;
            for (auto &it : gs.g[i]){
                if (it.dis == 0 && it.to > n){
                    colrs.push_back(it.to-n-1);
                }
            }
            assert(colrs.size()%2 == 0);
            for (int i = 0; i < colrs.size(); i += 2){
                int u1 = colrs[i], u2 = colrs[i+1];
                ans[u1] = ans[u2] = ++ id_tot;
            }
        }
        for (int i = 0; i < m; ++ i){
            if (ans[i] == 0){
                ans[i] = ++ id_tot;
            }
        }
    }
    print(ans);
}
