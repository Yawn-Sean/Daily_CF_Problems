void solve(){
    int n, R;
    cin >> n >> R;
    const f64 sqrR = sqrtl(2)*R;
    auto W = [&](int x)->f64{
        return 1.0 * x * (R + x*R + 2*sqrR);
    };

    f64 res = 0;
    for (int i = 1; i <= n; ++ i){
        res += 2*R;
        if (i-1 > 0) res += 2*R+sqrR;
        if (i-2 > 0) res += W(i-2);

        if (n-i > 0) res += 2*R+sqrR;
        if (n-i-1 > 0) res += W(n-i-1);
    }

    cout << fixed << setprecision(15) << res/(1.0*n*n) << "\n";
}
