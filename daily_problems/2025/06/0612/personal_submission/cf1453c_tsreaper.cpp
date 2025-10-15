#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n;
char MAP[MAXN + 5][MAXN + 5];

void solve() {
    scanf("%d", &n);

    int U[10], D[10], L[10], R[10];
    for (int i = 0; i < 10; i++) {
        U[i] = L[i] = n + 1;
        D[i] = R[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", MAP[i] + 1);
        for (int j = 1; j <= n; j++) {
            int x = MAP[i][j] - '0';
            U[x] = min(U[x], i);
            D[x] = max(D[x], i);
            L[x] = min(L[x], j);
            R[x] = max(R[x], j);
        }
    }

    int ans[10] = {0};
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        int x = MAP[i][j] - '0';
        int d = max(i - 1, n - i), h = max(j - L[x], R[x] - j);
        ans[x] = max(ans[x], d * h);
        d = max(j - 1, n - j); h = max(i - U[x], D[x] - i);
        ans[x] = max(ans[x], d * h);
    }
    for (int i = 0; i < 10; i++) printf("%d%c", ans[i], "\n "[i < 9]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
