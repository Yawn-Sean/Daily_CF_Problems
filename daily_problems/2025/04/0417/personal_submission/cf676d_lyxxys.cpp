void solve(){
    using ary3 = array<int,3>;
    vector <int> anti = {2, 3, 0, 1};
    const int dx[] = {-1, 0, 1, 0, -1};

    int n, m;
    cin >> n >> m;
    
    auto rotate = [&](int x)->int{
        return ((x << 1) | ((x & 8) ? 1 : 0)) & 15;
    };
    auto rool = [&](int x, int cnt)->int{
        for (int i = 0; i < cnt; ++ i){
            x = rotate(x);
        }
        return x;
    };
    auto fint = [&](vector <int> U)->int{
        int res = 0;
        for (auto &x : U){
            res |= 1 << x;
        }
        return res;
    };
    // 二进制右到左：上右下左
    auto chge = [&](char ch)->int{
        if (ch == '+') return fint({0,1,2,3});
        else if (ch == '-') return fint({1, 3});
        else if (ch == '|') return fint({0, 2});
        else if (ch == '^') return fint({0});
        else if (ch == '>') return fint({1});
        else if (ch == 'v') return fint({2});
        else if (ch == '<') return fint({3});
        else if (ch == 'L') return fint({0, 1, 2});
        else if (ch == 'R') return fint({0, 2, 3});
        else if (ch == 'U') return fint({1, 2, 3});
        else if (ch == 'D') return fint({0, 1, 3});
        else return 0;

    };
    auto chk_go = [&](int u, int v, int dir)->int{
        return (u >> dir & 1) && (v >> anti[dir] & 1);
    };
    auto ID = [&](int x, int y)->int{
        return x*m + y;
    };
    auto ufix = [&](int u)->array<int,2>{
        return array<int,2>{u/m, u%m};
    };
    
    
    vector <int> g(n*m);
    vector<array<int,4>> f(n*m, {inf_int, inf_int, inf_int, inf_int});
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char ch;
            cin >> ch;
            g[ID(i, j)] = chge(ch);
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx -= 1, sy -= 1, tx -= 1, ty -= 1;
    priority_queue <ary3,vector<ary3>,greater<ary3>> pq;
    pq.push({0, ID(sx,sy), 0});
    f[ID(sx,sy)][0] = 0;

    while (!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if (top[0] > f[top[1]][top[2]]) continue;

        int u = top[1];
        auto [x, y] = ufix(u);
        int dir = top[2];

        for (int i = dir+1, dis = 1; i < dir+4; ++ i, ++ dis){
            int j = i%4;
            if (f[u][j] > f[u][dir]+dis){
                f[u][j] = f[u][dir]+dis;
                pq.push({f[u][j], u, j});
            }
        }

        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dx[i+1];
            if (ix >= 0 && ix < n && iy >= 0 && iy < m){
                int v = ID(ix, iy);
                if (f[v][dir] > f[u][dir]+1 && chk_go(rool(g[u], dir), rool(g[v], dir), i)){
                    f[v][dir] = f[u][dir]+1;
                    pq.push({f[v][dir], v, dir});
                }
            }
        }
    }

    int res = inf_int;
    for (int i = 0; i < 4; ++ i){
        fmin(res, f[ID(tx,ty)][i]);
    }

    if (res == inf_int){
        cout << -1 << "\n";
    } else {
        cout << res << "\n";
    }
}
