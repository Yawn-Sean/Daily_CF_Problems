#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
vector<vector<ll>> mat_mul(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    int n = a.size(), m = b[0].size(), p = a[0].size();
    vector<vector<ll>> c(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % (MOD - 1)) % (MOD - 1);
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll k) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;

    while (k) {
        if (k & 1) res = mat_mul(res, a);
        a = mat_mul(a, a);
        k >>= 1;
    }
    return res;
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> a = {{1, 1}, {1, 0}};
    ll x = mat_pow(a, n)[0][1];
    cout << qpow(2, x) << "\n";
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T = 1;
    // cin >> T;  
    while (T--) solve();
    return 0;
}
