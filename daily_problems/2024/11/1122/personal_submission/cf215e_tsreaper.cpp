#include <bits/stdc++.h>
using namespace std;

long long f[100];

long long solve(long long x) {
    if (x == 0) return 0;
    vector<int> vec;
    for (; x; x >>= 1) vec.push_back(x & 1);
    int sz = vec.size();

    long long ret = 0;
    for (int i = 1; i < sz; i++) {
        memset(f, 0, sizeof(f));
        for (int j = 1; j < i; j++) if (i % j == 0) {
            f[j] = 1LL << (j - 1);
            for (int k = 1; k < j; k++) if (j % k == 0) f[j] -= f[k];
            ret += f[j];
        }
    }

    auto check = [&](int i, int j) {
        auto dgt = [&](int idx) {
            if (idx > i) return vec[idx];
            else return 0;
        };

        for (int k = 1; k + j <= sz; k++) {
            int x = sz - k, y = sz - k - j;
            if (x >= i && y >= i && dgt(x) != dgt(y)) return 0LL;
        }
        int rem = max(0, j - (sz - i));
        return 1LL << rem;
    };

    for (int i = sz - 2; i >= -1; i--) if (i < 0 || vec[i] == 1) {
        memset(f, 0, sizeof(f));
        for (int j = 1; j < sz; j++) if (sz % j == 0) {
            f[j] = check(i, j);
            for (int k = 1; k < j; k++) if (j % k == 0) f[j] -= f[k];
            ret += f[j];
        }
    }
    return ret;
}

int main() {
    long long l, r; scanf("%lld%lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}
