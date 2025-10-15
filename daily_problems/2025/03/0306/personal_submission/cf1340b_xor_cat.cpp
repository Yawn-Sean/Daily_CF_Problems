#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

std::string digits[] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](std::string s, std::string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && t[i] == '0') {
                return false;
            }
        }
        return true;
    };

    auto get = [&](std::string s, std::string t) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret += (t[i] == '1' && s[i] == '0');
        }
        return ret;
    };

    std::vector f(n + 1, std::vector<int>(k + 1));
    f[n][0] = true;
    for (int i = n - 1; ~i; i--) {
        for (int j = 0; j <= k; j++) {
            if (f[i + 1][j]) {
                for (int d = 0; d < 10; d++) {
                    if (check(a[i], digits[d])) {
                        int nj = get(a[i], digits[d]);
                        if (j + nj <= k) {
                            f[i][j + nj] = true;
                        }
                    }
                }
            }
        }
    }

    if (!f[0][k]) {
        std::cout << -1 << "\n";
        return 0;
    }

    int cur = k;
    for (int i = 0; i < n; i++) {
        for (int d = 9; ~d; d--) {
            if (check(a[i], digits[d])) {
                int nj = get(a[i], digits[d]);
                if (cur >= nj && f[i + 1][cur - nj]) {
                    std::cout << d;
                    cur -= nj;
                    break;
                }
            }
        }
    }

    return 0;
}
