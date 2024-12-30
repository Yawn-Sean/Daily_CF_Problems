#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, f[MAXN + 10];

int main() {
    scanf("%d", &n);

    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x > mx1) {
            f[x]--;
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            f[mx1]++;
            mx2 = x;
        }
    }

    int ans = 0, best = -1e9;
    for (int i = 1; i <= n; i++) if (f[i] > best) ans = i, best = f[i];
    printf("%d\n", ans);
    return 0;
}
