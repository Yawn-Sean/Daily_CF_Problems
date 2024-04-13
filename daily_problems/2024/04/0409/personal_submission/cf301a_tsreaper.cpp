#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
 
int n, ans, A[MAXN * 2 + 10];
int f[MAXN * 2 + 10];
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n * 2; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n * 2);
    for (int i = 1; i < n * 2; i++) f[i] = f[i - 1] + A[i];

    ans = -1e9;
    for (int i = 0; i < n * 2; i += 2) ans = max(ans, f[n * 2 - 1] - f[i] * 2);
    if (n % 2 == 1) for (int i = 0; i < n * 2; i++) ans = max(ans, f[n * 2 - 1] - f[i] * 2);
    printf("%d\n", ans);
    return 0;
}
