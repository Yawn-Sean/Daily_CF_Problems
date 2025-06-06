void solve(){
    auto mt = mt19937(rand());
    uniform_int_distribution <int> rnd(1e8, 1e9);
    const int mod = rnd(mt), ba = 131;

    int n;
    cin >> n;
    vector<vector<array<int,2>>> g(n);
    vector <array<int,2>> one;
    int tot = n-1;
    auto open = [&]()->int{
        g.push_back(one);
        ++ tot;
        return tot;
    };
    auto add_edge = [&](int u, int v, int w)->void{
        g[u].push_back({v, w});
    };

    for (int i = 1, fa; i < n; ++ i){
        string s;
        cin >> fa >> s;
        fa -= 1;

        for (int j = 0; j < s.size()-1; ++ j){
            int id = open();
            add_edge(fa, id, s[j]-'a');
            fa = id;
        }
        add_edge(fa, i, s.back()-'a');
    }

    string t;
    cin >> t;
    int m = t.size();

    i64 U = 0, H = 1;
    for (int i = 0; i < m; ++ i){
        U = (U*ba + (t[i]-'a')) % mod;
        if (i > 0) H = H*ba % mod;
    }
    int res = 0;

    auto dfs_find = [&](auto &&self, int u, i64 ha, vector <int> &curs)->void{
        if (curs.size() >= m && ha == U) res += 1;
        for (auto &[v, w] : g[u]){
            i64 nxt_ha;
            if (curs.size() >= m){
                int lst = curs[curs.size()-m];
                nxt_ha = ((ha - lst*H)%mod + mod) % mod;
                nxt_ha = (nxt_ha*ba + w) % mod;
            } else {
                nxt_ha = (ha*ba + w) % mod;
            }
            curs.push_back(w);
            self(self, v, nxt_ha, curs);
            curs.pop_back();
        }
    };
    vector <int> curs;
    dfs_find(dfs_find, 0, 0, curs);

    cout << res << "\n";
}
