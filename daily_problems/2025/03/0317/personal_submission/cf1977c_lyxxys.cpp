void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }
    int ma = *max_element(A.begin(), A.end());
    i64 cur = 1;
    for (int i = 0; i < n; ++ i){
        cur = cur * A[i] / __gcd(cur, 1ll*A[i]);
        if (cur > ma) break;
    }
    if (cur > ma) return void(cout << n << "\n");

    auto w = [&](int x)->int{
        i64 cur = 1, cnt = 0;
        for (auto &v : A){
            if (v == x) return 0;
            if (x%v == 0){
                cur = cur*v / __gcd(cur, 1ll*v);
                cnt += 1;
            }
        }
        return cur == x ? cnt : 0;
    };

    int res = 0;
    for (int i = 2; 1ll*i*i <= ma; ++ i){
        if (ma%i == 0){
            fmax(res, w(i));
            fmax(res, w(ma/i));
        }
    }
    cout << res << "\n";
}
