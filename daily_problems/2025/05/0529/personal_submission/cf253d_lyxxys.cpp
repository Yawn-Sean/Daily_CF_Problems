void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> pr(n+1, vector<int>(m));
    vector <string> g(n);
    for (auto &chs : g){
        cin >> chs;
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            pr[i+1][j] = pr[i][j] + (g[i][j] == 'a');
        }
    }

    i64 res = 0;
    vector <int> cnts(26);
    for (int r1 = 0; r1 < n; ++ r1){
        for (int r2 = r1+1; r2 < n; ++ r2){
            for (int i = 0; i < 26; ++ i){
                cnts[i] = 0;
            }
            for (int i = 0; i < m; ++ i){
                cnts[g[r1][i]-'a'] += (g[r1][i] == g[r2][i]);
            }
            // 小于 k 的部分 = 总个数 - 大于 k 的部分
            i64 ans = 0;
            for (int i = 0; i < 26; ++ i){
                ans += cnts[i] * (cnts[i]-1) / 2;
            }

            for (int i = 0, j = -1, sm = 0; i < m-1; ++ i){
                while (i >= j || j+1 < m && sm <= k){
                    if (j >= 0) cnts[g[r1][j]-'a'] -= (g[r1][j] == g[r2][j]);
                    j += 1;
                    sm += pr[r2+1][j] - pr[r1][j];
                }
                if (sm <= k) break;

                if (g[r1][i] == g[r2][i]){
                    ans -= cnts[g[r1][i]-'a'];
                }
                sm -= pr[r2+1][i] - pr[r1][i];
            }
            res += ans;
        }
    }
    

    cout << res << "\n";
}
