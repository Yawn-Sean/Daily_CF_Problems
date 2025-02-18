#include <bits/stdc++.h>
#define MAXN 50
#define MAXD 100
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, m, K, C[MAXN + 5];
long long L[MAXN + 5], R[MAXN + 5];

long long f[MAXN + 5][MAXN + 5][MAXD + 5];
pii from[MAXN + 5][MAXN + 5][MAXD + 5];

void update(int i, int j, int d, int jj, int dd) {
    long long val = f[i - 1][jj][dd] + L[j] + d;
    if (f[i][j][d] < val) {
        f[i][j][d] = val;
        from[i][j][d] = {jj, dd};
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) scanf("%lld%lld%d", &L[i], &R[i], &C[i]);

    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int d = 0; d <= MAXD; d++) f[i][j][d] = -INF;
    for (int j = 1; j <= m; j++) for (int d = 0; d <= R[j] - L[j]; d++) f[1][j][d] = L[j] + d;
    for (int i = 2; i <= n; i++) for (int j = 1; j <= m; j++) for (int d = 0; d <= R[j] - L[j]; d++) {
        long long x = L[j] + d;
        for (int jj = 1; jj <= m; jj++) if (C[jj] < C[j]) {
            if (x % K == 0) {
                long long y = x / K;
                if (L[jj] <= y && y <= R[jj]) update(i, j, d, jj, y - L[jj]);
            }
            long long y = x - K;
            if (L[jj] <= y && y <= R[jj]) update(i, j, d, jj, y - L[jj]);
        }
    }

    pii best = {0, 0};
    for (int j = 1; j <= m; j++) for (int d = 0; d <= R[j] - L[j]; d++)
        if (f[n][j][d] > f[n][best.first][best.second]) best = {j, d};
    if (f[n][best.first][best.second] < 0) { printf("NO\n"); return 0; }
    printf("YES\n");
    vector<array<long long, 2>> vec;
    for (int i = n, j = best.first, d = best.second; i > 0; i--) {
        vec.push_back({j, L[j] + d});
        int jj = from[i][j][d].first, dd = from[i][j][d].second;
        j = jj; d = dd;
    }
    while (!vec.empty()) printf("%lld %lld\n", vec.back()[0], vec.back()[1]), vec.pop_back();
    return 0;
}
