// 0629
#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int ret{ n };
    std::string_view pattern{ "RGB" };
    for (int p = 0; p < 3; ++p) {
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] != pattern[(i + p) % 3]) {
                ++cnt;
            }
        }
        ret = std::min(ret, cnt);

        for (int i = k; i < n; ++i) {
            if (s[i - k] != pattern[((i - k) + p) % 3]) {
                --cnt;
            }

            if (s[i] != pattern[(i + p) % 3]) {
                ++cnt;
            }
            ret = std::min(ret, cnt);
        }
    }

    std::cout << ret << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}