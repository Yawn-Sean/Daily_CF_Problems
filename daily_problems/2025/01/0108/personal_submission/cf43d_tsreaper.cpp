#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    if (n == 1) {
        if (m == 2) printf("0\n1 1\n1 2\n1 1\n");
        else {
            printf("1\n1 %d 1 1\n", m);
            for (int j = 1; j <= m; j++) printf("1 %d\n", j);
            printf("1 1\n");
        }
    } else if (m == 1) {
        if (n == 2) printf("0\n1 1\n2 1\n1 1\n");
        else {
            printf("1\n%d 1 1 1\n", n);
            for (int i = 1; i <= n; i++) printf("%d 1\n", i);
            printf("1 1\n");
        }
    } else {
        if (n % 2 == 1 && m % 2 == 1) {
            printf("1\n%d %d 1 1\n", n, m);
            for (int i = 1; i <= n; i++) {
                if (i & 1) for (int j = 1; j <= m; j++) printf("%d %d\n", i, j);
                else for (int j = m; j > 0; j--) printf("%d %d\n", i, j);
            }
            printf("1 1\n");
        } else {
            bool swapped = false;
            if (n % 2 == 0) swap(n, m), swapped = true;
            printf("0\n");
            auto print = [&](int i, int j) {
                if (swapped) printf("%d %d\n", j, i);
                else printf("%d %d\n", i, j);
            };
            for (int j = 1; j <= m; j++) print(1, j);
            for (int j = m; j > 0; j--) {
                if (j & 1) for (int i = n; i > 1; i--) print(i, j);
                else for (int i = 2; i <= n; i++) print(i, j);
            }
            printf("1 1\n");
        }
    }
    return 0;
}
