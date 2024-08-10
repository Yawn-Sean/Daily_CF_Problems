// 0628
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    for (auto ch = 'z'; ch >= 'b'; --ch) {
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == ch) {
                if ((i > 0 && s[i - 1] == ch - 1) || (i + 1 < size(s) && s[i + 1] == ch - 1)) {
                    s = s.substr(0, i) + s.substr(i + 1);
                    i = -1;
                }
            }
        }
    }

    std::cout << n - size(s) << '\n';

    return 0;
}