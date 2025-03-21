void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a/2+b/2+c/2+d/2 + (a&b&c&1)) << "\n";
}
