#include <iostream>
#include <algorithm>
#include <vector>

// https://codeforces.com/contest/757/problem/C

int main () {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> tmp(m);
    for (int i = 0; i < n; i++) {
        int g;
        std::cin >> g;
        while (g--) {
            int x;
            std::cin >> x;
            tmp[x - 1].emplace_back(i);
        }
    }

    // 按照字典序排序
    sort(tmp.begin(), tmp.end());

    long long curr = 1, ans = 1, mod = 1e9 + 7;
    for (int i = 1; i < m; i++) {
        if (tmp[i] == tmp[i - 1]) curr++;
        else curr = 1;
        ans = ans * curr % mod;
    }

    std::cout << ans;

    return 0;
}