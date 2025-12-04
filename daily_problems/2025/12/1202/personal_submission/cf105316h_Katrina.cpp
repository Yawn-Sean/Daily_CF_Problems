#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << endl;


const int MOD = 998244353;
const int N = 1e5 + 5;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return qpow(a, MOD - 2); }

vector<ll> f(N + 1, 1), i_f(N + 1);
void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (n + 1) * f[i] % MOD * i_f[i + 1] % MOD) % MOD;
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= N; ++i) f[i] = f[i - 1] * i % MOD;
    i_f[N] = inv(f[N]);
    for (int i = N; i; --i) i_f[i - 1] = i_f[i] * i % MOD;

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
