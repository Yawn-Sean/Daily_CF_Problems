#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];

void solve() {
    scanf("%*d%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    A[n + 1] = 0;

    int ans = 0;
    int now = A[1], i = 1;
    while (now > 2) {
        while (A[i] >= now) i++;
        if (A[i] == now - 1) {
            if (A[i + 1] != now - 2) ans++;
            now -= 2;
        } else {
            now = A[i] + 1;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
