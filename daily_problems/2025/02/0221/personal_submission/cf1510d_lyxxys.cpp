void solve(){
    int n, d;
    cin >> n >> d;
    vector<vector<f64>> f(n+1,vector<f64>(10, -1));
    vector<vector<int>> last(n+1,vector<int>(10, -1));
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    f[0][1] = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < 10; ++ j){
            if (f[i][j] >= 0){
                int nxt = j*A[i] %10;
                const f64 &val = log2l(A[i]);
                if (f[i][j]+val > f[i+1][nxt]){
                    f[i+1][nxt] = f[i][j]+val;
                    last[i+1][nxt] = j;
                }
                if (f[i][j] > f[i+1][j]){
                    f[i+1][j] = f[i][j];
                    last[i+1][j] = -1;
                }
            }
        }
    }

    vector <int> ans;
    for (int i = n, j = d; i > 0; -- i){
        if (last[i][j] < 0) continue;

        j = last[i][j];
        ans.push_back(A[i-1]);
    }

    if (ans.empty()){
        cout << -1 << "\n";
    } else {
        cout << ans.size() << "\n";
        print(ans);
    }
}
