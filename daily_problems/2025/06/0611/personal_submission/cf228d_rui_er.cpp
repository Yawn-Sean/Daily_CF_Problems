const ll N = 1e5 + 5, Z = 7;

ll n, a[N], m, S[Z][2 * Z];

struct BIT {
    ll c[N];
    ll lowbit(ll x) {return x & -x;}
    void add(ll x, ll k) {for(; x <= n; x += lowbit(x)) c[x] += k;}
    ll ask(ll x) {ll k = 0; for(; x; x ^= lowbit(x)) k += c[x]; return k;}
    ll ask(ll l, ll r) {return ask(r) - ask(l - 1);}
}bit[Z][2 * Z];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(z, 2, 6) {
        ll T = 2 * (z - 1);
        rep(k, 0, T - 1) {
            if(!k) S[z][k] = 2;
            else if(k <= z) S[z][k] = k;
            else S[z][k] = 2 * z - k;
            // cout << S[z][k] << " \n"[k == T - 1];
        }
    }
    rep(z, 2, 6) {
        ll T = 2 * (z - 1);
        rep(k, 0, T - 1) {
            rep(i, 1, n) {
                ll j = ((i - k + 1) % T + T) % T;
                bit[z][k].add(i, +a[i] * S[z][j]);
            }
        }
    }
    cin >> m;
    while(m--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll i, x;
            cin >> i >> x;
            rep(z, 2, 6) {
                ll T = 2 * (z - 1);
                rep(k, 0, T - 1) {
                    ll j = ((i - k + 1) % T + T) % T;
                    bit[z][k].add(i, -a[i] * S[z][j]);
                }
            }
            a[i] = x;
            rep(z, 2, 6) {
                ll T = 2 * (z - 1);
                rep(k, 0, T - 1) {
                    ll j = ((i - k + 1) % T + T) % T;
                    bit[z][k].add(i, +a[i] * S[z][j]);
                }
            }
        }
        else {
            ll l, r, z;
            cin >> l >> r >> z;
            ll T = 2 * (z - 1), k = l % T;
            cout << bit[z][k].ask(l, r) << endl;
        }
    }
    return 0;
}
