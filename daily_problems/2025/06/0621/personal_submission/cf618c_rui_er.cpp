const ll N = 1e5 + 5;

ll n, x[N], y[N];

inline ll sq(ll x) {return x * x;}
inline ll dis2(ll x1, ll y1, ll x2, ll y2) {return sq(x1 - x2) + sq(y1 - y2);}
inline ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll xa = x2 - x1, ya = y2 - y1;
    ll xb = x3 - x1, yb = y3 - y1;
    return xa * yb - xb * ya;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> x[i] >> y[i];
    ll p = 2, dm = dis2(x[1], y[1], x[2], y[2]);
    rep(i, 3, n) {
        ll d0 = dis2(x[1], y[1], x[i], y[i]);
        if(d0 < dm) dm = d0, p = i;
    }
    ll q = -1, Sm = 9e18;
    rep(i, 2, n) {
        if(i != p) {
            ll S = area(x[1], y[1], x[p], y[p], x[i], y[i]);
            if(S != 0 && abs(S) < abs(Sm)) Sm = S, q = i;
        }
    }
    cout << 1 << " " << p << " " << q << endl;
    return 0;
}
