const ll N = 2e5 + 5;

ll T, n, c;

struct Pair {
    ll a, b;
    friend bool operator<(Pair p, Pair q) {
        return p.b < q.b;
    }
}a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> c;
        rep(i, 1, n) cin >> a[i].a;
        rep(i, 1, n) a[i].b = i * c - a[i].a;
        sort(a + 2, a + 1 + n);
        ll S = a[1].a;
        bool ok = true;
        rep(i, 2, n) {
            if(S >= a[i].b) S += a[i].a;
            else {ok = false; break;}
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
