void solve(){
    auto find_big = [&](int x)->int{
        int ma = -1;
        for (int i = 2; i*i <= x; ++ i){
            if (x%i == 0){
                while (x%i == 0) x /= i;
                ma = i;
            }
        }
        if (x > 1) ma = x;
        return ma;
    };

    int n;
    cin >> n;
    int m = find_big(n);

    assert(m != n);

    int res = n;
    for (int i = n; i > n-m; -- i){
        int l = find_big(i);
        if (i == l) continue;
        fmin(res, i-l+1);
    }

    cout << res << "\n";
}
