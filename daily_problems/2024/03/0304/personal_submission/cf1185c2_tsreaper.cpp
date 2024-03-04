#include <bits/stdc++.h>
#define MAXT 100
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int cnt[MAXT + 10] = {0};
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        sm += x;
        int now = sm, ans = 0;
        for (int t = MAXT; t > 0; t--) {
            if (now - cnt[t] * t <= m) {
                ans += max(0, (now - m + t - 1) / t);
                break;
            }
            now -= cnt[t] * t;
            ans += cnt[t];
        }
        cnt[x]++;
        printf("%d%c", ans, "\n "[i < n]);
    }
    return 0;
}
