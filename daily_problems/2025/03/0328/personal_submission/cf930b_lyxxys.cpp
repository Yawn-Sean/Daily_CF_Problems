void solve(){
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<vector<int>>> f(26, vector<vector<int>>(n,vector<int>(26)));
    for (int i = 0; i < n; ++ i){
        int o = s[i]-'a';
        for (int u = 0; u < n; ++ u){
            int c = s[(i+u)%n]-'a';
            f[o][u][c] += 1;
        }
    }

    f64 res = 0;
    for (int i = 0; i < 26; ++ i){
        int o = s[i]-'a';
        int ans = 0;
        for (int u = 0; u < n; ++ u){
            int cur = 0;
            for (int j = 0; j < 26; ++ j){
                cur += f[i][u][j] == 1;
            }
            ans = max(ans, cur);
        }
        res += ans;
    }

    cout << fixed << setprecision(10) << res/n << "\n";
}
