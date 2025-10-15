#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans, A[MAXN + 5];
int pos[MAXN + 5], f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        pos[A[i]] = i;
    }
    for (int i = n; i > 0; i--) {
        if (pos[i + 1] >= pos[i]) f[i] = f[i + 1] + 1;
        else f[i] = 1;
    }

    ans = n;
    for (int i = 0; i < n; i++) ans = min(ans, i + (n - i - f[i + 1]));
    printf("%d\n", ans);
    return 0;
}
