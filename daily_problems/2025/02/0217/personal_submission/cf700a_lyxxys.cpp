void solve(){
    i64 n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;
    // cout << (n+k-1)/k << "\n";
    // return;

    auto chk = [&](f64 mid)->bool{
        const f64 l1 = (mid*v1*v2-v1*l)/(v2-v1), l2 = l-l1;
        const f64 t2 = l2/v2, L = v1*t2;
        const f64 c = (n+k-1)/k;
        f64 cur = 0;
        for (int i = 0; i < c; ++ i){
            if (i > 0) cur += v1*(l2-L)/(v1+v2);
            if (cur > l1) return false;
            cur += L;
        }
        return true;
    };

    f64 lo = 1.0*l/v2, hi = 1.0*l/v1;

    for (int i = 0; i < 200; ++ i){
        f64 mid = (lo+hi) / 2;
        if (chk(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(15) << lo << "\n";
}
