void solve(){
    const int N = 100000, M = 300;

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<int>> store(N+1);
    vector<vector<int>> f(n+1, vector<int>(M+1, inf_int));
    // 要取 A 的 下标i 为该操作的结尾，而且是第 j 次操作，对应 B 中的下标最小值
    vector <int> Mi(M+1, inf_int);

    vector <int> A(n+1), B(m+1);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }
    for (int i = 1; i <= m; ++ i){
        cin >> B[i];
        store[B[i]].push_back(i);
    }

    auto upper = [&](int x, int i)->int{
        auto it = upper_bound(store[x].begin(), store[x].end(), i);
        if (it == store[x].end()) return inf_int;
        else return *it;
    };

    f[0][0] = 0;
    for (int i = 0; i <= n; ++ i){
        
        for (int j = 1; j <= M; ++ j){
            int low = Mi[j-1];
            if (low < m){
                int r = upper(A[i], low);
                fmin(f[i][j], r);
            }
        }

        for (int j = 0; j <= M; ++ j){
            fmin(Mi[j], f[i][j]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= M; ++ j){
            int cost = i + f[i][j] + j * e;
            if (cost <= s){
                // cout << cost << " " << i << " " << j << "\n";
                fmax(res, j);
            }
        }
    }

    cout << res << "\n";
}
