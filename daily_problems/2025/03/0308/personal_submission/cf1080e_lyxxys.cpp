void solve(){
    auto rng = mt19937(random_device()());
    auto rngl = mt19937_64(random_device()());
    const int mod = rng()%int(1e8) + 100999111, bas = 253;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1,vector<int>(m+1));
    vector <i64> ha(26, 1);
    for (int i = 1; i < 26; ++ i){
        ha[i] = ha[i-1] * bas % mod;
    }

    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            char ch;
            cin >> ch;
            g[i][j] = ch-'a';
        }
    }

    vector <i64> curs;
    auto call = [&]()->i64{
        vector <int> A = {-1};
        for (auto &x : curs){
            A.push_back(x);
            A.push_back(-1);
        }
        int n = A.size();
        vector <int> wing(n);
        i64 res = 0;
        int ri = 1, rma = 0;
        for (int i = 1; i < n; ++ i){
            int r = rma > i ? min(wing[2*ri-i], rma-i) : 1;
            while (A[i-r] == A[i+r] && i-r >= 0 && i+r < n) r += 1;
            if (i+r > rma) ri = i, rma = i+r;
            wing[i] = r;
            res += wing[i]/2;
        }
        return res;
    };
    i64 res = 0;
    for (int u = 1; u <= m; ++ u){
        vector <int> msk(n+1);
        vector <i64> ws(n+1);
        for (int v = u; v <= m; ++ v){
            for (int i = 1; i <= n; ++ i){
                msk[i] ^= 1 << g[i][v];
                ws[i] += ha[g[i][v]];
                ws[i] %= mod;
            }
            for (int i = 1; i <= n; ++ i){
                if ((msk[i] & -msk[i]) == msk[i]){
                    curs.push_back(ws[i]);
                } else {
                    res += call();
                    curs.clear();
                }
            }
            res += call();
            curs.clear();
        }
    }
    cout << res << "\n";
}
