#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 2e9)
using namespace std;

int n, ans, A[MAXN + 5][2], f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int j = 0; j < 2; j++) for (int i = 1; i <= n; i++) scanf("%d", &A[i][j]);

    for (int i = 1; i <= n; i++) f[i] = INF;
    for (int i = 1; i <= n; i++) {
        int g[2];
        for (int j = 0; j < 2; j++) {
            int head = 1, tail = i;
            while (head < tail) {
                int mid = (head + tail) >> 1;
                if (f[mid] >= A[i][j]) tail = mid;
                else head = mid + 1;
            }
            ans = max(ans, head);
            g[j] = head;
        }
        for (int j = 0; j < 2; j++) f[g[j]] = min(f[g[j]], A[i][j]);
    }
    printf("%d\n", ans);
    return 0;
}
