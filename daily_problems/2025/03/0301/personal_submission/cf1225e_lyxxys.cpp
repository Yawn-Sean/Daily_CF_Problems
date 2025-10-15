/*
    f1[i][j] 表示在 i、j 这个格子且上一步是从上面转移过来
    f2[i][j] 表示在 i、j 这个格子且上一步是从左边转移过来
    一个岩石 只可以发生 向右走 或者 向下走，不能两件事情同时发生。
    岩石总是连续的向右走 或者 连续的向下走。
    从上面转移过来的格子，右边的岩石总是固定的：
        我们一旦从上面转移，右边不能走的格子立即减去当前的方案

    从左边转移过来的格子，下面的岩石总是固定的：
        我们一旦从左边转移，下面不能走的格子立即减去当前的方案

    我们 将 点状态强制转向维护转移
    由于方案总是竖着一段、横着一段的累积，我们只需要减去不能统计贡献的格子
*/
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    vector<vector<int>> f1(n+5,vector<int>(m+5)), f2(n+5,vector<int>(m+5));
    vector<vector<int>> R(n+5,vector<int>(m+5)), D(n+5,vector<int>(m+5));
    const int mod = 1e9+7;
    auto AD = [&](int &x, const i64 &y)->void{
        x = (x+y) % mod;
        if (x < 0) x += mod;
    };
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> g[i][j];
        }
    }
    if (g[1][1] == 'R' || g[n][m] == 'R') return void(cout << "0\n");
    if (n == 1 && m == 1) return void(cout << 1 << "\n");
    
    for (int i = n; i >= 1; -- i){
        for (int j = m; j >= 1; -- j){
            if (g[i][j] == 'R') D[i][j] = R[i][j] = 1;
            D[i][j] += D[i+1][j], R[i][j] += R[i][j+1];
        }
    }
    f1[1][1] = f2[1][1] = 1;
    f1[2][1] = f2[1][2] = -1;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            AD(f1[i][j], f1[i-1][j]+f2[i-1][j]);
            AD(f2[i][m-R[i][j+1]+1], -f1[i][j]);

            AD(f2[i][j], f1[i][j-1]+f2[i][j-1]);
            AD(f1[n-D[i+1][j]+1][j], -f2[i][j]);
        }
    }

    int res = (f1[n][m]+f2[n][m]) % mod;
    cout << res << "\n";
}
