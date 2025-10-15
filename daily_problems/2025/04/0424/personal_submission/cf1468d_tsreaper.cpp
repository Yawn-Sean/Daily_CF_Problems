#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, X, Y, Z, T, A[MAXN + 5];

bool check(int lim) {
    for (int i = lim; i > 0; i--) if ((lim - i + 1) + A[i] > T) return false;
    return true;
}

void solve() {
    scanf("%d%d%d%d", &X, &n, &Y, &Z);
    if (Y < Z) T = (Y - 1) + (Z - Y);
    else T = (X - Y) + (Y - Z);

    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    int head = 0, tail = min(abs(Y - Z) - 1, n);
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (check(mid)) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", head);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
