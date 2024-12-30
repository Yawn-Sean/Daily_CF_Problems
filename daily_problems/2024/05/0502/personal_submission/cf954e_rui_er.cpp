const ll N = 2e5 + 5;

ll n, T, lsum, rsum;
double ans;

struct Water {
    ll a, t;
    Water(ll a = 0, ll t = 0) : a(a), t(t) {}
    friend bool operator<(Water a, Water b) {return a.t < b.t;}
}a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> T;
    rep(i, 1, n) cin >> a[i].a;
    rep(i, 1, n) {
        cin >> a[i].t;
        a[i].t -= T;
        if(a[i].t < 0) lsum += a[i].a * -a[i].t;
        else if(a[i].t == 0) ans += a[i].a;
        else rsum += a[i].a * a[i].t;
    }
    sort(a + 1, a + 1 + n);
    if(lsum < rsum) {
        rep(i, 1, n) {
            if(a[i].t < 0) ans += a[i].a;
            else if(a[i].t > 0) {
                if(a[i].a * a[i].t <= lsum) {
                    lsum -= a[i].a * a[i].t;
                    ans += a[i].a;
                }
                else {
                    ans += 1.0 * lsum / a[i].t;
                    break;
                }
            }
        }
    }
    else {
        per(i, n, 1) {
            if(a[i].t > 0) ans += a[i].a;
            else if(a[i].t < 0) {
                if(a[i].a * -a[i].t <= rsum) {
                    rsum -= a[i].a * -a[i].t;
                    ans += a[i].a;
                }
                else {
                    ans += 1.0 * rsum / -a[i].t;
                    break;
                }
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
    return 0;
}
