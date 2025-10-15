struct Graph {
    const int inf = 1e9;
    vector<vector<Edge>> edge;
    vector <int> pre, lst, f, dis, vis;
    int S, T;
    Graph(){}
    Graph(int n): edge(n+1), pre(n+1), lst(n+1), f(n+1), dis(n+1), vis(n+1) {}
    void set(int s, int t){
        S = s, T = t;
    }
    void add(int a, int b, int c, int d){
        int ra = edge[a].size(), rb = edge[b].size();
        edge[a].push_back({b, c, d, rb}), edge[b].push_back({a, 0, -d, ra});
    }
    bool spfa(){
        fill(dis.begin(), dis.end(), inf), fill(f.begin(), f.end(), 0);
        queue<int> Q;
        Q.push(S), dis[S] = 0, f[S] = inf;
        while (!Q.empty()){
            int t = Q.front();
            Q.pop();
            vis[t] = false;
            for (int i = 0; i < edge[t].size(); ++ i){
                int ver = edge[t][i].ed, cost = edge[t][i].cost, len = edge[t][i].len;
                if (len && dis[ver] > dis[t]+cost){
                    dis[ver] = dis[t]+cost;
                    pre[ver] = i, lst[ver] = t;
                    f[ver] = min(f[t], len);
                    if (!vis[ver]){
                        Q.push(ver);
                        vis[ver] = true;
                    }
                }
            }
        }
        return f[T] > 0;
    }
    array<int,2> EK(){
        int flow = 0, cost = 0;
        while (spfa()){
            int t = f[T];
            flow += t, cost += t*dis[T];
            for (int i = T; i != S; i = lst[i]){
                auto &u = edge[lst[i]][pre[i]];
                u.len -= t;
                edge[i][u.id].len += t;
            }
        }
        return {flow, cost};
    }
};

void solve(){
    string tar;
    int n;
    cin >> tar >> n;

    Graph G(n+28);
    const int src = n+26, fini = n+27;
    G.set(src, fini);

    for (int i = 0, d; i < n; ++ i){
        string s;
        cin >> s >> d;
        vector <int> cnts(26);
        for (auto &ch : s){
            cnts[ch-'a'] += 1;
        }

        for (int j = 0; j < 26; ++ j){
            G.add(i, n+j, cnts[j], i+1);
        }
        G.add(src, i, d, 0);
    }

    vector <int> cnts(26);
    for (auto &ch : tar){
        cnts[ch-'a'] += 1;
    }
    for (int i = 0; i < 26; ++ i){
        G.add(n+i, fini, cnts[i], 0);
    }

    auto res = G.EK();
    if (res[0] != tar.size()){
        cout << -1 << "\n";
    } else {
        cout << res[1] << "\n";
    }
}
