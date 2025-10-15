#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    if (n <= 4 || k <= n) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::set<int> s{a, b, c, d};
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (s.contains(i)) {
            continue;
        }
        ans.emplace_back(i);
    }

    std::cout << a << " " << c << " ";
    for (auto &x : ans) {
        std::cout << x << " ";
    }
    std::cout << d << " " << b << "\n";
    std::cout << c << " " << a << " ";
    for (auto &x : ans) {
        std::cout << x << " ";
    }
    std::cout << b << " " << d << "\n";
    
    return 0;
}
