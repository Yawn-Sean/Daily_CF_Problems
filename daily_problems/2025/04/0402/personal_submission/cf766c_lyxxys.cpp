void solve(){
    /*
        合法分割方案
        合法分割最长子串
        合法分割最小分组
    */
    const int mod = 1e9+7;
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector <int> con(26);
    for (auto &x : con){
        cin >> x;
    }
    
    vector<vector<int>> f(n+1, vector<int>(n+1));  // 前 i 个 分 j 组、
    vector<vector<int>> h(n+1, vector<int>(n+1));  // 前 i 个 分 j 组
    
    int ma = 0;

    for (int i = 1; i <= n; ++ i){
        int bound = 1;
        for (int j = i; j >= bound; -- j){
            if (i-con[s[j]-'a']+1 > j){
                bound = j+1;
                break;
            }
            bound = max(bound, i-con[s[j]-'a']+1);
        }

        fmax(ma, i-bound+1);
        
        if (bound == 1) f[i][1] = 1;
        for (int j = 1; j <= i; ++ j){
            f[i][j] += (h[i-1][j-1] - h[max(0, bound-2)][j-1]) % mod;
            if (f[i][j] < 0) f[i][j] += mod;
        }
        for (int j = 0; j <= i; ++ j){
            h[i][j] = (h[i-1][j] + f[i][j]) % mod;
        }
    }

    int res = 0, mi = n;
    for (int j = 1; j <= n; ++ j){
        res += f[n][j], res %= mod;
        if (f[n][j]) fmin(mi, j);
    }
    
    cout << res << "\n" << ma << "\n" << mi << "\n";
}
