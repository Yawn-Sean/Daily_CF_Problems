void solve(){
    int n;
    f64 tar;
    cin >> n >> tar;
    const f64 all = n*(n-1)*(n-2)/6;
    for (int i = 0; i <= n; ++ i){
        i64 x = n-i;
        f64 prob = 0;
        prob += 1.0*i * x * (x-1) / 4;
        prob += i * (i-1) / 2 * x;
        prob += i * (i-1) * (i-2) / 6;
        if (prob/all >= tar){
            cout << i << "\n";
            break;
        }
    }
}
