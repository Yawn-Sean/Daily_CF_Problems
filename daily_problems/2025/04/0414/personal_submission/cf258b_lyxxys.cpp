void solve(){
    int n;
    cin >> n;
    n += 1;

    vector <int> vals, f(10);
    while (n){
        vals.push_back(n%10);
        n /= 10;
    }
    reverse(vals.begin(), vals.end());

    int cnt = 0;
    for (auto &x : vals){
        for (int i = 9; i > 0; -- i){ 
            f[i] = f[i]*8 + f[i-1]*2;
        }
        f[0] *= 8;

        for (int i = 0; i < x; ++ i){
            f[cnt + (i==4 || i==7)] += 1;
        }
        cnt += (x==4 || x==7);
    }
    f[0] -= 1;

    const int mod = 1e9+7;
    auto dfs_brute = [&](auto &&self, int u, int tot)->int{
        if (tot >= 9) return 0;
        i64 ans = 0;

        if (u < 6){
            for (int i = 0; i < 10; ++ i){
                if (f[i]){
                    f[i] -= 1;
                    ans += 1ll * (f[i]+1) * self(self, u+1, tot+i) % mod;
                    ans %= mod;
                    f[i] += 1;
                }
            }
        } else {
            for (int i = tot+1; i < 10; ++ i){
                ans += f[i], ans %= mod;
            }
        }
        return ans;
    };

    cout << dfs_brute(dfs_brute, 0, 0) << "\n";
}
