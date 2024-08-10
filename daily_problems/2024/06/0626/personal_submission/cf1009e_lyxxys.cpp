#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5, mod = 998244353;

void solve() {
    ll n;
    cin >> n;
    function<int(int, int)> pows = [&](int a, int b){
        if (b < 0) return 0;
        int res = 1;
        while (b){
            if (b&1) res = 1ll*res*a % mod;;
            a = 1ll*a*a % mod;
            b >>= 1;
        }
        return res;
    };
    int res = 0;
    for (int i = 1; i <= n; ++ i){
        ll x;
        cin >> x;
        // 令k = n-i
        // 1*C_k_0 + 2*C_k_1 + 3*C_k_2 + ··· + (k+1)*C_k_k = n * 2^(n-1) + 2^(n)
        res += ((n-i)*pows(2, n-i-1)%mod + pows(2, n-i))%mod *x%mod;
        res %= mod;
    }
    cout << res << "\n";
}
