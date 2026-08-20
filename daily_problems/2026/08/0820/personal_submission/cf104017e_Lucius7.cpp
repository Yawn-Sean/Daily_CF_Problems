#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;


    std::vector<char> stks, stkt;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'C') {
            if (!stks.empty() && stks.back() == s[i]) {
                stks.pop_back();
            } else {
                stks.push_back(s[i]);
            }
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'A' || t[i] == 'C') {
            if (!stkt.empty() && stkt.back() == t[i]) {
                stkt.pop_back();
            } else {
                stkt.push_back(t[i]);
            }
        }
    }

    if (stks == stkt && std::count(s.begin(), s.end(), 'B') % 2 == std::count(t.begin(), t.end(), 'B') % 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
