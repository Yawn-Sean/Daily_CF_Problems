#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    if (n == 1) { printf("1\n"); return 0; }
    if (n == 2) { printf("1 2\n"); return 0; }
    for (int i = 1, now = 1; i <= n; i *= 2) {
        for (int j = i; j <= n; j += i * 2, now++) {
            if (now == n - 1 && j > i * 2) { printf("%d %d\n", i, j); return 0; }
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
