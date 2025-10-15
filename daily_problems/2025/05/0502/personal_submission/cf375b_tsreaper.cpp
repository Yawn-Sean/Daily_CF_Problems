#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int n, m, ans;
char MAP[MAXN + 5][MAXN + 5];

int f[MAXN + 5], cnt[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i <= m; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (MAP[i][j] == '0') f[i] = 0;
            else f[i]++;
            cnt[f[i]]++;
        }
        for (int i = m, sm = 0; i > 0; i--) {
            sm += cnt[i];
            ans = max(ans, sm * i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
