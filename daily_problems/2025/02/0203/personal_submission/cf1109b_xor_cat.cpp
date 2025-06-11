#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();

    if (std::ranges::count(s, s[0]) >= (n - (n % 2))) {
        std::cout << "Impossible\n";
        return 0;
    }

    if (n % 2 == 1) {
        std::cout << 2 << "\n";
    } else {
        std::string s0 = s.substr(0, n / 2);
        std::string s1 = s.substr(n / 2);
        if (s0 != s1) {
            std::cout << 1 << "\n";
        } else {
            while (s0 == s1 && s0.size() >= 2) {
                auto s2 = s0;
                s0 = s2.substr(0, s2.size() / 2);
                s1 = s2.substr(s2.size() / 2);
                auto s3 = s0;
                std::ranges::reverse(s3);
                if (s0 != s1 && s3 == s1) {
                    std::cout << 1 << "\n";
                    return 0;
                }
            }
            std::cout << 2 << "\n";
        }
    }

    return 0;
}
