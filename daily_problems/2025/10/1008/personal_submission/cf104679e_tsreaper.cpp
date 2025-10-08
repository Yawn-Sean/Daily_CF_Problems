#include <bits/stdc++.h>
#define MAXN ((int) 1e7)
#define MAXS ((int) 1e4)
using namespace std;

int f[MAXN + 5];

void solve() {
    int n; scanf("%d", &n);
    if (n == 2) printf("0\n");
    else if (n == 3) printf("1\n");
    else printf("%d\n", f[n] - f[n / 2]);
}

int main() {
    for (int i = 2; i <= MAXS; i++) if (!f[i]) for (int j = i * 2; j <= MAXN; j += i) f[j] = 1;
    for (int i = 2; i <= MAXN; i++) f[i] = 1 - f[i] + f[i - 1];

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
