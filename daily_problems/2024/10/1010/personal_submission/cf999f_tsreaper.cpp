#include <bits/stdc++.h>
#define MAXN 500
#define MAXK 10
#define INF ((long long) 1e18)
using namespace std;

int n, K, A[MAXK + 5];
long long ans;
unordered_map<int, int> mp1, mp2;

long long f[MAXN + 5][MAXN * MAXK + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n * K; i++) {
        int x; scanf("%d", &x);
        mp1[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mp2[x]++;
    }
    for (int i = 1; i <= K; i++) scanf("%d", &A[i]);

    for (int i = 0; i <= n; i++) for (int j = 0; j <= n * K; j++) f[i][j] = -INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= i * K; j++) for (int k = 0; k <= K && k <= j; k++)
        f[i][j] = max(f[i][j], f[i - 1][j - k] + A[k]);

    for (auto &p : mp1) {
        if (mp2.count(p.first) == 0) continue;
        int t = mp2[p.first];
        ans += f[t][min(t * K, p.second)];
    }
    printf("%lld\n", ans);
    return 0;
}
