void solve(){
    i64 n, d, s;
    cin >> n >> d >> s;
    
    n /= s, d /= s;

    if (n <= d+1){
        cout << n*s << "\n";
        return;
    }

    n = min(n, 2*d);

    for (i64 i = 2; i <= 1000000; ++ i){
        if (n%i == 0 && n - n/i <= d){
            cout << n*s << "\n";
            return;
        }
    }
    cout << (n-1)*s << "\n";
}
