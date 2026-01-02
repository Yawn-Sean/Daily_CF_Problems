#include <bits/stdc++.h>
using namespace std;
//借鉴了题解:(
//想用next_permutation全排列函数来做但是没做明白
typedef long long ll;

ll quickPow(ll base, ll power, ll mod) {
    if (power == 0) return 1 % mod;
    ll cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const int M = 2e5;
    const int mod = 1e9 + 7;
    vector<ll> f(M + 1), g(M + 1);

    f[0] = 1;
    for (int i = 1; i <= M; ++i) {
        f[i] = 1ll * i * f[i - 1] % mod;
    }

    g[M] = quickPow(f[M], mod - 2, mod);
    for (int i = M; i >= 1; --i) {
        g[i - 1] = 1ll * i * g[i] % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> S(k);
        for (int i = 0; i < k; ++i) {
            cin >> S[i];
        }

        sort(S.begin(), S.end());

        vector<int> pos(n - 1, 1);
        for (int idx : S) {
            pos[idx - 1] = 0;
        }

        ll ans = f[n];
        int cur = 1;
        for (auto &x : pos) {
            if (x) {
                cur += x;
            } else {
                ans = 1ll * ans * g[cur] % mod;
                cur = 1;
            }
        }
        ans = 1ll * ans * g[cur] % mod;

        cout << ans << '\n';
    }

    return 0;
}