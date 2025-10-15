void solve(){
    auto fout = [&](int x, int y)->void{
        cout << x << " " << y << "\n";
    };
    int b, n;
    cin >> b >> n;
    i64 cur = 1;
    for (int i = 1; i <= n; ++ i){
        cur = cur*b%n;
        if (!cur) return fout(1, i);
        if (cur == 1) return fout(2, i);
        if (cur == n-1) return fout(3, i);
    }
    cout << 0 << "\n";
}
