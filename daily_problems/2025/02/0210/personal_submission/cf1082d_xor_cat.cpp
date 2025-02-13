#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> chain, node;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) node.push_back(i);
        else chain.push_back(i);
    }

    if (chain.empty()) {
        std::cout << "NO\n";
        return 0;
    }

    std::vector<std::array<int, 2>> ans;
    auto bind = [&](int x, int y) {
        a[x]--, a[y]--;
        ans.push_back({x, y});
    };

    std::ranges::sort(chain, [&](int i, int j) {
        return a[i] > a[j];
    });

    if (chain.size() > 2) {
        std::swap(chain[1], chain.back());
    }
    for (int i = 1; i < chain.size(); i++) {
        bind(chain[i], chain[i - 1]);
    }

    int rem = 0;
    for (int i = 0; i < chain.size(); i++) {
        rem += a[chain[i]];
    }

    if (rem < node.size()) {
        std::cout << "NO\n";
        return 0;
    }

    int p = 0;
    if (node.size() > 0) {
        if (a[chain.front()] > 0) {
            bind(node[p], chain.front());
            p++;
        }
        if (node.size() > 1) {
            if (a[chain.back()] > 0) {
                bind(node[p], chain.back());
                p++;
            }
        }
    }

    for (int i = p; i < node.size(); i++) {
        for (int j = 0; j < chain.size(); j++) {
            if (a[chain[j]] > 0) {
                bind(node[i], chain[j]);
                break;
            }
        }
    }

    std::cout << "YES ";
    std::cout << chain.size() - 1 + std::min(int(node.size()), 2) << "\n";

    std::cout << ans.size() << "\n";
    for (auto &[u, v] : ans) {
        std::cout << u + 1 << " " << v + 1 << "\n";
    }

    return 0;
}
