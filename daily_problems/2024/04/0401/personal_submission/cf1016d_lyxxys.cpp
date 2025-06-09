void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A1(n), A2(m);
    vector<vector<int>> ans(n,vector<int>(m));
    int cur = 0;
    for (auto &x : A1){
        cin >> x;
        cur ^= x;
    }
    for (auto &x : A2){
        cin >> x;
        cur ^= x;
    }
    if (cur) return void(cout << "NO\n");

    for (int i = 0; i < n; ++ i){
        ans[i][0] = A1[i];
    }
    for (int i = 1; i < m; ++ i){
        ans[0][i] = A2[i];
        ans[0][0] ^= A2[i];
    }

    cout << "YES\n";
    for (auto &vec : ans){
        print(vec);
    }
}
