#include <bits/stdc++.h>
#define MAGIC (1 << 17)
using namespace std;

int main() {
    int n, X; scanf("%d%d", &n, &X);
    if (n == 1) printf("YES\n%d\n", X);
    else if (n == 2) {
        if (X == 0) printf("NO\n");
        else printf("YES\n0 %d\n", X);
    } else {
        int t = 0;
        for (int i = 1; i < n; i++) t ^= i;
        int g = t ^ X;
        if (g == 0 || g >= n) {
            printf("YES\n");
            for (int i = 1; i < n; i++) printf("%d ", i);
            printf("%d\n", g);
        } else {
            bool flag = true;
            printf("YES\n");
            for (int i = 1; i < n; i++) {
                if (flag && i != g) printf("%d ", i + MAGIC), flag = false;
                else printf("%d ", i);
            }
            printf("%d\n", g + MAGIC);
        }
    }
    return 0;
}
