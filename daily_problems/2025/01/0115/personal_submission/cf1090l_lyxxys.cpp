void solve(){
    i64 t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    if (k > n){
        cout << 0 << "\n";
        return;
    }
    i64 w1 = (n+1)/2, w2 = n/2;
    i64 ans = min(t, (w1*a+w2*b) / k);

    if (k > w1) fmin(ans, (w2*b)/(k-w1));
    if (k > w2) fmin(ans, (w1*a)/(k-w2));

    cout << ans << "\n";
}
