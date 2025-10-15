void solve(){
    const int N = 5050;
    static int f[N][(N+1)/2][3];
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < (N+1)/2; ++ j){
            for (int u = 0; u < 3; ++ u){
                f[i][j][u] = inf_int;
            }
        }
    }
    auto cost = [&](int x, int y)->int{  // 使得 x 小于 y 的代价
        return max(0, x-y+1);
    };

    int n;
    cin >> n;
    const int m = (n+1)/2;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    f[1][0][0] = 0;
    f[1][1][1] = 0;

    for (int i = 1; i < n; ++ i){
        for (int j = 0; j <= m; ++ j){
            for (int u = 0; u < 3; ++ u){ // {00, 01, 10}
                if (f[i][j][u] == inf_int) continue;

                if (u == 0){
                    fmin(f[i+1][j][0], f[i][j][u]);
                    fmin(f[i+1][j+1][1], f[i][j][u]+cost(A[i-1], A[i]));
                } else if (u == 1){
                    fmin(f[i+1][j][2], f[i][j][u]+cost(A[i], A[i-1]));
                } else {
                    fmin(f[i+1][j][0], f[i][j][u]);
                    fmin(f[i+1][j+1][1], f[i][j][u] + cost(min(A[i-2]-1, A[i-1]), A[i]));
                }
            }
        }
    }

    vector <int> ans(m, inf_int);

    for (int i = 1; i <= m; ++ i){
        for (int u = 0; u < 3; ++ u){
            fmin(ans[i-1], f[n][i][u]);
        }
    }

    print(ans);
}
