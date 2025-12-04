#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    if (n == 1) { printf("! -1\n"); fflush(stdout); return; }
    
    printf("? %d", n);
    for (int i = 1; i <= n; i++) printf(" %d", i);
    printf(" %d", n);
    for (int i = 1; i <= n; i++) printf(" %d", i);
    printf("\n"); fflush(stdout);
    int m; scanf("%d", &m);

    int tot = 0;
    for (int i = 1; i < n; i++) {
        printf("? %d", n - 1);
        for (int j = 1; j <= n; j++) if (i != j) printf(" %d", j);
        printf(" %d", n - 1);
        for (int j = 1; j <= n; j++) if (i != j) printf(" %d", j);
        printf("\n"); fflush(stdout);
        int x; scanf("%d", &x);
        x = m - x;
        tot += x;
        if (x == 1) { printf("! %d\n", i); fflush(stdout); return; }
    }

    int t = m * 2 - tot;
    if (t == 1) printf("! %d\n", n);
    else printf("! -1\n");
    fflush(stdout);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
