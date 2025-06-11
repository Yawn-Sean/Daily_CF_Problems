#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, S, T, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];

bool check(long long lim) {
    long long ret = 0;
    for (int i = 1; i <= m; i++) {
        long long det = C[i] - C[i - 1];
        if (det * 2 <= lim) ret += det;
        else if (det > lim) return false;
        else {
            long long x = det * 2 - lim, y = det - x;
            ret += x * 2 + y;
        }
    }
    return ret <= T;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &C[i]);
    C[++m] = S;
    sort(C + 1, C + m + 1);

    if (!check(S)) { printf("-1\n"); return 0; }

    long long head = 0, tail = S;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }

    int ans = 2e9;
    for (int i = 1; i <= n; i++) if (B[i] >= head) ans = min(ans, A[i]);
    if (ans < 2e9) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
