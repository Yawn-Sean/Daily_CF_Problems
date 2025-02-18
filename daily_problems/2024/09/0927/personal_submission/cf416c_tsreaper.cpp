#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 1000
#define INF ((long long) 1e18)
using namespace std;

int n, m;
array<int, 3> A[MAXN + 10];
array<int, 2> B[MAXM + 10];

long long f[MAXN + 10][MAXM + 10];
array<int, 2> from[MAXN + 10][MAXM + 10];

void update(int i, int j, int ii, int jj, int det) {
    long long t = f[ii][jj] + det;
    if (f[i][j] >= t) return;
    f[i][j] = t;
    from[i][j] = {ii, jj};
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][0], &A[i][1]), A[i][2] = i;
    sort(A + 1, A + n + 1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i][0]), B[i][1] = i;
    sort(B + 1, B + m + 1);

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) f[i][j] = -INF;
    f[0][0] = 0;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
        if (i < n) update(i + 1, j, i, j, 0);
        if (j < m) update(i, j + 1, i, j, 0);
        if (i < n && j < m && A[i + 1][0] <= B[j + 1][0]) update(i + 1, j + 1, i, j, A[i + 1][1]);
    }

    vector<array<int, 2>> vec;
    for (int i = n, j = m; i + j > 0; ) {
        int ii = from[i][j][0], jj = from[i][j][1];
        if (ii == i - 1 && jj == j - 1) vec.push_back({A[i][2], B[j][1]});
        i = ii; j = jj;
    }
    printf("%d %lld\n", vec.size(), f[n][m]);
    for (auto &arr : vec) printf("%d %d\n", arr[0], arr[1]);
    return 0;
}
