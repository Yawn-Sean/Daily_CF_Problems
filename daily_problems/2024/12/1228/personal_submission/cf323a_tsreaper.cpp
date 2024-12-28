#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
char ans[MAXN + 5][MAXN + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    if (n & 1) { printf("-1\n"); return 0; }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int d = min({i, j, n + 1 - i, n + 1 - j});
                if ((d & 1) ^ (k & 1)) printf("b");
                else printf("w");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
