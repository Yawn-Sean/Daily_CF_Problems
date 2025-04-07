#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, A[MAXN + 5];
long long B[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (n == 1) { printf("%lld\n", (1LL << A[1]) - 1); return; }

    int mx = -1, pos = 0;
    for (int i = 2; i <= n; i++) {
        int det = A[i] - A[i - 1];
        det = -det + 1;
        if (det > mx) mx = det, pos = i;
    }

    long long base = (1LL << A[pos]) - 1;
    base <<= mx;
    base -= pos;
    for (int i = 1; i <= n; i++) B[i] = ++base;
    for (int i = 1; i <= n; i++) if (__builtin_popcountll(B[i]) != A[i]) { printf("-1\n"); return; }
    printf("%lld\n", B[1]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
