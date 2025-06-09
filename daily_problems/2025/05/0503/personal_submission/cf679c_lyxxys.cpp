
void solve(){
    int n, k;
    cin >> n >> k;
    auto ID = [&](int x, int y)->int{
        return x*n + y;
    };
    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    vector<vector<int>> g(n,vector<int>(n)), acc(n+1,vector<int>(n+1));
    vector<vector<int>> roots(n,vector<int>(n));
    vector<int> cnts(n*n);

    vector <int> p(n*n), sz(n*n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            char ch;
            cin >> ch;
            g[i][j] = ch == '.';
            if (g[i][j]) sz[ID(i,j)] = 1;
            else acc[i+1][j+1] = 1;
        }
    }

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
            sz[x] += sz[y];
            p[y] = x;
        }
    };

    // 预处理前缀和数组
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            acc[i][j] += acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
        }
    }
    auto w = [&](int i1, int j1, int i2, int j2)->int{
        i1 += 1, j1 += 1, i2 += 1, j2 += 1;
        return acc[i2][j2] - acc[i1-1][j2] - acc[i2][j1-1] + acc[i1-1][j1-1];
    };
    
    // 预处理 根数组
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (g[i][j]){
                if (i && g[i-1][j]) merge(ID(i-1, j), ID(i, j));
                if (j && g[i][j-1]) merge(ID(i, j-1), ID(i, j));
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            roots[i][j] = root(ID(i, j));
        }
    }
    
    int res = 0, cur = 0;
    auto chge = [&](int x, int y, int d)->void{
        if (!chk(x, y)) return;
        int u = roots[x][y];
        if (d == 1){
            if (!cnts[u]) cur += sz[u];
            cnts[u] += 1;
        } else {
            cnts[u] -= 1;
            if (!cnts[u]) cur -= sz[u];
        }
    };

    for (int i = 0; i < k; ++ i){
        for (int j = 0; j < k; ++ j){
            chge(i, j, 1);
        }
    }
    for (int i = 0; i < k; ++ i){
        chge(i, k, 1);
        chge(k, i, 1);
    }

    int ux = 0, uy = 0;
    auto fchge = [&]()->void{
        fmax(res, cur + w(ux, uy, ux+k-1, uy+k-1));
    };

    fchge();
    while (true){  // 考虑增量的维护正方形
        if (uy == 0){
            while (uy < n-k){  // 向右走
                for (int i = 0; i < k; ++ i){
                    chge(ux+i, uy-1, -1);
                    chge(ux+i, uy+k+1, 1);
                }
                chge(ux-1, uy, -1), chge(ux+k, uy, -1);
                chge(ux-1, uy+k, 1), chge(ux+k, uy+k, 1);
                uy += 1;
                fchge();
            }
        } else {
            while (uy > 0){  // 向左走
                for (int i = 0; i < k; ++ i){
                    chge(ux+i, uy-2, 1);
                    chge(ux+i, uy+k, -1);
                }
                chge(ux-1, uy-1, 1), chge(ux+k, uy-1, 1);
                chge(ux-1, uy+k-1, -1), chge(ux+k, uy+k-1, -1);
                uy -= 1;
                fchge();
            }
        }
        // 向下走
        for (int i = 0; i < k; ++ i){
            chge(ux-1, uy+i, -1);
            chge(ux+k+1, uy+i, 1);
        }
        chge(ux, uy-1, -1), chge(ux, uy+k, -1);
        chge(ux+k, uy-1, 1), chge(ux+k, uy+k, 1);
        ux += 1;
        if (ux > n-k) break;
        fchge();
    }

    cout << res << "\n";
}

