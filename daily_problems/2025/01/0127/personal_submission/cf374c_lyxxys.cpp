void solve(){
    int n, m;
    cin >> n >> m;
    auto chk = [&](int i, int j)->bool{
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    const int dx[] = {-1,0,1,0,-1};
    vector<vector<int>> g(n,vector<int>(m));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char ch;
            cin >> ch;
            if (ch == 'D') g[i][j] = 0;
            if (ch == 'I') g[i][j] = 1;
            if (ch == 'M') g[i][j] = 2;
            if (ch == 'A') g[i][j] = 3;
        }
    }

    vector<vector<int>> edges(n*m);
    vector <int> degs(n*m);
    auto ID = [&](int i, int j)->int{
        return i*m + j;
    };
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            for (int k = 0; k < 4; ++ k){
                int x = i+dx[k], y = j+dx[k+1];
                if (chk(x, y) && g[x][y] == (g[i][j]+1)%4){
                    edges[ID(i,j)].push_back(ID(x,y));
                    degs[ID(x,y)] += 1;
                }
            }
        }
    }

    vector <int> Q(n*m+1), f(n*m+1);
    int tp = -1, hp = 0, cnt = 0;
    for (int i = 0; i < n*m; ++ i){
        if (!degs[i]){
            Q[++ tp] = i;
            if (g[i/m][i%m] == 0){
                f[i] = 1;
            } else {
                f[i] = -inf_int;
            }
            cnt += 1;
        }
    }

    while (tp >= hp){
        int u = Q[hp++];
        for (auto &v : edges[u]){
            -- degs[v];
            fmax(f[v], f[u]+1);
            if (degs[v] == 0){
                Q[++ tp] = v;
                cnt += 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n*m; ++ i){
        fmax(res, f[i]);
    }

    if (cnt < n*m){
        cout << "Poor Inna!\n";
    } else if (res < 4){
        cout << "Poor Dima!\n";
    } else cout << res/4 << "\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    while (_--) solve();
    return 0;
}
