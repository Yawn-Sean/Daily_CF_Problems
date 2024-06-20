#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e8 + 7, P = 1e9 + 7;

template<typename T>
struct Matrix {
    T m, n;
    std::vector<std::vector<T>> g;
    Matrix(int _m, int _n) : m(_m), n(_n), g(m, std::vector<T>(n)) {}
    void init1 () {
        for (int i = 0; i < m; i ++ ) g[i][i] = 1;
    }
    Matrix(const Matrix& x) : m(x.m), n(x.n), g(x.g) {}
    void init (const std::vector<std::vector<T>>& _g) {
        g = _g;
    }

    Matrix<T> operator * (const Matrix<T>& x) const {
        Matrix<T> res(m, x.n);
        for (int i = 0; i < m; i ++ )
            for (int k = 0; k < n; k ++ )
                for (int j = 0; j < n; j ++ )
                    res.g[i][j] = (res[i][j] + 1LL * g[i][k] * x[k][j] % P) % P;
        return res;
    }
    const std::vector<T>& operator [] (int i) const {
        return g[i];
    }
    Matrix<T> qp(i64 b) {
        Matrix<T> res(m, n), a(*this);
        res.init1();
        while (b) {
            if (b & 1) res = res * a;
            a = a * a, b >>= 1;
        }
        return res;
    }
};

void solve() {
    i64 A, B, n, x;
    std::cin >> A >> B >> n >> x;
    Matrix<i64> ga(2, 2), gb(2, 2);
    ga.g = { { x, 1 }, { 0, 0 } }, gb.g = { { A, 0 }, { B, 1 } };
    std::cout << (ga * gb.qp(n))[0][0];
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}