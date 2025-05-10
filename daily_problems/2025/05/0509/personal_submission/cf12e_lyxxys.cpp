void solve(){
    int n;
    cin >> n;
    vector<vector<int>> ans(n,vector<int>(n));
    for (int i = 0; i < n-1; ++ i){
        for (int j = 0; j < n-1; ++ j){
            ans[i][j] = (i+j) % (n-1) + 1;
        }
    }
    for (int i = 0; i < n; ++ i){
        ans[i][n-1] = ans[n-1][i] = ans[i][i];
        ans[i][i] = 0;
    }
    for (int i = 0; i < n; ++ i){
        print(ans[i]);
    }
}
