#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((int) 1e9)
using namespace std;

int n, q, OP[MAXN + 5][4];
long long ans[MAXN + 5];

long long sm[MAXN + 5];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) ans[i] = INF;

    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < 4; j++) scanf("%d", &OP[i][j]);
        if (OP[i][0] == 1) {
            for (int j = OP[i][1]; j <= OP[i][2]; j++) sm[j] += OP[i][3];
        } else {
            for (int j = OP[i][1]; j <= OP[i][2]; j++) ans[j] = min(ans[j], OP[i][3] - sm[j]);
        }
    }

    for (int i = 1; i <= n; i++) sm[i] = 0;
    for (int i = 1; i <= q; i++) {
        if (OP[i][0] == 1) {
            for (int j = OP[i][1]; j <= OP[i][2]; j++) sm[j] += OP[i][3];
        } else {
            bool fail = true;
            for (int j = OP[i][1]; j <= OP[i][2]; j++) if (ans[j] + sm[j] == OP[i][3]) { fail = false; break; }
            if (fail) { printf("NO\n"); return 0; }
        }
    }
    for (int i = 1; i <= n; i++) if (abs(ans[i]) > INF) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}
