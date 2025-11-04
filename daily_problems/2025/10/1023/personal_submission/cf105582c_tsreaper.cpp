#include <bits/stdc++.h>
#define MAXN 50
#define MAXM ((int) 1e4)
using namespace std;

int n, L, R, A[MAXN + 5], B[MAXN + 5];
bool f[MAXN + 5][MAXM + 5];

bool check(int lim) {
    if (lim == 0) return true;

    for (int i = 0; i <= n; i++) for (int j = 0; j <= R; j++) f[i][j] = false;
    f[0][0] = true;
    for (int i = 1; i <= n; i++) {
        int r = B[i] / lim;
        for (int t = 0; t < A[i]; t++) for (int j = t, now = 0; j <= R; j += A[i]) {
            if (f[i - 1][j]) now++;
            if (now) f[i][j] = true;
            if (j - 1LL * r * A[i] >= 0 && f[i - 1][j - r * A[i]]) now--;
        }
    }

    for (int i = L; i <= R; i++) if (f[n][i]) return true;
    return false;
}

int main() {
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);

    int head = 0, tail = 1e6;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", head);
    return 0;
}
