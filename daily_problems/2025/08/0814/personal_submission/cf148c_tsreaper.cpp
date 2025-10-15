#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);

    if (n == 1) printf("1");
    else if (b > 0) {
        int now = 1;
        printf("1");
        for (int i = 1; i <= b; i++) {
            now *= 2;
            printf(" %d", now);
        }
        for (int i = 1; i <= a; i++) {
            now++;
            printf(" %d", now);
        }
        for (int i = a + b + 2; i <= n; i++) printf(" %d", now);
    } else if (a == n - 1) printf("-1");
    else {
        int now = 2;
        printf("2 2");
        for (int i = 1; i <= a; i++) {
            now++;
            printf(" %d", now);
        }
        for (int i = a + 3; i <= n; i++) printf(" %d", now);
    }

    printf("\n");
    return 0;
}
