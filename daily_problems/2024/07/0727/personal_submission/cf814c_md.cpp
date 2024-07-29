// 0727
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> results(26, std::vector<int>(n + 1));
    for (int c = 0; c < 26; ++c) {
        for (int len = 1; len <= n; ++len) {
            int left = 0;
            int cur_cnt = 0;
            for (int right = 0; right < n; ++right) {
                if (s[right] - 'a' != c) {
                    cur_cnt++;
                }
                while (cur_cnt > len) {
                    if (s[left] - 'a' != c) {
                        cur_cnt--;
                    }
                    left++;
                }
                results[c][len] = std::max(results[c][len], right - left + 1);
            }
        }
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int m;
        char c;
        std::cin >> m >> c;
        std::cout << results[c - 'a'][m] << '\n';
    }

    return 0;
}