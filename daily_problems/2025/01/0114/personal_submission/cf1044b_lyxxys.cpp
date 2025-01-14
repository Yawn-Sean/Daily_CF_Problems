void solve(){
    auto fout = [&](int opt, int x)->int{
        if (opt <= 1){
            cout << (opt==0 ? 'A' : 'B') << " " << x+1 << "\n" << flush;
            int y;
            cin >> y;
            y -= 1;
            return y;
        }
        if (opt == 2) cout << "C " << x+1 << "\n" << flush;
        else cout << "C " << -1 << "\n" << flush;
        return -1;
    };

    int n, k1, k2;
    cin >> n;
    vector<vector<int>> g(n);
    vector <int> vis1(n), vis2(n), color(n), fa(n);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v), g[v].push_back(u);
    }

    cin >> k1;
    for (int i = 0,x; i < k1; ++ i){
        cin >> x;
        x -= 1;
        vis1[x] = 1;
    }
    cin >> k2;
    int b_ask, a_up = -1;
    for (int i = 0,x; i < k2; ++ i){
        cin >> x;
        x -= 1;
        vis2[x] = 1;
        b_ask = x;
    }

    auto dfs_color = [&](auto &&self, int u, int presor, int black)->void{
        if (vis1[u]){
            black = 1;
            if (a_up == -1){
                a_up = u;
            }
        }
        color[u] = black;
        fa[u] = presor;

        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u, black);
        }
    };
    dfs_color(dfs_color, 0, -1, 0);

    int bu = fout(1, b_ask), _;
    if (!color[bu]){
        int au = fout(0, a_up);
        if (vis2[au]) _ = fout(2, a_up);
        else _ = fout(3, -1);
    } else {
        int j = bu;
        while (!vis1[j]){
            j = fa[j];
        }
        assert(j != -1);
        int au = fout(0, j);
        if (vis2[au]) _ = fout(2, j);
        else _ = fout(3, -1);
    }
}
