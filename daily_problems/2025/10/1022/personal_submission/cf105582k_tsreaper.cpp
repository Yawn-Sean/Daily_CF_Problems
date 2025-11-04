#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    
    if (n == 3) {
        printf("0 0\n4 3\n-20 21\n");
        return 0;
    } else if (n == 5) {
        printf("0 18\n20 -3\n24 0\n0 -32\n-24 0\n");
        return 0;
    }

    int t = (n - 4) / 2;
    int x = 0, y = 18 * 30;
    printf("%d %d\n", x, y);
    for (int i = 1; i <= t; i++) {
        x += 20;
        y -= 21;
        printf("%d %d\n", x, y);
        x += 4;
        y += 3;
        printf("%d %d\n", x, y);
    }
    printf("%d %d\n", 24 * 30, 0);
    printf("%d %d\n", 0, -18 * 30);
    printf("%d %d\n", -24 * 30, 0);
    if (n & 1) printf("%d %d\n", -4 * 30, 21 * 30);
    return 0;
}
