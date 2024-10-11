#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 1e9 + 7;
/*
    x1/y1   x2/y2

    x1 = y2
    x1 + x2 = y2 + x2
*/
void solve() {
    int n;
    std::cin >> n;
    
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int tot = 0;
    std::vector<std::vector<int>> cnt(3);
    for (int i = 0; i < n; ++ i )
        cnt[(s1[i] ^ 48) + (s2[i] ^ 48)].push_back(i + 1), tot += (s1[i] ^ 48);

    for (int i = 0; i <= cnt[2].size(); ++ i) {
        int j = tot - i * 2;
        if (j >= 0 && j <= cnt[1].size() && n / 2 - i - j >= 0 && n / 2 - i - j <= cnt[0].size()) {
            for (int k = i; k < cnt[2].size(); ++ k) std::cout << cnt[2][k] << ' ';
            for (int k = j; k < cnt[1].size(); ++ k) std::cout <<  cnt[1][k] << ' ';
            for (int k = n / 2 - i - j; k < cnt[0].size(); ++ k) std::cout << cnt[0][k] << ' ';
            return;
        }
    }
    std::cout << -1;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}