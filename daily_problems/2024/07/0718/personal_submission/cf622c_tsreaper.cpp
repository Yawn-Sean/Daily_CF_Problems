#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q, A[MAXN + 10];

int f[MAXN + 10];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    f[n] = n;
    for (int i = n - 1; i > 0; i--) {
        if (A[i] == A[i + 1]) f[i] = f[i + 1];
        else f[i] = i;
    }
    while (q--) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        if (A[l] != x) printf("%d\n", l);
        else if (f[l] < r) printf("%d\n", f[l] + 1);
        else printf("-1\n");
    }
    return 0;
}
