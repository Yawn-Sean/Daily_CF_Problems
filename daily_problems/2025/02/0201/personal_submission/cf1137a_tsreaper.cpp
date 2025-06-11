#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, A[MAXN + 5][MAXN + 5];

int R[MAXN + 5], C[MAXN + 5], f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);

    for (int i = 1; i <= n; i++) {
        map<int, int> mp;
        for (int j = 1; j <= m; j++) mp[A[i][j]] = 1;
        R[i] = mp.size();
        int t = 0;
        for (auto &p : mp) p.second = ++t;
        for (int j = 1; j <= m; j++) f[i][j] = mp[A[i][j]];
    }

    for (int j = 1; j <= m; j++) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) mp[A[i][j]] = 1;
        C[j] = mp.size();
        int t = 0;
        for (auto &p : mp) p.second = ++t;
        for (int i = 1; i <= n; i++) g[i][j] = mp[A[i][j]];
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (f[i][j] > g[i][j]) printf("%d", max(R[i], C[j] - g[i][j] + f[i][j]));
        else printf("%d", max(C[j], R[i] - f[i][j] + g[i][j]));
        printf("%c", "\n "[j < m]);
    }
    return 0;
}
