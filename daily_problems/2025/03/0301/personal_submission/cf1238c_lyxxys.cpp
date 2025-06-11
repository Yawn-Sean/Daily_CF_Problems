void solve(){
    int n, h;
    cin >> h >> n;
    vector <int> A(n+2);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }
    vector <int> f(n+2, inf_int);
    f[1] = 0;
    for (int i = 2; i <= n+1; ++ i){
        fmin(f[i], f[i-1] + (i <= n));
        if (i-2 >= 1 && A[i]+1 == A[i-1]){
            fmin(f[i], f[i-2]);
        }
    }
    cout << f[n+1] << "\n";
}
