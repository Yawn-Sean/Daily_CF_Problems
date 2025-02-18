#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int mod = 1e9 + 7;
i64 power(i64 a, i64 b) {
    i64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i64 x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << 0;
        return 0;
    }
    i64 ans = (power(2, k) * 1LL * ((2 * x % mod - 1 + mod)) % mod) % mod + 1;
    cout << ans % mod << "\n";
    return 0;
}
