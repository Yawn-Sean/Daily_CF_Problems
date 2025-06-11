void solve(){
    int n;
    cin >> n;
    vector <int> A(n), gcds(n);
    for (auto &x : A){
        cin >> x;
    }
    for (int i = 1; i < n; ++ i){
        gcds[i] = __gcd(i, n);
    }

    i64 res = 0;
    for (int i = 1; i < n; ++ i){
        if (n%i == 0){
            vector <int> ma(i);
            for (int j = 0; j < n; ++ j){
                fmax(ma[j%i], A[j]);
            }
            vector <int> vis(2*n);
            for (int j = 0; j < n; ++ j){
                if (A[j] == ma[j%i]){
                    vis[j] = 1;
                    vis[j+n] = 1;
                }
            }

            vector <int> acc(n+1);
            int cur = 0;
            for (int j = 2*n-1; j >= 0; -- j){
                cur = vis[j] ? cur+1 : 0;
                if (j < n) acc[min(cur, n)] += 1;
            }

            for (int j = n; j > 0; -- j){
                acc[j-1] += acc[j];
            }

            for (int j = i; j < n; j += i){
                if (gcds[j] == i){
                    res += acc[j];
                }
            }
        }
    }

    cout << res << "\n";
}
