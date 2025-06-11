#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, X, Y, ans, A[MAXN + 5], B[MAXN + 5];

int f[2][MAXN + 5];
vector<int> vec[MAXN + 5];

int main() {
    scanf("%d%d%d%d", &n, &m, &X, &Y);
    int mx = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mx = max(mx, A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]), mx = max(mx, B[i]);

    for (int r = 1; r <= X / Y; r++) {
        for (int i = 1; i <= mx; i++) vec[i].clear();
        for (int i = 0; i <= n; i++) f[r & 1][i] = m + 1;
        for (int i = n, j = 1; ; i--) {
            int bgn;
            if (i == 0) bgn = m + 1;
            else bgn = f[r & 1 ^ 1][i - 1] + 1;
            while (j < bgn) {
                for (int x : vec[B[j]]) f[r & 1][x] = j;
                vec[B[j]].clear();
                j++;
            }
            if (i == 0) break;
            else vec[A[i]].push_back(i);
        }
        int mn = n + m + 1;
        for (int i = 1; i <= n; i++) if (f[r & 1][i] <= m) mn = min(mn, i + f[r & 1][i]);
        if (mn <= n + m && r * Y + mn <= X) ans = r;
        for (int i = 1; i <= n; i++) f[r & 1][i] = min(f[r & 1][i], f[r & 1][i - 1]);
    }
    printf("%d\n", ans);
    return 0;
}
