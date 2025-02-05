void solve(){
    const int mod = 1e9+7;
    auto add = [&](int &x, int y)->void{
        (x += y) %= mod;
    };

    int n, l;
    cin >> n >> l;
    vector<vector<vector<int>>> f(l+1,vector<vector<int>>(n,vector<int>(2,0)));
    vector<array<int,2>> A(n);
    for (auto &it : A){
        cin >> it[0] >> it[1];
    }
    for (int i = 0; i < n; ++ i){
        int a = A[i][0], b = A[i][1];
        if (a <= l){
            f[a][i][0] = 1;
        }
        if (a != b){
            swap(a, b);
            if (a <= l){
                f[a][i][1] = 1;
            }
        }
    }

    for (int i = 1; i < l; ++ i){
        for (int j = 0; j < n; ++ j){
            for (int u = 0; u < 2; ++ u){
                int a = A[j][0], b = A[j][1];
                if (u == 1) swap(a, b);

                for (int k = 0; k < n; ++ k){
                    if (k == j) continue;

                    int c = A[k][0], d = A[k][1];
                    if (b == c && i+c <= l){
                        add(f[i+c][k][0], f[i][j][u]);
                    }

                    if (c == d) continue;

                    swap(c, d);
                    if (b == c && i+c <= l){
                        add(f[i+c][k][1], f[i][j][u]);
                    }
                }

                if (a == b) break;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < 2; ++ j){
            add(res, f[l][i][j]);
        }
    }

    cout << res << "\n";
}

