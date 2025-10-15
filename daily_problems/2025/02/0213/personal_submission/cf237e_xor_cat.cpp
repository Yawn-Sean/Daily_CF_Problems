#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string t;
    std::cin >> t;

    int tar = t.size();
    std::vector<int> cnt(26);
    for (auto &c : t) {
        cnt[c - 'a']++;
    }

    int n;
    std::cin >> n;

    MinCostFlow<int> mcf(n + 28);
    int S = n + 26, T = n + 27;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            mcf.addEdge(n + i, T, cnt[i], 0);
        }
    }

    for (int i = 0; i < n; i++) {
        std::string s;
        int a;
        std::cin >> s >> a;
        mcf.addEdge(S, i, a, i + 1);

        std::fill(cnt.begin(), cnt.end(), 0);
        for (auto &c : s) {
            cnt[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (cnt[j]) {
                mcf.addEdge(i, n + j, cnt[j], 0);
            }
        }
    }

    auto ans = mcf.flow(S, T);
    std::cout << (ans.first == tar ? ans.second : -1) << "\n";

    return 0;
}
