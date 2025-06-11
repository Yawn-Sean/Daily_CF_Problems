void solve(){
    auto error = [&]()->void{
        cout << "NO\n";
    };
    int n, m;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }
    cin >> m;
    vector <int> B(m);
    for (auto &x : B){
        cin >> x;
    }

    vector <array<int,2>> ans, segs;
    int bj = 0;
    for (int i = 0, lst=0,cur=0; i < n; ++ i){
        cur += A[i];
        if (bj >= m) return error();
        if (cur == B[bj]){
            segs.push_back({lst,i});
            cur = 0, lst = i+1, bj += 1;
        } else if (cur > B[bj]){
            return error();
        }
    }
    if (bj < m) return error();

    vector<vector<int>> f(n,vector<int>(n)), g(n,vector<int>(n));
    auto back_find = [&](auto &&self, int i, int j)->void{
        if (i == j) return;
        for (int u = i; u < j; ++ u){
            if ((f[i][u] && f[u+1][j]) && (f[i][u] != f[u+1][j])){
                self(self, i, u), self(self, u+1, j);
                if (f[i][u] > f[u+1][j]){
                    ans.push_back({1, g[i][u]});
                } else {
                    ans.push_back({0, g[u+1][j]});
                }
                break;
            }
        }
    };
    for (auto &it : segs){
        int l = it[0], r = it[1];
        for (int L = 1; L <= r-l+1; ++ L){
            for (int i = l; i+L-1 <= r; ++ i){
                int j = i+L-1;
                if (L == 1){
                    f[i][j] = A[i];
                    g[i][j] = i;
                } else {
                    for (int u = i; u < j; ++ u){
                        if ((f[i][u] && f[u+1][j]) && (f[i][u] != f[u+1][j])){
                            if (f[i][u] > f[u+1][j]){
                                g[i][j] = g[i][u];
                            } else {
                                g[i][j] = g[u+1][j];
                            }
                            f[i][j] = f[i][u]+f[u+1][j];
                            break;
                        }
                    }
                }
            }
        }
        if (f[l][r] == 0) return error();
        back_find(back_find, l, r);
    }

    for (int i = ans.size()-1; i > 0; -- i){
        int cur = ans[i][1];
        for (int j = 0; j < i; ++ j){
            if (cur > ans[j][1] || (cur == ans[j][1] && ans[j][0] == 0)){
                ans[i][1] -= 1;
            }
        }
    }

    cout << "YES\n";
    for (auto &it : ans){
        cout << it[1]+1 << " " << (it[0] == 0 ? 'L' : 'R') << "\n";
    }
}
