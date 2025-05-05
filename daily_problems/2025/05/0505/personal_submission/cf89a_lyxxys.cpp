void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    if (n%2 == 0){
        cout << 0 << "\n";
        return;
    }

    int mi = inf_int;
    for (int i = 0; i < n; i += 2){
        fmin(mi, A[i]);
    }

    cout << min(1ll*mi, 1ll*k * (m / ((n+1)/2))) << "\n";
}
