#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int p = 0;
    while (n > 3) {
        for (int i = 0; i < n - n / 2; i++) {
            printf("%d ", 1 << p);
        }
        n /= 2;
        p++;
    }
    if (n == 3) {
        printf("%d %d %d", 1 << p, 1 << p, 3 << p);
    } else if (n == 2) {
        printf("%d %d", 1 << p, 2 << p);
    } else if (n == 1) {
        printf("%d", 1 << p);
    }
    printf("\n");
    return 0;
}

