#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K;
long long A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];

bool check(long long lim) {
    int bad = 0;
    for (int i = 1; i < n; i++) if (A[i + 1] - A[i] > lim) {
        if (bad > 0) return false;
        bad = i;
    }
    if (bad == 0) return true;

    long long l = A[bad + 1] - lim, r = A[bad] + lim;
    if (l > r) return false;

    for (int i = m, j = 1; i > 0; i--) {
        while (j <= K && B[i] + C[j] < l) j++;
        if (j <= K && B[i] + C[j] <= r) return true;
    }
    for (int i = 1, j = K; i <= m; i++) {
        while (j > 0 && B[i] + C[j] > r) j--;
        if (j > 0 && B[i] + C[j] >= l) return true;
    }
    return false;
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i]);
    sort(B + 1, B + m + 1);
    for (int i = 1; i <= K; i++) scanf("%lld", &C[i]);
    sort(C + 1, C + K + 1);

    long long head = 1, tail = 0;
    for (int i = 1; i < n; i++) tail = max(tail, A[i + 1] - A[i]);
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%lld\n", head);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
