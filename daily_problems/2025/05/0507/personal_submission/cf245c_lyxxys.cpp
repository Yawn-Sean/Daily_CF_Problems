void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    if (n <= 2 || n%2 == 0) return void(cout << -1 << "\n");

    int res = 0;
    for (int i = n-2; i > 0; i -= 2){
        int need = max(A[i], A[i+1]);
        A[i] = A[i+1] = 0;
        A[i/2] -= min(need, A[i/2]);
        res += need;
    }
    res += A[0];

    cout << res << "\n";
}
