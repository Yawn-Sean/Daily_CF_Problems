void solve(){
    const int limi = 1<<20, mod = 1e9+7;

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> f(n+1, vector<int>(limi));

    for (int i = 0; i < n; ++ i){
        f[i][0] = 1;
    }

    for (int i = 0; i < n; ++ i){
        int v = 0;
        for (int j = i; j < n; ++ j){
            v = v*2 + (s[j]-'0');
            if (v == 0) continue;
            if (v > 20) break;

            for (int u = 0; u < limi; ++ u){
                f[j+1][u|(1<<v-1)] += f[i][u];
                f[j+1][u|(1<<v-1)] %= mod;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= 20; ++ j){
            res += f[i][(1<<j)-1];
            res %= mod;
        }
    }
    cout << res << "\n";
}
