void solve(){
    const int d1 = 90, d2 = 1440;

    int n;
    cin >> n;
    vector <int> A(n+1), f(n+1, inf_int);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }
    A[0] = -1, f[0] = 0;

    for (int i = 1; i <= n; ++ i){
        int x = A[i];
        int j1 = lower_bound(A.begin(), A.end(), x-d1+1) - A.begin();
        int j2 = lower_bound(A.begin(), A.end(), x-d2+1) - A.begin();
        fmin(f[i], f[i-1]+20);
        if (j1 != i) fmin(f[i], f[max(j1-1, 0)]+50);
        if (j2 != i) fmin(f[i], f[max(j2-1, 0)]+120);
    }
    for (int i = 1; i <= n; ++ i){
        cout << f[i]-f[i-1] << "\n";
    }
}
