void solve(){
    int n, k;
    cin >> n >> k;

    vector <i64> A(n/k), p10(11,1);
    for (int i = 1; i < 11; ++ i){
        p10[i] = p10[i-1] * 10;
    }

    for (auto &x : A){
        cin >> x;
    }
    const int mod = 1e9+7;
    i64 res = 1;
    auto W = [&](i64 b, i64 a)->int{
        return ((b+1)*p10[k-1]-1)/a - (b*p10[k-1]-1)/a;
    };
    for (int i = 0, x; i < n/k; ++ i){
        cin >> x;
        if (!x){
            i64 v = (p10[k]-1)/A[i] - (p10[k-1]-1)/A[i];
            res = res*v % mod;
        } else {
            i64 v = (p10[k]-1)/A[i]+1 - W(x, A[i]);
            res = res*v % mod;
            // cout << v << "\n";
        }
    }

    cout << res << "\n";
}
