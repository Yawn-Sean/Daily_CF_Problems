void solve(){
    int n, m, p, q;
    cin >> n >> m >> q >> p;
    vector<string> g(n);
    vector<vector<i64>> dist(n,vector<i64>(m));
    vector<vector<int>> vis(n,vector<int>(m));
    for (auto &chs : g){
        cin >> chs;
    }

    vector <int> orgs;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (isupper(g[i][j])){
                orgs.push_back(i*m+j);
            }
        }
    }

    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    const int dx[] = {-1, 0, 1, 0, -1};

    vector <int> Q(n*m);

    for (auto &o : orgs){
        int ox = o/m, oy = o%m;
        int d = q * (g[ox][oy]-'A'+1);

        int tp = -1, hp = 0;
        Q[++ tp] = o;
        vis[ox][oy] = 1;

        for (int anchor = tp; tp >= hp; anchor = tp){
            for (int i = hp; i <= anchor; ++ i){
                int u = Q[i];
                int x = u/m, y = u%m;
                dist[x][y] += d;
            }
            d /= 2;
            if (!d) break;

            while (anchor >= hp){
                int u = Q[hp++];
                int x = u/m, y = u%m;
                for (int i = 0; i < 4; ++ i){
                    int ix = x+dx[i], iy = y+dx[i+1];
                    if (!chk(ix, iy) || vis[ix][iy] || g[ix][iy]=='*') continue;
                    vis[ix][iy] = 1;
                    Q[++ tp] = ix*m+iy;
                }
            }
        }
        for (int i = 0; i <= tp; ++ i){
            int u = Q[i];
            int x = u/m, y = u%m;
            vis[x][y] = 0;
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (dist[i][j] > p){
                res += 1;
            }
        }
    }

    cout << res << "\n";
}
