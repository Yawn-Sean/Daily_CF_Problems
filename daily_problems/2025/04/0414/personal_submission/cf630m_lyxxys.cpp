void solve(){
    i64 x;
    cin >> x;
    x %= 360;
    if (x < 0) x += 360;
    x = (360 - x) % 360;

    i64 ans = 0;
    while (!(x >= 0 && x <= 45 || x >= 315 && x < 360)){
        ans += 1;
        x += 90;
        x %= 360;
    }

    cout << ans << "\n";
}
