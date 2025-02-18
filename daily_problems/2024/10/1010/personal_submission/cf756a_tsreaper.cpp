#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, ans, A[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        ans++;
        for (int j = i; !vis[j]; j = A[j]) vis[j] = true;
    }
    if (ans == 1) ans = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        t ^= x;
    }
    ans += 1 - t;
    printf("%d\n", ans);
    return 0;
}
