#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, X, Y;
pii A[MAXN + 5];

bool gao(int X, int Y, bool ord) {
    int lim = -1;
    for (int i = n; i > 0; i--) if (1LL * A[i].first * (n - i + 1) >= Y) { lim = i; break; }
    if (lim < 0) return false;

    for (int i = lim - 1; i > 0; i--) if (1LL * A[i].first * (lim - i) >= X) {
        printf("Yes\n");
        if (ord) {
            printf("%d %d\n", lim - i, n - lim + 1);
            for (int j = i; j < lim; j++) printf("%d ", A[j].second);
            printf("\n");
            for (int j = lim; j <= n; j++) printf("%d ", A[j].second);
            printf("\n");
        } else {
            printf("%d %d\n", n - lim + 1, lim - i);
            for (int j = lim; j <= n; j++) printf("%d ", A[j].second);
            printf("\n");
            for (int j = i; j < lim; j++) printf("%d ", A[j].second);
            printf("\n");
        }
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first), A[i].second = i;
    sort(A + 1, A + n + 1);
    if (!gao(X, Y, true) && !gao(Y, X, false)) printf("No\n");
    return 0;
}
