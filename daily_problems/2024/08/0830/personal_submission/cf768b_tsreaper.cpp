#include <bits/stdc++.h>
#define MAXP 50
using namespace std;

long long f[MAXP];

long long gao(long long n, int d, long long pos) {
    if (pos == 0) return 0;
    if (d == 0) return n;
    if (f[d - 1] >= pos) return gao(n / 2, d - 1, pos);
    else if (f[d - 1] + 1 == pos) return n / 2 + n % 2;
    else return n / 2 + n % 2 + gao(n / 2, d - 1, pos - f[d - 1] - 1);
}

int main() {
    f[0] = 1;
    for (int p = 1; p < MAXP; p++) f[p] = f[p - 1] * 2 + 1;

    long long n, l, r; scanf("%lld%lld%lld", &n, &l, &r);
    printf("%lld\n", gao(n, __lg(n), r) - gao(n, __lg(n), l - 1));
    return 0;
}
