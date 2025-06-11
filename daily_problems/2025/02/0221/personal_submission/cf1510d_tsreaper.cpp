#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef long double db;

int n, D, A[MAXN + 5];

db f[MAXN + 5][10][2];
array<int, 4> from[MAXN + 5][10][2];

void update(int i, int j, int k, int ii, int jj, int kk, int t) {
    db val = f[ii][jj][kk];
    if (t) val += log(A[i]);
    if (val > f[i][j][k]) {
        f[i][j][k] = val;
        from[i][j][k] = {ii, jj, kk, t};
    }
}

int main() {
    scanf("%d%d", &n, &D);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 0; i <= n; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 2; k++) {
        f[i][j][k] = -1e300;
        from[i][j][k] = {-1, -1, -1, -1};
    }
    f[0][1][0] = 0;
    from[0][1][0] = {0, 0, 0, 0};

    for (int i = 0; i < n; i++) for (int j = 0; j < 10; j++) {
        int nxt = j * A[i + 1] % 10;
        if (from[i][j][0][0] >= 0) {
            update(i + 1, j, 0, i, j, 0, 0);
            update(i + 1, nxt, 1, i, j, 0, 1);
        }
        if (from[i][j][1][0] >= 0) {
            update(i + 1, j, 1, i, j, 1, 0);
            update(i + 1, nxt, 1, i, j, 1, 1);
        }
    }

    if (from[n][D][1][0] >= 0) {
        vector<int> ans;
        for (int i = n, j = D, k = 1; i > 0; ) {
            auto &arr = from[i][j][k];
            if (arr[3] == 1) ans.push_back(A[i]);
            i = arr[0]; j = arr[1]; k = arr[2];
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}
