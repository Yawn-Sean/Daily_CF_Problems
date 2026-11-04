#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = 998244353;

i64 qpow(i64 a, i64 b) {
    i64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % md;
        }
        a = a * a % md;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;

    if (n <= 3) {
        cout << 1;
        return 0;
    }

    n -= 2;
    if (n <= 3) {
        cout << n << "\n";
    } else if (n % 3 == 0) {
        cout << qpow(3, n / 3) << "\n";
    } else if (n % 3 == 1) {
        cout << 4 * qpow(3, (n - 4) / 3) % md << "\n";
    } else {
        cout << 2 * qpow(3, (n - 2) / 3) % md << "\n";
    }
    return 0;
}