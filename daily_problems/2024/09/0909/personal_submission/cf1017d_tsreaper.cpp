#include <bits/stdc++.h>
#define MAXN 12
#define MAXK 100
using namespace std;

int n, m, q, W[MAXN];
int cnt[1 << MAXN], f[1 << MAXN][MAXK + 1];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) scanf("%d", &W[i]);
    for (int i = 1; i <= m; i++) {
        char s[MAXN + 5]; scanf("%s", s);
        int x = 0;
        for (int i = 0; i < n; i++) x = x * 2 + s[i] - '0';
        cnt[x]++;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) if (cnt[j] > 0) {
            int v = 0;
            for (int k = 0; k < n; k++) if ((i >> k & 1) == (j >> k & 1)) v += W[n - 1 - k];
            if (v <= MAXK) f[i][v] += cnt[j];
        }
        for (int k = 1; k <= MAXK; k++) f[i][k] += f[i][k - 1];
    }

    while (q--) {
        char s[MAXN + 5]; scanf("%s", s);
        int x = 0;
        for (int i = 0; i < n; i++) x = x * 2 + s[i] - '0';
        int k; scanf("%d", &k);
        printf("%d\n", f[x][k]);
    }
    return 0;
}
