#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    std::vector<int> cnt(26);
    for (int i = 0; i < n; ++ i) 
        ++ cnt[s[i] - 'a'], ++ cnt[t[i] - 'a'];

    for (int i = 0; i < 26; ++ i)
        if (cnt[i] & 1) {
            std::cout << "No\n";
            return;
        }

    std::vector<PII> ans;

    auto pull = [&](int i, int j) -> void {
        std::swap(s[i], t[j]);
        ans.emplace_back(i + 1, j + 1);
    };

    for (int i = 0; i < n; ++ i) {
        if (s[i] != t[i]) {
            for (int j = i + 1; j < n; ++ j) {
                if (s[i] == s[j]) {
                    pull(j, i);
                    break;
                }
                if (s[i] == t[j]) {
                    pull(i + 1, j);
                    pull(i + 1, i);
                    break;
                }
            }
        }
    }

    std::cout << "Yes\n";
    std::cout << ans.size() << '\n';

    for (auto& [a, b] : ans)
        std::cout << a << ' ' << b << '\n';
}

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}