void solve(){
    const int mod = 1e9+7;
    const int N = 8;
    int n;
    cin >> n;
    vector<vector<char>> g(n+1, vector<char>(3));
    vector<vector<int>> pr(n+2, vector<int>(N)), sf(n+2, vector<int>(N));
    vector <int> chuk(n+2, 7), valid = {0,1,0,0,1,0,0,1};
    array<int,2> loc = {-1, -1};

    for (int j = 0; j < 3; ++ j){
        for (int i = 1; i <= n; ++ i){
            cin >> g[i][j];
            if (g[i][j] == 'O') loc = {i, j};
        }
    }
    for (int i = 1; i <= n; ++ i){
        int cur = 0;
        for (int j = 0; j < 3; ++ j){
            if (g[i][j] == 'X'){
                cur += 1 << j;
            }
        }
        chuk[i] = cur;
    }
    
    pr[0][0] = pr[1][0] = 1;
    sf[n+1][0] = sf[n][0] = 1;

    for (int i = 2; i <= n; ++ i){
        if (i >= loc[0]) break;
        for (int u1 = 0; u1 < 8; ++ u1){
            if (u1&chuk[i-1] || u1&chuk[i]) continue;
            for (int u2 = 0; u2 < 8; ++ u2){
                if ((u2&chuk[i-1]) || u1&u2 || !valid[u1|u2|chuk[i-1]]) continue;
                pr[i][u1] += pr[i-1][u2], pr[i][u1] %= mod;
            }
        }
    }
    for (int i = n-1; i >= 1; -- i){
        if (i <= loc[0]) break;
        for (int u1 = 0; u1 < 8; ++ u1){
            if (u1&chuk[i+1] ||  u1&chuk[i]) continue;
            for (int u2 = 0; u2 < 8; ++ u2){
                if ((u2&chuk[i+1]) || u1&u2 || !valid[u1|u2|chuk[i+1]]) continue;  // u1，u2，chuk[i+1]互不相交
                sf[i][u1] += sf[i+1][u2], sf[i][u1] %= mod;
            }
        }
    }

    auto put = [&](vector<vector<int>>& U, int st, int column, int color)->void{
        for (int i = 0; i < 3; ++ i){
            if (st>>i & 1) U[i][column] = color; 
        }
    };
    const int D[][4] = {{0,0,0,1},{0,1,0,2},{1,0,1,1},{1,1,1,2},{2,0,2,1},{2,1,2,2}};
    auto is_valid = [&](vector<vector<int>> U, int st, int i0, int j0)->bool{
        for (int i = 0; i < 6; ++ i){
            if (st>>i & 1){
                int x1 = D[i][0], y1 = D[i][1], x2 = D[i][2], y2 = D[i][3];
                if (U[x1][y1] != -1 || U[x2][y2] != -1) return false;
                U[x1][y1] = 3, U[x2][y2] = 3;  //3：放横着的格子
            }
        }
        for (int i = 0; i < 3; ++ i){  // 4: 放竖着的格子
            for (int j = 0; j < 3; ++ j){
                if (U[i][j] == -1){
                    if (i+1 < 3 && U[i+1][j] == -1){
                        U[i][j] = U[i+1][j] = 4;
                    } else return false;
                }
            }
        }

        for (int i = 0; i < 3; ++ i){
            for (int j = 0; j < 3; ++ j){
                assert(U[i][j] != -1);
            }
        }
        bool jug = (U[i0][j0-1]==1) || (U[i0][j0+1]==1);
        if (i0 != 1) jug |= U[1][1] = 4;

        return jug;
    };
    auto W = [&](int u1, int u2)->int{ // 左边的状态是 u1，右边的状态是 u2，能够产生多少方案？
        vector<vector<int>> U(3,vector<int>(3, -1));  // -1：未被放的格子
        int i0 = loc[0];
        if ((u1&chuk[i0-1]) || (u2&chuk[i0+1])) return 0;  // 如果 放突出的格子 和 障碍 有冲突，无解
        

        put(U, chuk[i0-1], 0, 0), put(U, chuk[i0], 1, 0), put(U, chuk[i0+1], 2, 0);  // 0：放障碍
        put(U, u1, 0, 1), put(U, u2, 2, 1);  // 1：放突出的格子，构造 9 宫图
        assert(U[loc[1]][1] == -1);
        U[loc[1]][1] = 2;  // 2：放圈圈

        int res = 0;
        for (int i = 0; i < 1<<6; ++ i){
            if (is_valid(U, i, loc[1], 1)){
                res += 1;
            }
        }

        return res;
    };
    int i = loc[0];
    i64 res = 0;

    for (int u1 = 0; u1 < 8; ++ u1){
        for (int u2 = 0; u2 < 8; ++ u2){
            res += 1ll * pr[i-1][u1] * sf[i+1][u2] % mod * W(u1, u2) % mod;
            res %= mod;
        }
    }
    
    cout << res << "\n";
}

