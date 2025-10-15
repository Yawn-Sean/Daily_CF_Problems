void solve(){
    const int N = 8;
    int n;
    cin >> n;
    vector<vector<int>> g(N,vector<int>(N));
    set <array<int,2>> st;
    
    bool revse = n > 32;

    for (int i = 0; i < n; ++ i){
        char ch1, ch2;
        cin >> ch1 >> ch2;
        swap(ch1, ch2);
        int x = ch1-'1', y = ch2-'a';
        g[x][y] = 1;
    }
    for (int i = 0; i < 8; ++ i){
        for (int j = 0; j < 8; ++ j){
            if (g[i][j] == !revse){
                st.insert({i, j});
            }
        }
    }
    vector<array<int,4>> ans;
    const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < N && y >= 0 && y < N;
    };
    
    static array<int,2> pre[N][N];
    static int vis[N][N];
    auto bfs_path = [&](int x, int y, int tar_x, int tar_y)->bool{
        for (int i = 0; i < N; ++ i){
            for (int j = 0; j < N; ++ j){
                pre[i][j] = {-1, -1};
                vis[i][j] = 0;
            }
        }

        queue<array<int,2>> Q;
        Q.push({x, y});
        
        while (!Q.empty()){
            if (vis[tar_x][tar_y]) break;
            auto it = Q.front();
            Q.pop();
            int ox = it[0], oy = it[1];
            for (int i = 0; i < 8; ++ i){
                int ix = ox+dx[i], iy = oy+dy[i];
                if (!chk(ix, iy) || g[ix][iy]==!revse || vis[ix][iy]) continue;
                Q.push({ix, iy});
                pre[ix][iy] = {ox, oy};
                vis[ix][iy] = 1;
            }
        }
        return vis[tar_x][tar_y];
    };
    auto find = [&](int tar_x, int tar_y)->void{
        array<int,2> j;
        for (auto &i : st){
            if (bfs_path(i[0], i[1], tar_x, tar_y)){  // 从 i[0],i[1] 走到 tar_x, tar_y
                j = i;
                break;
            }
        }

        g[j[0]][j[1]] = revse, g[tar_x][tar_y] = !revse;
        st.erase(j);
        vector<array<int,4>> curs;
        int x = tar_x, y = tar_y;

        while (x != j[0] || y != j[1]){
            int lst_x = pre[x][y][0], lst_y = pre[x][y][1];
            if (!revse) curs.push_back({lst_x, lst_y, x, y});
            else curs.push_back({x, y, lst_x, lst_y});
            x = lst_x, y = lst_y;
        }
        reverse(curs.begin(), curs.end());
        for (auto &it : curs){
            ans.push_back(it);
        }
    };


    int cnt = 0;
    if (revse){
        for (int i = N-1; i >= 0 && cnt < 64-n; -- i){
            for (int j = N-1; j >= 0 && cnt < 64-n; -- j){
                if (!g[i][j]){
                    st.erase({i, j});
                } else {
                    find(i, j);
                }
                cnt += 1;
            }
        }
    } else {
        for (int i = 0; i < N && cnt < n; ++ i){
            for (int j = 0; j < N && cnt < n; ++ j){
                if (g[i][j]){
                    st.erase({i, j});
                } else {
                    find(i, j);
                }
                cnt += 1;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &it : ans){
        cout << char(it[1]+'a') << it[0]+1;
        cout << "-";
        cout << char(it[3]+'a') << it[2]+1;
        cout << "\n";
    }
}
