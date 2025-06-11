void solve(){
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    for (int i = 0, m; i < n; ++ i){
        cin >> m;
        A[i].resize(m);
        for (auto &x : A[i]){
            cin >> x;
        }
        sort(A[i].begin(), A[i].end());
    }

    int res = 0;
    for (int i = 0; i < n; ++ i){
        auto &U1 = A[(i-1+n)%n], &U2 = A[(i+1)%n];
        auto &U = A[i];
        int n1 = U1.size(), n2 = U2.size(), un = U.size();

        int i1 = 0, j1 = -1, i2 = 0, j2 = -1;
        for (int i = 0; i < un-1; ++ i){
            int l = U[i], r = U[i+1];
            while (i1 < n1 && U1[i1] < l) i1 += 1;
            while (i2 < n2 && U2[i2] < l) i2 += 1;
            while (j1+1 < n1 && U1[j1+1] < r) j1 += 1;
            while (j2+1 < n2 && U2[j2+1] < r) j2 += 1;

            if (j1-i1+1 != j2-i2+1) res += 1;
        }
    }

    cout << res << "\n";
}
