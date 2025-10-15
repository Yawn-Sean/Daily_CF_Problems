void solve(){
    i64 L, w, b;
    cin >> L >> w >> b;
    if (w < b) swap(w, b);

    i64 l = (__int128_t)w*b / __gcd(w,b) > L ? L+1 : (__int128_t)w*b / __gcd(w,b);
    i64 k = L/l;
    i64 p = k*b + min(b, L%l+1) - 1;

    i64 q = L, d = __gcd(p, q);
    p /= d, q /= d;
    cout << p << "/" << q << "\n";
}
