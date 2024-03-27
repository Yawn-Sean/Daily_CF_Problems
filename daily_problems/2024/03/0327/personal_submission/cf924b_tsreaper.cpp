#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 10];
double ans;

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    ans = -1;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && A[j] - A[i] <= K) j++;
        if (j - 1 > i + 1) ans = max(ans, 1.0 * (A[j - 1] - A[i + 1]) / (A[j - 1] - A[i]));
    }
    printf("%.12f\n", ans);
    return 0;
}
