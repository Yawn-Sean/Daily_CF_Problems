#include <bits/stdc++.h>
#define MAXN 1000
#define MAXA 8
#define INF ((int) 1e9)
using namespace std;

int n, ans, A[MAXN + 5];

int f[1 << MAXA], g[MAXN + 5][MAXN / MAXA + 5][MAXA + 1];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int j = 1; j <= n / MAXA + 1; j++) for (int k = 1; k <= MAXA; k++) g[n + 1][j][k] = n + 1;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n / MAXA + 1; j++) for (int k = 1; k <= MAXA; k++) g[i][j][k] = g[i + 1][j][k];
        g[i][1][A[i]] = i;
        for (int j = 2; j <= n / MAXA + 1; j++) g[i][j][A[i]] = g[i + 1][j - 1][A[i]];
    }

    for (int mn = 0; mn <= n / MAXA; mn++) for (int msk = 0; msk < (1 << MAXA); msk++) {
        vector<int> vec;
        int tot = 0;
        for (int i = 0; i < MAXA; i++) {
            vec.push_back(mn); tot += mn;
            if (msk >> i & 1) vec[vec.size() - 1] += 1, tot += 1;
        }
        
        for (int i = 0; i < (1 << MAXA); i++) f[i] = INF;
        f[0] = 0;
        for (int i = 1; i < (1 << MAXA); i++) {
            for (int j = 0; j < MAXA; j++) if (i >> j & 1) {
                int ii = i ^ (1 << j);
                if (vec[j] == 0) f[i] = min(f[i], f[ii]);
                else if (f[ii] <= n) f[i] = min(f[i], g[f[ii] + 1][vec[j]][j + 1]);
            }
        }
        if (f[(1 << MAXA) - 1] <= n) ans = max(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
