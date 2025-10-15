#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, ans, A[MAXN + 5], B[MAXN + 5];
int f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        B[x] = i;
    }
    for (int i = 1; i <= n; i++) A[i] = B[A[i]];

    f[0] = n + 1;
    for (int i = 1; i <= n; i++) {
        int head = 0, tail = i - 1;
        while (head < tail) {
            int mid = (head + tail + 1) >> 1;
            if (f[mid] >= A[i]) head = mid;
            else tail = mid - 1;
        }
        ans = max(ans, head + 1);
        f[head + 1] = A[i];
    }
    printf("%d\n", ans);
    return 0;
}
