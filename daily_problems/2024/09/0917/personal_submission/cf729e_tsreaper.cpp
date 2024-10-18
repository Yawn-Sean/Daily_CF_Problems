#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, S, ans, A[MAXN + 10];
int cnt[MAXN + 10];

int main() {
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int base = 0;
    if (A[S] != 0) base++, A[S] = 0;
    for (int i = 1; i <= n; i++) if (i != S && A[i] == 0) A[i] = n;
    for (int i = 1; i <= n; i++) cnt[A[i]]++;

    ans = n;
    int sm = n, need = 0;
    for (int i = 0; i < n; i++) {
        sm -= cnt[i];
        if (cnt[i] == 0) need++;
        ans = min(ans, base + max(sm, need));
    }
    printf("%d\n", ans);
    return 0;
}
