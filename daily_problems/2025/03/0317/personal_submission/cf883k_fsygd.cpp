#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int s[200010], g[200010], l[200010], r[200010], ans[200010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &s[i], &g[i]);
        if (i == 1) {
            l[i] = s[i];
            r[i] = s[i] + g[i];
        }
        else {
            l[i] = max(l[i - 1] - 1, s[i]);
            r[i] = min(r[i - 1] + 1, s[i] + g[i]);
            if (l[i] > r[i]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    ans[n] = r[n];
    long long total = ans[n] - s[n];
    for (int i = n - 1; i >= 1; --i) {
        l[i] = max(l[i], ans[i + 1] - 1);
        r[i] = min(r[i], ans[i + 1] + 1);
        if (l[i] > r[i]) {
            printf("-1\n");
            return 0;
        }
        ans[i] = r[i];
        total = total + ans[i] - s[i];
    }
    printf("%lld\n", total);
    for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}