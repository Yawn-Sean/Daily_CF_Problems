void solve(){
    int q;
    cin >> q;
    while (q--){
        i64 n, m, k;
        cin >> n >> m >> k;
        i64 res = 0;
        if (k < max(n, m)) res = -1;
        else if ((n+m)%2) res = k-1;
        else if (n%2 == k%2) res = k;
        else res = k-2;
        cout << res << "\n";
    }
}
