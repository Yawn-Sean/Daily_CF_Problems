void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ps(m,vector<int>(n)), locs(m,vector<int>(n));
    for (int i = 0; i < m; ++ i){
        auto &p = ps[i];
        for (int j = 0; j < n; ++ j){
            cin >> p[j];
            p[j] -= 1;
            locs[i][p[j]] = j;
        }
    }

    auto chk = [&](int x, int y)->bool{
        for (int i = 1; i < m; ++ i){
            int j = locs[i][x];
            if (j+1 >= n || ps[i][j+1] != y) return false;
        }
        return true;
    };

    i64 res = 0;
    auto &A = ps[0];
    for (int i = 0, j = -1; i < n; ++ i){
        while (j < i || j+1 < n && chk(A[j], A[j+1])){
            j += 1;
        }
        res += j-i+1;
    }

    cout << res << "\n";
}
