#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, X1, X2, Y1, Y2, A[MAXN + 5];
long long K;

long long calc(int lim) {
    long long a = 1LL * X2 / gcd(X2, Y2) * Y2;
    a = lim / a;
    int b = lim / X2 - a, c = lim / Y2 - a;

    long long ret = 0;
    for (int i = 1; i <= a; i++) ret += A[i] / 100 * (X1 + Y1);
    for (int i = a + 1; i <= a + b; i++) ret += A[i] / 100 * X1;
    for (int i = a + b + 1; i <= a + b + c; i++) ret += A[i] / 100 * Y1;
    return ret;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1, greater<int>());
    scanf("%d%d%d%d%lld", &X1, &X2, &Y1, &Y2, &K);
    if (X1 < Y1) swap(X1, Y1), swap(X2, Y2);

    if (calc(n) < K) { printf("-1\n"); return; }
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (calc(mid) >= K) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
