#include <bits/stdc++.h>
#define MAXA ((int) 2e5)
using namespace std;

int n, cnt[MAXA + 10];
long long ans;

int main() {
    scanf("%d", &n);
    
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
        m = max(m, x);
    }

    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= m; i++) if (cnt[i] - cnt[i - 1] > 0) {
        long long sm = 0;
        for (int j = i; j <= m; j += i) {
            int t = cnt[min(m, j + i - 1)] - cnt[j - 1];
            sm += 1LL * t * j;
        }
        ans = max(ans, sm);
    }
    printf("%lld\n", ans);
    return 0;
}
