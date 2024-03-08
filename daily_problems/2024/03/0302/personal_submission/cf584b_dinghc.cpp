#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1'000'000'007;

int64 binpow(int64 a, int64 b, int64 m) {
    a %= m;
    int64 res = 1LL;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    
    int ans = (binpow(3, 3*n, mod) + mod - binpow(7, n, mod)) % mod;
    cout << ans << endl;

    return 0;
}
