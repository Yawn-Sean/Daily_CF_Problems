// 0719
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> freq(26);
    for (auto ch : s) {
        ++freq[ch - 'a'];
    }
    for (auto ch : t) {
        ++freq[ch - 'a'];
    }

    for (auto val : freq) {
        if (val % 2) {
            std::cout << "No\n";
            return;
        }
    }

    std::vector<pii> ret;
    auto swap = [&](int i, int j) {
        std::swap(s[i], t[j]);
        ret.emplace_back(i, j);
    };

    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            continue;
        }

        auto found = [&] () {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    swap(j, i);
                    return true;
                }
            }
            return false;
        } ();

        if (!found) {
            found = [&] () {
                for (int j = i + 1; j < n; ++j) {
                    if (s[i] == t[j]) {
                        swap(i + 1, j);
                        swap(i + 1, i);
                        return true;
                    }
                }
                return false;
            } ();
        }

        if (!found) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n" << size(ret) << '\n';
    for (auto [i, j] : ret) {
        std::cout << i + 1 << ' ' << j + 1 << '\n';
    }
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