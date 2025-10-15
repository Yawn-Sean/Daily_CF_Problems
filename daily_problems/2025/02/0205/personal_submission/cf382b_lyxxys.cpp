void solve(){
    i64 a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;

    if (c <= a) cout << 0 << "\n";
    else cout << (1ll * (c - a) * w - b + w - x - 1) / (w - x) << "\n";
}
