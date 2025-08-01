#include <bits/stdc++.h>
#define MAXN 50
#define MAXP 30
#define INF ((long long) 1e18)
using namespace std;

int n, m;
long long ans;

long long mx[MAXN + 5], mn[MAXN + 5], sm[MAXN + 5], val[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        mx[i] = -INF; mn[i] = INF; val[i] = -INF;
        int K; scanf("%d", &K);
        long long now = 0;
        for (int j = 1; j <= K; j++) {
            int x; scanf("%d", &x);
            sm[i] += x;
            mx[i] = max(mx[i], sm[i]);
            mn[i] = min(mn[i], sm[i]);
            now += x;
            val[i] = max(val[i], now);
            if (now < 0) now = 0;
        }
    }

    ans = -INF;
    long long now = 0, best = 0;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        ans = max(ans, val[x]);
        ans = max(ans, mx[x] + now - best);
        best = min(best, now + mn[x]);
        now += sm[x];
    }
    printf("%lld\n", ans);
    return 0;
}
