#include <bits/stdc++.h>
#define MAXP 60
using namespace std;

long long bias[MAXP];

long long val2pos(long long val) {
    int level = __lg(val);
    long long mod = 1LL << level;
    long long oldPos = val % mod;
    return (oldPos + bias[level]) % mod + mod;
}

long long pos2val(long long pos) {
    int level = __lg(pos);
    long long mod = 1LL << level;
    long long oldVal = pos % mod;
    return (oldVal - bias[level] + mod) % mod + mod;
}

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 3) {
            long long X; scanf("%lld", &X);
            while (X > 1) {
                printf("%lld ", X);
                long long pos = val2pos(X);
                pos >>= 1;
                X = pos2val(pos);
            }
            printf("1\n");
        } else {
            long long X, K; scanf("%lld%lld", &X, &K);
            int L = __lg(X);
            int R = (op == 2 ? MAXP - 1 : L);
            for (int level = L; level <= R; level++) {
                long long mod = 1LL << level;
                if (level != L) K = K * 2 % mod;
                bias[level] = (bias[level] + K % mod + mod) % mod;
            }
        }
    }
    return 0;
}
