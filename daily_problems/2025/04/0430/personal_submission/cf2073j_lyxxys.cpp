void solve(){
    int n;
    cin >> n;
    vector <int> A(n), p(n);
    vector<vector<int>> f(n,vector<int>(n, inf_int));

    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        A[i] -= 1;
        p[A[i]] = i;
    }

    auto settle = [&](int l, int mid, int r)->int{
        return abs(p[l] - p[mid+1]);
    };

    for (int r = 0; r < n; ++ r){
        for (int l = r; l >= 0; -- l){
            if (l == r){
                f[l][r] = 0;
                continue;
            }

            for (int i = l; i < r; ++ i){
                int v = f[l][i]+f[i+1][r] + settle(l, i, r);
                if (v < f[l][r]){
                    f[l][r] = v;
                }
            }
        }
    }

    cout << f[0][n-1] << "\n";
}
