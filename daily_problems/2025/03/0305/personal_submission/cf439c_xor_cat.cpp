#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, p;
    std::cin >> n >> k >> p;

    std::vector<int> a(n);
    std::vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] & 1) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }

    // k, now > k
    // even + even = even
    // odd + even = odd
    // odd + odd = even
    if (odd.size() < k - p || (odd.size() - (k - p)) % 2) {
        std::cout << "NO\n";
        return 0;
    }

    if (even.size() + (odd.size() - (k - p)) / 2 < p) {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<std::vector<int>> ans(k);
    for (int i = 0; i < k - p; i++) {
        ans[i].push_back(odd.back());
        odd.pop_back();
    }

    for (int i = k - p; i < k; i++) {
        if (!even.empty()) {
            ans[i].push_back(even.back());
            even.pop_back();
        } else {
            ans[i].push_back(odd.back());
            odd.pop_back();
            ans[i].push_back(odd.back());
            odd.pop_back();
        }
    }

    while (!even.empty()) {
        ans.back().push_back(even.back());
        even.pop_back();
    }
    while (!odd.empty()) {
        ans.back().push_back(odd.back());
        odd.pop_back();
    }

    std::cout << "YES\n";
    for (auto &vec : ans) {
        std::cout << vec.size() << " ";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " \n"[i == vec.size() - 1];
        }
    }

    return 0;
}
