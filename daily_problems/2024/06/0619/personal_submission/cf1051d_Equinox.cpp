#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e8 + 7, P = 998244353;

/*
0   bb
1   bw
2   wb
3   ww
*/
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<std::array<i64, 4>>> f(1001, std::vector<std::array<i64, 4>>(2001));
    f[0][1][0] = f[0][2][1] = f[0][2][2] = f[0][1][3] = 1;
    auto F = [&](int a, int b, int c) -> i64 {
        if (b < 0) return 0;
        return f[a][b][c];
    };
    for (int i = 1; i < n; i ++ ) {
        for (int j = 0; j <= k; j ++ ) {
            f[i][j][0] = (F(i - 1, j, 0) + F(i - 1, j , 1) + F(i - 1, j , 2) + F(i - 1, j - 1, 3)) % P;
            f[i][j][1] = (F(i - 1, j - 1, 0) + F(i - 1, j, 1) + F(i - 1, j - 2, 2) + F(i - 1, j - 1, 3)) % P;;
            f[i][j][2] = (F(i - 1, j - 1, 0) + F(i - 1, j - 2, 1) + F(i - 1, j, 2) + F(i - 1, j - 1, 3)) % P;;
            f[i][j][3] = (F(i - 1, j - 1, 0) + F(i - 1, j, 1) + F(i - 1, j, 2) + F(i - 1, j, 3)) % P;;
        }
    }
    i64 res = 0;
    for (int i = 0; i < 4; i ++ )
        res = (res + f[n - 1][k][i]) % P;
    std::cout << res;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}