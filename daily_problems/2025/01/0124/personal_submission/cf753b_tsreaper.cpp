#include <bits/stdc++.h>
using namespace std;

int ans[4];
bool vis[10];

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) printf("%d", i);
        printf("\n"); fflush(stdout);
        int x, y; scanf("%d%d", &x, &y);
        vis[i] = (x + y > 0);
    }

    int bad = 0;
    for (int i = 0; i < 10; i++) if (!vis[i]) { bad = i; break; }

    for (int i = 0; i < 10; i++) if (vis[i]) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) printf("%d", i);
                else printf("%d", bad);
            }
            printf("\n"); fflush(stdout);
            int x; scanf("%d%*d", &x);
            if (x > 0) { ans[j] = i; break; }
        }
    }

    for (int i = 0; i < 4; i++) printf("%d", ans[i]);
    printf("\n"); fflush(stdout);
    int x, y; scanf("%d%d", &x, &y);
    assert(x == 4);
    return 0;
}
