int n;
ll p, q;

struct frac {
    ll x, y;//x分子，y分母 
    frac(ll xx = 0, ll yy = 0){
        x = xx;
        y = yy;
    }
    frac re() {
        if (y < 0) x = -x, y = -y;
        if (x != 0 and y == 0) x = 1;
        else if (x == 0 and y != 0) y = 1;
        else if (x != 0 and y != 0) {
            ll z = gcd(abs(x), abs(y));
            x /= z;
            y /= z;
        }
        return *this;
    }
    frac operator+ (const frac w) const {
        ll z = y / gcd(y, w.y) * w.y;
        return frac(x * (z / y) + w.x * (z / w.y), z).re();
    }
    frac operator- (const frac w) const {
        ll z = y /gcd(y,w.y)*w.y;
        return frac(x * (z / y) - w.x * (z / w.y), z).re();
    }
    frac operator* (const frac w) const {
        ll z1 = gcd(x,w.y),z2=gcd(y,w.x);
        return frac((x/z1)*(w.x/z2),(y/z2)*(w.y/z1)).re();
    }
    frac operator/ (const frac w) const {
        ll z1 = gcd(x, w.x), z2 = gcd(y, w.y);
        return frac((x / z1) * (w.y / z2), (y / z2) * (w.x / z1)).re();
    }
};

void solve() {
    cin >> p >> q;
    auto g = gcd(p, q);
    p /= g;
    q /= g;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    
    frac t(p, q);
    
    for (int i = 0; i < n - 1; i ++) {
        if (t.x / t.y + 1 < a[i]) {
            cout << "NO" << endl;
            return;
        }
        t = t - frac(a[i], 1);
        if (t.x <= 0) {
            cout << "NO" << endl;
            return;
        }
        t = frac(1, 1) / t;
    }
    
    if (t.x % t.y == 0 and t.x / t.y == a.back()) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}