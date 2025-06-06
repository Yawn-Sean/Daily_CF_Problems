void solve(){
    const f64 sq3 = sqrtl(3);

    i64 r, h;
    cin >> r >> h;

    i64 res = 2*(h/r);
    i64 l = h%r;

    if (2*l >= sq3*r) res += 3;
    else if (2*l >= r) res += 2;
    else res += 1;

    cout << res << "\n";
}
