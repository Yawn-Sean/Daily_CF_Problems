#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K;
array<int, 3> A[MAXN + 10];

array<int, 3> B[MAXN + 10];

long long gao(long long X, long long Y) {
    X *= K; Y *= K;

    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        B[i] = A[i];
        X -= B[i][0];
        ret += 1LL * B[i][0] * B[i][1];
    }

    for (int i = 1; i <= n; ) {
        long long det = 0;
        if (X < 0) det = min(-X, 1LL * B[i][0]);
        else if (B[i][2] > B[i][1]) det = min(Y, 1LL * B[i][0]);
        if (det == 0) break;
        B[i][0] -= det;
        X += det;
        Y -= det;
        ret += (B[i][2] - B[i][1]) * det;
        if (B[i][0] == 0) i++;
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    long long sm1 = 0, sm2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]);
        sm1 += A[i][0];
        if (A[i][1] < A[i][2]) sm2 += A[i][0];
    }
    sort(A + 1, A + n + 1, [&](array<int, 3> &a, array<int, 3> &b) {
        return a[2] - a[1] > b[2] - b[1];
    });

    long long tot = (sm1 + K - 1) / K, ans = 0;
    for (int d = -2; d <= 2; d++) {
        long long w = sm2 / K + d;
        if (w >= 0 && w <= tot) ans = max(ans, gao(tot - w, w));
    }
    printf("%lld\n", ans);
    return 0;
}
