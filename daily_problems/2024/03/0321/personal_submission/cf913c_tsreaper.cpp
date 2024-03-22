#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

int n;
long long L, A[MAXN + 5];

int main() {
    scanf("%d%lld", &n, &L);
    for (int i = 0; i < n; i++) scanf("%lld", &A[i]);
    for (int i = 1; i < n; i++) A[i] = min(A[i], A[i - 1] * 2);
    for (int i = n; i <= MAXN; i++) A[i] = A[i - 1] * 2;

    long long ans = A[MAXN], now = 0;
    for (int i = MAXN - 1; i >= 0; i--) {
        if (L >> i & 1) now += A[i];
        else ans = min(ans, now + A[i]);
    }
    ans = min(ans, now);
    printf("%lld\n", ans);
    return 0;
}
