void solve(){
    int n;
    cin >> n;
    vector <i64> A(n);
    i64 all = 0;
    for (auto &x : A){
        cin >> x;
        all += x;
    }
    i64 need = all / n, res = 0;
    for (int i = 0; i < n-1; ++ i){
        i64 v = need-A[i];
        A[i] += v, A[i+1] -= v;
        res += abs(v);
    }

    cout << res << "\n";
}
