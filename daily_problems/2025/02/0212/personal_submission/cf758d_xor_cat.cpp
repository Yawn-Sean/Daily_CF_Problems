#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::string k;
    std::cin >> n >> k;

    i64 ans = 0, base = 1;
    for (int r = k.size() - 1, l; r >= 0; r = l - 1) {
        l = r;
        i64 cur = k[l] - '0', v = 1;
        for (int i = l - 1; i >= std::max(0, l - 16); i--) {
            v *= 10;
            u128 now = (k[i] - '0') * v;
            if (cur + now < n) {
                l = i;
                cur += now;
            } else {
                break;
            }
        }

        while (k[l] == '0' && l < r) {
            l++;
        }

        ans += cur * base;
        base *= n;
    }

    std::cout << ans << "\n";

    return 0;
}
