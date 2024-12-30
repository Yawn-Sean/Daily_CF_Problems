#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, a, b, G[MAXN + 10][MAXN + 10];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if ((n == 2 || n == 3) && a == 1 && b == 1) { printf("NO\n"); return 0; } 
    if (a > 1 && b > 1) { printf("NO\n"); return 0; }

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        if (i < max(a, b)) G[i][j] = (b == 1 ? 0 : 1);
        else if (j == i + 1) G[i][j] = (b == 1 ? 1 : 0);
        else if (i > max(a, b) && j == i - 1) G[i][j] = (b == 1 ? 1 : 0);
        else G[i][j] = (b == 1 ? 0 : 1);
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) G[i][j] = G[j][i];

    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d", G[i][j]);
        printf("\n");
    }
    return 0;
}
