// 0812
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;
    std::string s;
    std::cin >> s;

    auto check = [&](char max_char) -> std::optional<std::string> {
        int last = -1;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] <= max_char) {
                last = i;
            }
            if (i - last >= m) {
                return std::nullopt;
            }
        }

        last = -1;
        std::optional<int> try_add = std::nullopt;
        std::string ret{ "" };
        for (int i = 0; i < size(s); ++i) {
            if (s[i] < max_char) {
                last = i;
                ret.push_back(s[i]);
            } else if (s[i] == max_char) {
                try_add = i;
            }

            if (i - last >= m) {
                if (try_add.has_value()) {
                    last = try_add.value();
                    ret.push_back(s[last]);
                    try_add.reset();
                } 
            }
        }
        
        return ret;
    };

    std::string ans(size(s), 'z');
    auto max_char = *std::max_element(begin(s), end(s));
    for (char c = 'a'; c <= max_char; ++c) {
        auto ret = check(c);
        if (ret.has_value()) {
            ans = ret.value();
            std::sort(begin(ans), end(ans));
            break;
        }
    }

    std::cout << ans << '\n';

    return 0;
}