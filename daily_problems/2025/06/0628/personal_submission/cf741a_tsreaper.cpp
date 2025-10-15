#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, A[MAXN + 5];
long long ans;

bool vis[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (vis[A[i]]) { printf("-1\n"); return 0; }
        vis[A[i]] = true;
    }
    
    ans = 1;
    memset(vis, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int cnt = 0;
        for (int j = i; !vis[j]; j = A[j]) vis[j] = true, cnt++;
        if (cnt % 2 == 0) cnt /= 2;
        ans = ans / gcd(ans, cnt) * cnt;
    }
    printf("%lld\n", ans);
    return 0;
}
