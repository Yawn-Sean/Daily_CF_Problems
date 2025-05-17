void solve(){
    int k, ans = 0;
    string s;
    cin >> s >> k;
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == '0' || s[i] == '5') {
            int fi = binpow(2, i);
            int plus = (binpow(binpow(2, s.size()), k) + MOD - 1) % MOD;
            int mins = (binpow(2, s.size()) + MOD - 1) % MOD;
            int se = plus * binpow(mins, MOD - 2) % MOD;
            ans = (fi * se % MOD + ans) % MOD;
        }
    }
    cout << ans << '\n';
}
