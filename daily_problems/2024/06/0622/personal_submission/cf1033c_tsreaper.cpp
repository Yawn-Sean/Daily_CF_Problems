#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 10];

int f[MAXN + 10];

int dp(int pos) {
    if (f[pos] >= 0) return f[pos];
    for (int i = pos - A[pos]; i > 0; i -= A[pos])
        if (A[i] > A[pos] && !dp(i)) return f[pos] = 1;
    for (int i = pos + A[pos]; i <= n; i += A[pos])
        if (A[i] > A[pos] && !dp(i)) return f[pos] = 1;
    return f[pos] = 0;
}

int main() {
    scanf("%d", &n);
    memset(f, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        if (dp(i)) printf("A");
        else printf("B");
    printf("\n");
    return 0;
}
