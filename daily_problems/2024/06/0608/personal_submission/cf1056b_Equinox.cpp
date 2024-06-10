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
    i64 res = 0, N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= M; i ++ )
        for (int j = 1; j <= M; j ++ ) 
            if ((i * i + j * j) % M == 0) {
                i64 cnt_i = (N - i + M) / M, cnt_j = (N - j + M) / M;
                res += cnt_i * cnt_j;
            }
    std::cout << res;
    /*
        a^2 + b^2 | m
        (a mod m)^2 + (b mod m)^2 | m

        x^2 + y^2 | m
        Σ(cnt_x * cnt_y)

        m(q - 1) + r <= n
        q = (n - r + m) / m

    */
}


int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
