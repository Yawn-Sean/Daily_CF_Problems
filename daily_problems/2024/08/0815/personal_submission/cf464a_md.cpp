// 0815
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;
    std::string s;
    std::cin >> s;

    bool changed = false;
    for (int i = n - 1; i >= 0 && !changed; --i) {
        for (char c = s[i] + 1; c < p + 'a'; ++c) {
            if ((i - 1 >= 0 && c == s[i - 1]) || (i - 2 >= 0 && c == s[i - 2])) {
                continue;
            }
            s[i] = c;
            for (int r = i + 1; r < n; ++r) {
                for (char cur_ch = 'a'; cur_ch < p + 'a'; ++cur_ch) {
                    if ((r - 1 >= 0 && s[r - 1] == cur_ch) || (r - 2 >= 0 && s[r - 2] == cur_ch)) {
                        continue;
                    }
                    s[r] = cur_ch;
                    break;
                }
            }
            changed = true;
            break;
        }
    }

    if (changed) {
        std::cout << s << '\n';
    } else {
        std::cout << "NO\n";
    }

    return 0;
}