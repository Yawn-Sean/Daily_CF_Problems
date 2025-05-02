void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> f(n,vector<int>(m));
    for (int i = 0; i < n; ++ i){
        cin >> s[i];
        int cur = 0;
        for (int j = m-1; j >= 0; -- j){
            cur = s[i][j] == '1' ? cur+1 : 0;
            f[i][j] = cur;
        }
    }

    int res = 0;
    vector <int> cnts(m+2);
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            cnts[f[i][j]] += 1;
        }
        for (int i = m; i >= 0; -- i){
            cnts[i] += cnts[i+1];
            fmax(res, cnts[i] * i);
        }
        for (int i = m; i >= 0; -- i){
            cnts[i] = 0;
        }
    }

    cout << res << "\n";
}
