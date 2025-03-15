void solve(){
    const int mod = 1e9+7;
    auto pows = [&](i64 a, int b)->i64{
        i64 res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> next(n+1);
    vector <int> vis(n+1);
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        next[u].push_back(v);
    }
    
    int cnt = 0, l = n, r = 1;
    for (int i = 1; i <= n; ++ i){
        // assert(next[i].size() <= 2);
        for (auto &x : next[i]){
            if (!(x == i+1 || x == i+1+k)){
                return void(cout << 0 << "\n");
            }

            if (x == i+1+k){
                fmin(l, i), fmax(r, i);
                vis[i] = 1;
                cnt += 1;
            }
        }
    }
    
    if (cnt){
        if (r-l > k) return void(cout << 0 << "\n");
        for (int i = 1; i <= n; ++ i){
            vis[i] += vis[i-1];
        }

        i64 res = !vis[n];
        // cout << "YES\n";
        for (int i = 0; i < n-k-1; ++ i){
            if (!vis[i] && vis[i+k+1] == vis[n]){
                int r = min(i+k, n-k-2);
                res += pows(2, r-i - (vis[r+1]-vis[i+1]));
                // cout << r-i - (vis[r+1]-vis[i+1]) << "\n";
                res %= mod;
            }
        }
        cout << res << "\n";
    } else {
        i64 res = 1;
        i64 cnt = n-2*(k+1)+1;
        if (cnt < 0) cnt = 0;
        res += pows(2, k) * cnt % mod, res %= mod;
        for (int i = 0; i < min(n-k-1-cnt,1ll*k); ++ i){
            res += pows(2, i);
            res %= mod;
        }
        cout << res << "\n";
    }
}
