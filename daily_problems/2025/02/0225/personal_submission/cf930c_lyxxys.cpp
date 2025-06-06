void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A(m+1), pr(m+1), sf(m+1);
    for (int i = 0,l,r; i < n; ++ i){
        cin >> l >> r;
        l -= 1, r -= 1;
        A[l] += 1, A[r+1] -= 1;
    }
    for (int i = 1; i < m; ++ i){
        A[i] += A[i-1];
    }
    
    vector <int> stk;
    for (int i = 0; i < m; ++ i){
        auto it = upper_bound(stk.begin(), stk.end(), A[i]);
        if (it == stk.end()) stk.push_back(A[i]);
        else *it = A[i];
        pr[i] = stk.size();
    }
    while (stk.size()) stk.pop_back();
    for (int i = m-1; i >= 0; -- i){
        auto it = upper_bound(stk.begin(), stk.end(), A[i]);
        if (it == stk.end()) stk.push_back(A[i]);
        else *it = A[i];
        sf[i] = stk.size();
    }

    int res = 0;
    for (int i = 0; i < m; ++ i){
        fmax(res, pr[i]+sf[i]-1);
    }
    cout << res << "\n";
}
