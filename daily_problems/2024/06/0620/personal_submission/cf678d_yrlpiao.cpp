#include <iostream>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int pw(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int yrlpSolve() {
    int a, b, n, x; cin >> a >> b >> n >> x;
    int ans;
    if (a == 1) ans = b % mod * (n % mod) % mod + x;
    else ans = b % mod * (pw(a, n) - 1) % mod * pw(a - 1, mod - 2) % mod + x % mod * pw(a, n) % mod;
    cout << ans % mod;
    return 0; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
