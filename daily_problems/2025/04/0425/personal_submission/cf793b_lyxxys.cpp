void solve(){
    const int N = 1000;
    static int f[N][N][4][3];

    int n, m;
    cin >> n >> m;
    vector <string> g(n);
    for (auto &chs : g){
        cin >> chs;
    }

    int sx, sy, tx, ty;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (g[i][j] == 'S'){
                tie(sx, sy) = tuple<int,int>(i, j);
            } else if (g[i][j] == 'T'){
                tie(tx, ty) = tuple<int,int>(i, j);
            }
        }
    }

    const int dx[] = {-1, 0, 1, 0, -1};
    auto chk = [&](int i, int j)->bool{
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    queue <array<int,4>> Q;
    for (int i = 0; i < 4; ++ i){
        Q.push({sx,sy,i,0});
    }

    while (!Q.empty()){
        auto [x, y, dir, k] = Q.front();
        Q.pop();
        if (f[x][y][dir][k]) continue;
        f[x][y][dir][k] = 1;

        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dx[i+1];
            if (chk(ix, iy) && g[ix][iy] != '*'){
                if (i == dir){
                    if (!f[ix][iy][i][k]){
                        Q.push({ix,iy,i,k});
                    }
                } else {
                    if (k < 2 && !f[ix][iy][i][k+1]){
                        Q.push({ix,iy,i,k+1});
                    }
                }
            }
        }
    }


    for (int i = 0; i < 4; ++ i){
        for (int j = 0; j < 3; ++ j){
            if (f[tx][ty][i][j]){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
