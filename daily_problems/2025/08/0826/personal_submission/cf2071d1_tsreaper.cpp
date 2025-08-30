#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, A[MAXN * 4 + 5], B[MAXN * 4 + 5], C[MAXN * 4 + 5];
long long L, R;

long long calc(long long X) {
    if (X < m * 2) return C[X];
    int rem = X % 4;
    if (rem >= 2) return calc(X - X % 4 + 1) + B[m - 1] * (rem - 1);
    if (B[m - 1]) return C[m * 2 - 1] + X - m * 2 + 1 - calc(X / 2 + rem) + C[m - 1];
    else return C[m * 2 - 1] + calc(X / 2 + rem) - C[m - 1];
}

void solve() {
    scanf("%d%lld%lld", &n, &L, &R);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        B[i] = B[i - 1] ^ A[i];
    }

    m = 2 << __lg(n);
    for (int i = n + 1; i < m * 2; i++) {
        A[i] = B[i / 2];
        B[i] = B[i - 1] ^ A[i];
    }
    for (int i = 1; i < m * 2; i++) C[i] = C[i - 1] + A[i];

    printf("%lld\n", calc(R) - calc(L - 1));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
