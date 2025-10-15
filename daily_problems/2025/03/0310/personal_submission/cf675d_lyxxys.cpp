void solve(){
    int n;
    cin >> n;
    vector <int> A(n), idx(n);
    for (auto &x : A){
        cin >> x;
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return A[u] < A[v];
    });
    vector <int> stk, lc(n, -1), rc(n, -1);
    for (int i = 0; i < n; ++ i){
        int cur = idx[i];
        while (!stk.empty() && cur < stk.back()){
            int x = stk.back();
            rc[x] = lc[cur], lc[cur] = x;
            stk.pop_back();
        }
        stk.push_back(cur);
    }
    while (stk.size() > 1){
        int x = stk.back();
        stk.pop_back();
        rc[stk.back()] = x;
    }

    vector <int> ans(n);
    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        ans[u] = presor;
        if (lc[u] != -1) self(self, lc[u], u);
        if (rc[u] != -1) self(self, rc[u], u);
    };
    dfs_find(dfs_find, stk[0], -1);
    for (int i = 1; i < n; ++ i){
        if (i > 1) cout << " ";
        cout << A[ans[i]];
    }
    cout << "\n";
}
