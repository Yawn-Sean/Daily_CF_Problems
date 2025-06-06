#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n, m, satisfied, sum;
int a[200010], b[200010], cnt[200010];
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
        if (b[i] == 0)
            ++satisfied;
        sum += b[i];
    }
    int end = 0;
    while (end + 1 <= n && satisfied < m) {
        ++end;
        if (++cnt[a[end]] == b[a[end]]) ++satisfied;
    }
    if (satisfied < m) {
        printf("-1\n");
        return 0;
    }
    int ans = end - sum;
    for (int start = 2; start <= n; ++start) {
        if (--cnt[a[start - 1]] == b[a[start - 1]] - 1) --satisfied;
        while (end + 1 <= n && satisfied < m) {
            ++end;
            if (++cnt[a[end]] == b[a[end]]) ++satisfied;
        }
        if (satisfied == m) ans = min(ans, end - start + 1 - sum);
    }
    printf("%d\n", ans);
    return 0;
}