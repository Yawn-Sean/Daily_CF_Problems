int n;

bool check(int x) {
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}
void solve() {
    cin >> n;
    // 1/2 - 1/v(n) + (n-v(i)+1) / u(n) / v(n)
    
    auto v = n, u = n + 1;
    while (!check(u)) u ++;
    while (!check(v)) v --;
    
    ll down = (ll)u * v * 2;
    ll up = (ll)u * (v - 2) + 2ll * (n - v + 1);
    
    auto t = gcd(up, down);
    
    down /= t;
    up /= t;
    
    cout << up << '/' << down << endl;
}