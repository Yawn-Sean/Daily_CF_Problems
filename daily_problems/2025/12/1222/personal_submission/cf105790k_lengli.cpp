#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;
static const long long MOD_EXP = MOD - 1;

struct Matrix {
    long long a[2][2];
};

Matrix mul(const Matrix &x, const Matrix &y, long long mod) {
    Matrix r{};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            r.a[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
            }
        }
    }
    return r;
}

Matrix matrix_pow(Matrix base, long long exp, long long mod) {
    Matrix res{};
    res.a[0][0] = res.a[1][1] = 1;
    res.a[0][1] = res.a[1][0] = 0;

    while (exp > 0) {
        if (exp & 1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

long long qpow(long long a, long long b, long long mod) {
    long long r = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    Matrix fib{};
    fib.a[0][0] = 1; fib.a[0][1] = 1;
    fib.a[1][0] = 1; fib.a[1][1] = 0;

    Matrix r = matrix_pow(fib, n, MOD_EXP);

    long long Fn = r.a[0][1];  
    cout << qpow(2, Fn, MOD) << '\n';

    return 0;
}
