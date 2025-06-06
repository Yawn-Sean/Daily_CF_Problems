void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    i64 res = (1ll << A[0]) - 1;
    for (int i = 1; i < n; ++ i){
        int cnt = A[i-1] - A[i] + 1;
        if (cnt >= 0){
            fmax(res, (1ll << A[i-1]+1) - (1ll << cnt) - i);
        }
    }
    bool jug = true;
    for (int i = 0; i < n; ++ i){
        if (__builtin_popcountll(res+i) != A[i]){
            jug = false;
            break;
        }
    }

    cout << (jug ? res : -1) << "\n";
}
