#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

i64 qpow(i64 a, i64 b, i64 m) {
    i64 ans = 1;
    a %= m;
    while (b) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    /*
    

    */
    int n, k;
    cin >> n >> k;
    i64 ans = 0;
    i64 cur = 1ll;
    for (int cnt = 0; cnt <= min(n, k); cnt++) {
        ans += cur * (qpow(cnt + 1, k - cnt + 1, mod) - qpow(cnt, k - cnt + 1, mod)) % mod;
        cur = cur * (n - cnt) % mod * (cnt + 1) % mod;
    }
    cout << (ans % mod + mod) % mod << '\n';
    return 0;
}
