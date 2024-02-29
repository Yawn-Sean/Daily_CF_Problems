#include <bits/stdc++.h>
#define MAXN ((int) 1e7)
using namespace std;

int ans[MAXN + 10];
long long f[MAXN + 10];

int main() {
    for (int i = 1; i <= MAXN; i++) for (int j = i; j <= MAXN; j += i) f[j] += i;
    for (int i = 1; i <= MAXN; i++) if (f[i] <= MAXN && ans[f[i]] == 0) ans[f[i]] = i;

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        int n; scanf("%d", &n);
        printf("%d\n", ans[n] ? ans[n] : -1);
    }
    return 0;
}
