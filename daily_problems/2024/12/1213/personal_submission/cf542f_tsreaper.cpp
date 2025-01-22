#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 100
#define INF ((int) 1e9)
using namespace std;

int n, K, ans;
vector<int> A[MAXK + 5];

int f[2][MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        A[x].push_back(y);
    }

    for (int i = 0; i <= n; i++) f[1][i] = -INF;
    f[1][1] = 0;
    for (int k = 1; k <= K; k++) {
        if (k > 1) {
            for (int i = 0; i <= n; i++) f[k & 1][i] = -INF;
            for (int i = 0; i <= n; i++) {
                int ii = min(n, i * 2);
                f[k & 1][ii] = max(f[k & 1][ii], f[k & 1 ^ 1][i]);
            }
        }
        for (int v : A[K + 1 - k]) for (int i = 0; i < n; i++)
            f[k & 1][i] = max(f[k & 1][i], f[k & 1][i + 1] + v);
    }

    int ans = -INF;
    for (int i = 0; i <= n; i++) ans = max(ans, f[K & 1][i]);
    printf("%d\n", ans);
    return 0;
}
