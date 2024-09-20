int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, n;
    cin >> x >> y >> n;
    ll ggg = gcd(x, y);
    x /= ggg;
    y /= ggg;
    //cout << x << ' ' << y ;return 0;
    ll a = x / y;
    x %= y;
    if(n >= y) {
        cout << x + a * y << "/" << y << "\n";
        return 0;
    }
    
    pii ans = {0, n};
    db dif = db(x) / db(y);
    auto get = [&](int u) {
        ll temp = x * u / y;
        if(ab(x * u - temp * y) > ab(x * u - (temp + 1) * y)) {
            temp++;
        }
        if(dif > ab_(db(x) / db(y) - db(temp) / db(u))){
            dif = ab_(db(x) / db(y) - db(temp) / db(u));
            ans = {temp, u};
        }
    };
    for(int i = 1; i <= n; i++){
        get(i);
    }
    ans.fi += a * ans.se;
    ggg = gcd(ans.fi, ans.se);
    ans.fi /= ggg, ans.se /= ggg;
    cout << ans.fi << "/" << ans.se << "\n";
}
