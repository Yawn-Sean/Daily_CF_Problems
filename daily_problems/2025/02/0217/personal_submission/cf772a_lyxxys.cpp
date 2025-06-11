void solve(){
    int n, _p;
    cin >> n >> _p;
    f64 p = _p;

    i64 all_a = 0;
    vector <array<int,2>> A(n);
    for (auto &[u, v] : A){
        cin >> u >> v;
        all_a += u;
    }

    if (_p >= all_a){
        cout << -1 << "\n";
        return;
    }

    auto chk = [&](f64 mid)->bool{
        f64 cur = 0;
        for (auto &[u, v] : A){
            cur += max(mid*u-v, (f64)0);
        }
        return cur <= p*mid;
    };
    f64 lo = 0, hi = 1e12;
    for (int i = 0; i < 200; ++ i){
        f64 mid = (lo+hi) / 2;
        if (chk(mid)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(15) << lo << "\n";
}
