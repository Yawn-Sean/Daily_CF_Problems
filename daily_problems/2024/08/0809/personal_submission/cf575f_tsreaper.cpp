#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((long long) 1e18)
using namespace std;

int n, m, L[MAXN + 10], R[MAXN + 10];
long long ans;

long long f[2][MAXN * 2 + 10], g[2][MAXN * 2 + 10], h[2][MAXN * 2 + 10];

int main() {
    int X; scanf("%d%d", &n, &X);

    vector<int> vec = {X};
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &L[i], &R[i]);
        vec.push_back(L[i]); vec.push_back(R[i]);
    }
    sort(vec.begin(), vec.end());
    m = unique(vec.begin(), vec.end()) - vec.begin();
    vec.resize(m);

    for (int i = 1; i <= m; i++) {
        f[0][i] = INF;
        if (vec[i - 1] == X) f[0][i] = 0;        
    }
    g[0][0] = INF;
    for (int i = 1; i <= m; i++) g[0][i] = min(g[0][i - 1], f[0][i] - vec[i - 1]);
    h[0][m + 1] = INF;
    for (int i = m; i > 0; i--) h[0][i] = min(h[0][i + 1], f[0][i] + vec[i - 1]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d = 0;
            if (vec[j - 1] < L[i]) d = L[i] - vec[j - 1];
            if (vec[j - 1] > R[i]) d = vec[j - 1] - R[i];
            f[i & 1][j] = min(g[i & 1 ^ 1][j] + vec[j - 1], h[i & 1 ^ 1][j] - vec[j - 1]) + d;
        }
        g[i & 1][0] = INF;
        for (int j = 1; j <= m; j++) g[i & 1][j] = min(g[i & 1][j - 1], f[i & 1][j] - vec[j - 1]);
        h[i & 1][m + 1] = INF;
        for (int j = m; j > 0; j--) h[i & 1][j] = min(h[i & 1][j + 1], f[i & 1][j] + vec[j - 1]);
    }

    ans = INF;
    for (int j = 1; j <= m; j++) ans = min(ans, f[n & 1][j]);
    printf("%lld\n", ans);
    return 0;
}
