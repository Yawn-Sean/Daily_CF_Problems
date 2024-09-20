ll x, y, n;

void solve() {
    cin >> x >> y >> n;
    double mn = 1e18;
    ll resa = -1, resb = inf;
    // 枚举b bx-ay <= res * b * y (a<=n)
    
    auto check = [&](ll a, ll b) -> bool {
        if (resa * b == resb * a) return false;
        if (2 * x * resb * b == resa * y * b + a * y * resb) return false;
        return true;
    };
    
    for (ll b = 1; b <= n; b ++) {
        ll a = b * x / y;
        if (mn > (double)x / y - (double)a / b and check(a, b)) {
            mn = (double)x / y - (double)a / b;
            resa = a, resb = b;
        }
        a += 1;
        if (mn > (double)a / b - (double)x / y and check(a, b)) {
            mn = (double)a / b - (double)x / y;
            resa = a, resb = b;
        }
    }
    
    cout << resa << '/' << resb << endl;
}