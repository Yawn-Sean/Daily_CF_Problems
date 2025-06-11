void solve(){
    const int N = 60;

    int n, m, q;
    cin >> n >> m >> q;
    static i64 f[N][N][N], h[N][N];
    // f[k][i][j] 换了 k-1 辆车(包含可以换回原来的车的情况)，走了 k 条边，从 i 到 j 的最短路
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            for (int k = 0; k < N; ++ k){
                f[i][j][k] = inf_i64;
            }
        }
    }

    auto process = [&]()->void{
        for (int k = 0; k < n; ++ k){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    fmin(h[i][j], h[i][k]+h[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                fmin(f[1][i][j], h[i][j]);
            }
        }
    };
    for (int i = 0; i < m; ++ i){
        for (int u = 0; u < n; ++ u){
            for (int v = 0; v < n; ++ v){
                cin >> h[u][v];
            }
        }
        process();
    }

    // return;

    for (int k = 2; k < N; ++ k){
        for (int to = 0; to < n; ++ to){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    fmin(f[k][i][j], f[k-1][i][to]+f[1][to][j]);
                }
            }
        }
    }

    while (q--){
        int u, v, k;
        cin >> u >> v >> k;
        k += 1;
        fmin(k, N-1);
        u -= 1, v -= 1;
        cout << f[k][u][v] << "\n";
    }
}
