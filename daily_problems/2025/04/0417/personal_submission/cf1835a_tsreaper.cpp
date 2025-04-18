#include <bits/stdc++.h>
#define MAXN 6
using namespace std;

int P[MAXN + 1];

void solve() {
    int A, B, C;
    long long K;
    scanf("%d%d%d%lld", &A, &B, &C, &K);

    for (int a = P[A - 1]; a < P[A]; a++) {
        int l = max(P[B - 1], P[C - 1] - a);
        int r = min(P[B] - 1, P[C] - 1 - a);
        if (l > r) continue;
        if (r - l + 1 >= K) {
            int b = l + K - 1;
            printf("%d + %d = %d\n", a, b, a + b);
            return;
        }
        K -= r - l + 1;
    }
    printf("-1\n");
}

int main() {
    P[0] = 1;
    for (int i = 1; i <= MAXN; i++) P[i] = P[i - 1] * 10;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
