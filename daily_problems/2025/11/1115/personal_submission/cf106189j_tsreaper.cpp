#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

int n, A[MAXN + 5];

int f[MAXN + 5][MAXN + 5], from[MAXN + 5][MAXN + 5];
vector<int> ans;

void gao(int l, int r) {
    if (l > r) return;
    if (f[l][r] == r - l + 1) {
        for (int i = l; i <= r; i++) ans.push_back(i);
        return;
    }
    if (from[l][r] == -1) gao(l + 1, r - 1);
    else gao(l, from[l][r]), gao(from[l][r] + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int i = 1; i < n; i++) {
        f[i][i + 1] = 2;
        if (A[i] % A[i + 1] == 0 || A[i + 1] % A[i] == 0)
            f[i][i + 1] = 0, from[i][i + 1] = -1;
    }
    for (int len = 3; len <= n; len++) for (int i = 1, j = len; j <= n; i++, j++) {
        f[i][j] = len;
        for (int k = i; k < j; k++) {
            int t = f[i][k] + f[k + 1][j];
            if (t < f[i][j]) f[i][j] = t, from[i][j] = k;
        }
        if (A[i] % A[j] == 0 || A[j] % A[i] == 0) {
            int t = f[i + 1][j - 1];
            if (t < f[i][j]) f[i][j] = t, from[i][j] = -1;
        }
    }

    printf("%d\n", f[1][n]);
    gao(1, n);
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
