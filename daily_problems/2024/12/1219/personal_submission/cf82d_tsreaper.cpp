#include <bits/stdc++.h>
#define MAXN 1000
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5];

long long f[MAXN + 5][MAXN + 5];
array<int, 4> from[MAXN + 5][MAXN + 5];

void update(int ii, int jj, int i, int j, int x, int y) {
    long long t = f[i][j] + max(A[x], A[y]);
    if (f[ii][jj] > t) {
        f[ii][jj] = t;
        from[ii][jj] = {i, j, x, y};
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int N = n;
    if (n & 1) A[++n] = 0;

    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= n + 1; j++) f[i][j] = INF;
    f[1][1] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; i + j <= n; j++) {
        update(i + j + 1, 1, i, j, i, i + j);
        if (i + j + 1 <= n) {
            update(i + j, 2, i, j, i, i + j + 1);
            update(i, j + 2, i, j, i + j, i + j + 1);
        }
    }

    printf("%lld\n", f[n + 1][1]);
    vector<pii> vec;
    for (int i = n + 1, j = 1; i != 1 || j != 1; ) {
        vec.push_back({from[i][j][2], from[i][j][3]});
        int ii = from[i][j][0], jj = from[i][j][1];
        i = ii; j = jj;
    }
    while (!vec.empty()) {
        pii p = vec.back(); vec.pop_back();
        if (p.first <= N) printf("%d ", p.first);
        if (p.second <= N) printf("%d ", p.second);
        printf("\n");
    }
    return 0;
}
