#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;
 
int n, K;
char s1[MAXN + 10], s2[MAXN + 10];
long long ans;
 
int main() {
    scanf("%d%d%s%s", &n, &K, s1 + 1, s2 + 1);
    long long now = 0;
    for (int i = 1; i <= n; i++) {
        now *= 2;
        now += s2[i] - s1[i];
        now = min(now, 1LL * K);
        ans += min(now + 1, 1LL * K);
    }
    printf("%lld\n", ans);
    return 0;
}
