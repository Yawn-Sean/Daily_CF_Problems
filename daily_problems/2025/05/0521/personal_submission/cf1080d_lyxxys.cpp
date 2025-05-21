void solve(){
    i64 n, k;
    cin >> n >> k;

    vector <i64> f4(32), h(32), f2(32);
    i64 u = 1;
    for (int i = 1; i <= 31; ++ i){
        f4[i] = f4[i-1] * 4 + 1;
        u *= 2;
        f2[i] = u-1;
        f2[i] += f2[i-1];
    }

    if (n > 31){
        cout << "YES " << n-1 << "\n";
    } else {
        for (int i = 0; i <= n; ++ i){
            i64 lo, hi;  // 下界、上界
            lo = f2[n-i];
            hi = f4[n];  // 先整体变 1x1，找回多减的
            hi -= f2[n-0] - f2[n-i];

            if (k >= lo && k <= hi){
                cout << "YES " << i << "\n";
                return;
            }
        }
        cout << "NO\n";
    }
}
