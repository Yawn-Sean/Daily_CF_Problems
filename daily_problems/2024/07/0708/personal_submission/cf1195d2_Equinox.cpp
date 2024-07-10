#include <bits/stdc++.h>


using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<size_t> a(n);

    for (int i = 0; i < n; i ++ ) {
        std::string s;
        std::cin >> s;
        int ps = 0;
        for (char ch : s)
            ps = (131 * ps + (ch ^ 48));
        a[i] = ps;
    }

    std::sort(a.begin(), a.end());
    a.resize(std::unique(a.begin(), a.end()) - a.begin());

    std::cout << a.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
