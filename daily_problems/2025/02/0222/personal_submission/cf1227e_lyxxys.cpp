void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+2,vector<int>(m+2));
    vector<vector<int>> dist(n+2,vector<int>(m+2, inf_int));
    const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    auto chk = [&](const int &i, const int &j)->bool{
        return i > 0 && i <= n && j > 0 && j <= m;
    };

    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            char ch;
            cin >> ch;
            g[i][j] = (ch == 'X');
        }
    }

    vector <array<int,2>> Q((m+2)*(n+2)+1), chuks;
    int lp = 0, rp = -1;
    for (int i = 0; i <= n+1; ++ i){
        for (int j = 0; j <= m+1; ++ j){
            if (!g[i][j]){
                Q[++ rp] = {i, j};
                dist[i][j] = 0;
            } else {
                chuks.push_back({i, j});
            }
        }
    }
    while (lp <= rp){
        const auto &[x, y] = Q[lp++];
        for (int u = 0; u < 8; ++ u){
            int ix = x+dx[u], iy = y+dy[u];
            if (!chk(ix, iy) || dist[ix][iy] <= dist[x][y]+1) continue;
            dist[ix][iy] = dist[x][y]+1;
            Q[++ rp] = {ix, iy};
        }
    }
    vector<vector<int>> vis(n+1,vector<int>(m+1));
    auto chk_mid = [&](int mid)->bool{    
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                vis[i][j] = 0;
            }
        }
        lp = 0, rp = -1;

        for (const auto &[x, y] : chuks){
            if (dist[x][y] >= mid){
                Q[++ rp] = {x, y};
                vis[x][y] = 1;
            }
        }
        for (int i = 0, r = rp; i < mid-1; ++ i, r = rp){
            while (lp <= r){
                const auto &[x, y] = Q[lp++];
                for (int u = 0; u < 8; ++ u){
                    int ix = x+dx[u], iy = y+dy[u];
                    if (!chk(ix, iy) || vis[ix][iy]) continue;
                    vis[ix][iy] = 1;
                    Q[++ rp] = {ix, iy};
                    if (!g[ix][iy]){
                        return false;
                    }
                }
            }
        }
        for (const auto &[x, y] : chuks){
            if (vis[x][y] != g[x][y]){
                return false;
            }
        }
        return true;
    };

    int lo = 1, hi = max(n, m);
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk_mid(mid)) lo = mid;
        else hi = mid-1;
    }

    vector<vector<int>> ans(n+1,vector<int>(m+1));
    for (const auto &[x, y] : chuks){
        if (dist[x][y] >= lo){
            ans[x][y] = 1;
        }
    }
    cout << lo-1 << "\n";
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cout << (ans[i][j]==0 ? '.' : 'X');
        }
        cout << "\n";
    }
}
