void solve(){
    const int mod = 1e9+7;
    auto pows = [&](i64 a, int b)->int{
        i64 res = 1;
        while (b){
            if (b&1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };
    auto call = [&](i64 a1, i64 n, i64 q)->int{
        i64 res = a1 * (pows(q, n) - 1) % mod;
        res = res * pows(q-1, mod-2) % mod;
        if (res < 0) res += mod;
        return res;
    };

    string s;
    int k;
    cin >> s >> k;

    int n = s.size(), res = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0' || s[i] == '5'){
            i64 a1 = pows(2, i), n1 = k, q1 = pows(2, n);  // 首项、项数、公比
            res += call(a1, n1, q1);
            res %= mod;
        }
    }

    cout << res << "\n";
}
