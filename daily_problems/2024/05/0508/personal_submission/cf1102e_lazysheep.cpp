#include <ranges>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using PII = std::pair<int, int>;
 
constexpr int MOD = 998244353;
 
int power(int a, int b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b % 2) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
    std::unordered_map<int, PII> st;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (st.contains(x)) {
            st[x].second = i;
        }
        else {
            st[x] = {i, i};
        }
    }
    std::vector<PII> v;
    for (auto [x, y] : st) {
        v.push_back(y);
    }
    std::ranges::sort(v);
    int rmx = 0, cnt = 0;
    for (auto [l, r] : v) {
        if (l <= rmx) {
            rmx = std::max(r, rmx);
        }
        else {
            cnt++;
            rmx = r;
        }
    }
    int res = power(2, cnt, MOD);
 
    std::cout << res << '\n';
 
    return 0;
}
