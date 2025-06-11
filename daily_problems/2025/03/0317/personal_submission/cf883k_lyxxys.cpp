void solve(){
    int n;
    cin >> n;
    vector <int> A(n), B(n);
    int ma = 0;
    for (int i = 0; i < n; ++ i){
        cin >> A[i] >> B[i];
        ma = max(ma, A[i]);
    }

    i64 res = 0;
    vector <int> pr(n, inf_int), sf(n, inf_int);
    pr[0] = A[0]+B[0], sf[n-1] = A[n-1]+B[n-1];
    for (int i = 1; i < n; ++ i){
        pr[i] = min(A[i]+B[i], pr[i-1]+1);
    }
    for (int i = n-2; i >= 0; -- i){
        sf[i] = min(A[i]+B[i], sf[i+1]+1);
    }
    for (int i = 0; i < n; ++ i){
        int d = min(pr[i], sf[i]) - A[i];
        res += d;
        A[i] += d;
        if (d < 0){
            cout << -1 << "\n";
            return;
        }
    }
    cout << res << "\n";
    print(A);
}
