void solve(){
    int n, m;
    cin >> n >> m;
    vector <string> g(n);
    for (auto &chs : g){
        cin >> chs;
    }

    vector <int> p(n*m), sz(n*m, 1);
    iota(p.begin(), p.end(), 0);
    auto root = [&](int x)->int{
        int y = x;
        while (p[y] != y){
            y = p[y];
        }
        while (p[x] != x){
            int &j = p[x];
            x = p[x];
            j = y;
        }
        return y;
    };
    auto merge = [&](int x, int y)->void{
        x = root(x), y = root(y);
        if (x != y){
            p[y] = x;
            sz[x] += sz[y];
        }
    };

    auto ID = [&](int x, int y)->int{
        return x*m + y;
    };

    const int dx[] = {-1, 0, 1, 0, -1};
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (g[i][j] == '.'){
                for (int u = 0; u < 4; ++ u){
                    int ux = i+dx[u], uy = j+dx[u+1];
                    if (ux >= 0 && ux < n && uy >= 0 && uy < m && g[ux][uy] == '.'){
                        merge(ID(i, j), ID(ux, uy));
                    }
                }
            }
        }
    }

    vector<string> ans = g;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (g[i][j] == '*'){
                set <int> st;
                for (int u = 0; u < 4; ++ u){
                    int ux = i+dx[u], uy = j+dx[u+1];
                    if (ux >= 0 && ux < n && uy >= 0 && uy < m && g[ux][uy] == '.'){
                        st.insert(root(ID(ux, uy)));
                    }
                }
                int cur = 1;
                for (auto &x : st){
                    cur += sz[x];
                }
                cur %= 10;
                ans[i][j] = char(cur+'0');
            }
        }
    }

    for (int i = 0; i < n; ++ i){
        cout << ans[i] << "\n";
    }
}
