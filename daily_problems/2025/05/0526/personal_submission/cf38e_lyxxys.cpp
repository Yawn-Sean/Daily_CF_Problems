void solve(){
    int n;
    cin >> n;
    vector <array<int,2>> A(n);
    vector <int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    for (auto &i : A){
        cin >> i[0] >> i[1];
    }
    sort(idx.begin(), idx.end(), [&](int &u, int &v){
        return A[u][0] < A[v][0];
    });

    vector <i64> f1(n+1, inf_i64), f2(n+1, inf_i64);
    f1[1] = A[idx[0]][1];
    auto w = [&](int i, int j)->int{
        return abs(A[idx[i]][0] - A[idx[j]][0]);
    };
    for (int i = 1; i < n; ++ i){
        int id = idx[i];
        int x = A[id][0], c = A[id][1];

        i64 mi = inf_i64;
        for (int j = 1; j <= i; ++ j){
            fmin(f2[j], f1[j] + w(i, j-1));
            fmin(mi, f1[j]);
        }
        f2[i+1] = mi + c;

        for (int j = 1; j <= i+1; ++ j){
            f1[j] = f2[j];
            f2[j] = inf_i64;
        }
    }

    i64 res = inf_i64;
    for (int i = 1; i <= n; ++ i){
        fmin(res, f1[i]);
    }

    cout << res << "\n"; 
}
