#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
using i128 = __int128;
std::ostream& operator<< (std::ostream& out, i128 x) {
    std::string s;
    while (x) s += ((x % 10) ^ 48), x /= 10;
    std::reverse(s.begin(), s.end());
    return out << s;
}

void solve() {
    
}


int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}