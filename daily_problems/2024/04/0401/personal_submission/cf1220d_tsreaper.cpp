#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 60
using namespace std;

int n;
long long A[MAXN + 10];

int f[MAXN + 5], cnt[MAXP + 5];

int main() {
    int n;scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        for (long long x = A[i]; x & 1 ^ 1; x >>= 1) f[i]++;
        cnt[f[i]]++;
    }

    int best = 0;
    for (int p = 1; p < MAXP; p++) if (cnt[p] > cnt[best]) best = p;
    printf("%d\n", n - cnt[best]);
    for (int i = 1; i <= n; i++) if (f[i] != best) printf("%lld ", A[i]);
    printf("\n");
    return 0;
}
