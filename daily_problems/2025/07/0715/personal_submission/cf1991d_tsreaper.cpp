#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, col[MAXN + 10] = {0, 1, 3, 2, 3, 1, 4};

void solve() {
    scanf("%d", &n);
    if (n <= 6) {
        printf("%d\n", n / 2 + 1);
        for (int i = 1; i <= n; i++) printf("%d%c", i / 2 + 1, "\n "[i < n]);
    } else {
        printf("4\n");
        for (int i = 1; i <= n; i++) printf("%d%c", col[i], "\n "[i < n]);
    }
}

int main() {
    for (int i = 5; i <= MAXN; i++) {
        if (i % 4 == 1) col[i] = 1;
        else if (i % 4 == 2) col[i] = 4;
        else if (i % 4 == 3) col[i] = 2;
        else col[i] = 3;
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}