#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, deg[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        deg[x]++; deg[y]++;
    }
    int leaf = 0;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) leaf++;
    printf("%.9f\n", 2.0 * K / leaf);
}
