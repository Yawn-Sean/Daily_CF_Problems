#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXA ((int) 1e7)
using namespace std;

int n, A[MAXN + 5];
int fac[MAXA + 5], flag[MAXA + 5];

int main() {
    for (int i = 2; i <= MAXA; i++) if (fac[i] == 0) for (int j = i; j <= MAXA; j += i) fac[j] = i;

    scanf("%d", &n);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        g = gcd(g, A[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int x = A[i] / g; x > 1; x /= fac[x]) {
            if (flag[fac[x]] && flag[fac[x]] != i) { printf("NO\n"); return 0; }
            flag[fac[x]] = i;
        }
    }
    printf("YES\n");
    return 0;
}
