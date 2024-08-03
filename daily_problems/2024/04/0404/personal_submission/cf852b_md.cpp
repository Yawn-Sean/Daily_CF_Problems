#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, l, m;
    std::cin >> n >> l >> m;

    vector<int> src(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(src));
    vector<int> ts(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(ts));
    vector<int> dst(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(dst));

    // dp[i][j] = \sum_{k=0}^{n-1} dp[i-1][(j-w[k]) % m] ==>
    // dp[i][j] = \sum_{k=0}^{m-1} freq[k] * dp[i-1][(j-k) % m]
    vector<i64> freq(m);
    for (auto val : ts) {
        freq[val % m]++;
    }

    // 1 x m
    vector<vector<i64>> start(1, vector<i64>(m, 0));
    for (auto val : src) {
        start[0][val % m]++;
    }

    // m x m
    vector<vector<i64>> mat(m, vector<i64>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int d = (j - i + m) % m;
            mat[i][j] = freq[d];
        }
    }

    // (1 x m) * (m x m) = (1 x m)
    auto ret_mat = mat_mul(start, mat_pow(mat, l - 2, MOD), MOD);

    i64 ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += ret_mat[0][((-dst[i] - ts[i]) % m + m) % m];
        ret %= MOD;
    }
    cout << ret << endl;

    return 0;
}