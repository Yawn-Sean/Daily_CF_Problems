void solve(){
    int n;
    cin >> n;
    vector <int> A(n), idx(n);
    for (auto &x : A){
        cin >> x;
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return A[u] != A[v] ? A[u] < A[v] : u < v;
    });

    int res = -1, r = -1;
    for (int id = 0; id <= n; ++ id){
        if (id > r) res += 1;

        if (id < n){
            int i = idx[id];
            fmax(r, i);
        }
    }
    
    cout << res << "\n";
}
