#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, K, A[MAXN + 5], B[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
    sort(A + 1, A + n + 1);
    sort(B + 1, B + m + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= m && A[i] > B[j]) j++;
        if (j > m) { printf("YES\n"); return 0; }
        j++;
    }
    printf("NO\n");
    return 0;
}
