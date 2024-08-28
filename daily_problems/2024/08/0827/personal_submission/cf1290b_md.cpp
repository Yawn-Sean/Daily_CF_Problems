// 0827
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> prefix(26, std::vector<int>(size(s) + 1));
    for (int ch = 0; ch < 26; ++ch) {
        for (int i = 0; i < size(s); ++i) {
            prefix[ch][i + 1] = prefix[ch][i] + (s[i] == ('a' + ch));
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l, --r;

        int cnt = 0;
        for (int ch = 0; ch < 26; ++ch) {
            cnt += (prefix[ch][r + 1] - prefix[ch][l]) > 0;
        }

        if (l == r || s[l] != s[r] || cnt > 2) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}
