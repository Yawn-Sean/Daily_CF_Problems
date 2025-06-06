void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m+1));
    vector<vector<int>> colms(n+1, vector<int>(m));
    vector<string> s(n);
    for (auto &chs : s){
        cin >> chs;
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            rows[i][j+1] = rows[i][j] + (s[i][j] == 'B');
        }
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            colms[i+1][j] = colms[i][j] + (s[i][j] == 'B');
        }
    }

    vector<array<int,2>> points;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == 'B'){
                points.push_back({i, j});
            }
        }
    }

    auto chk_row = [&](int i1, int j1, int i2, int j2)->bool{
        assert(i1 == i2);
        if (j1 < j2) swap(j1, j2);
        return rows[i1][j1+1] - rows[i2][j2] == j1-j2+1;
    };
    auto chk_colm = [&](int i1, int j1, int i2, int j2)->bool{
        assert(j1 == j2);
        if (i1 < i2) swap(i1, i2);
        return colms[i1+1][j1] - colms[i2][j2] == i1-i2+1;
    };
    auto chk_line = [&](int i1, int j1, int i2, int j2)->bool{
        if (i1 == i2) return chk_row(i1, j1, i2, j2);
        else return chk_colm(i1, j1, i2, j2);
    };
    auto chk = [&](int i1, int j1, int i2, int j2)->bool{
        return chk_line(i1,j1,i2,j1) && chk_line(i2,j1,i2,j2) 
        || chk_line(i1,j1,i1,j2) && chk_line(i1,j2,i2,j2);
    };

    int l = points.size();
    for (int i = 0; i < l; ++ i){
        for (int j = i+1; j < l; ++ j){
            int i1 = points[i][0], j1 = points[i][1];
            int i2 = points[j][0], j2 = points[j][1];
            if (!chk(i1,j1,i2,j2)){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
