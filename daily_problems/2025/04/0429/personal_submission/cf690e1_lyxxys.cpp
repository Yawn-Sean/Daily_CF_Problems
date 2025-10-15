void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> A[i][j];
        }
    }

    int u1 = 0, u2 = 0;
    for (int i = 0, mid = n/2; i < m; ++ i){
        u1 += abs(A[mid][i]-A[mid-1][i]);
        u2 += abs(A[0][i]-A[n-1][i]);
    }

    if (u1 < u2){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
