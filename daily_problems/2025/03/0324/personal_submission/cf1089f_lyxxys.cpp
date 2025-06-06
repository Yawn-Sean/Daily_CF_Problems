void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= 40000; ++ i){
        if (i >= n) break;
        if (n%i == 0 && __gcd(i, n/i) == 1){
            int u = i, v = n/i;
            for (int j = 1; j < u; ++ j){
                if ((n-1-v*j)%u == 0){
                    cout << "YES\n2\n";
                    cout << ((n-1-v*j)/u) << " " << v << "\n";
                    cout << j << " " << u << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
