#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, ans, A[MAXN + 10];
char s[MAXN + 10];

int f[MAXN + 10];

void solve() {
    scanf("%d%d%s", &n, &K, s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') A[i] = 0;
        else if (s[i] == 'G') A[i] = 1;
        else A[i] = 2;
    }

    ans = n;
    for (int b = 0; b < 3; b++) {
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (A[i] != (b + i) % 3) f[i]++;
        }
        for (int i = K; i <= n; i++) ans = min(ans, f[i] - f[i - K]);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
