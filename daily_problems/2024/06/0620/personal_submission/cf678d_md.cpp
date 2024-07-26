// 0620
#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 MOD = 1e9 + 7;

template <typename T = i64>
std::vector<std::vector<T>> mat_mul_cache_optimized(std::vector<std::vector<T>> a, std::vector<std::vector<T>> b, T mod) {
    int n = std::size(a);
    int l = std::size(a[0]);
    int l2 = std::size(b);
    assert(l == l2);  // (n x l) * (l x m)

    // Transpose the matrix b to make it sequential in memory to increase the cache hit rate.
    std::vector<std::vector<T>> transb(size(b[0]), std::vector<T>(l2));
    for (int i = 0; i < l2; ++i) {
        for (int j = 0; j < size(b[0]); ++j) {
            transb[j][i] = b[i][j];
        }
    }

    int m = std::size(b[0]);
    std::vector<std::vector<T>> res(n, std::vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                res[i][j] += a[i][k] * transb[j][k];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

template <typename T = i64>
std::vector<std::vector<T>> mat_pow(std::vector<std::vector<T>> a, T b, T mod) {
    // Matrix exponentiation
    int n = std::size(a);
    std::vector<std::vector<T>> res(n, std::vector<T>(n));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = mat_mul_cache_optimized(res, a, mod);
        }
        a = mat_mul_cache_optimized(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Similar to abc293e
// an = A B    an-1 = A B ^ n * a0
//  1   0 1    1      0 1       1
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 a, b, n, x;
    std::cin >> a >> b >> n >> x;
    std::vector<std::vector<i64>> mat{{a, b}, {0, 1}};
    auto retmat = mat_mul_cache_optimized(mat_pow(mat, n, MOD), {{x}, {1}}, MOD);
    std::cout << retmat[0][0] << std::endl;
    return 0;
}
