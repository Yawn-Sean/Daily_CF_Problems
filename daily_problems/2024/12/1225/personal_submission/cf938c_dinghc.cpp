#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            printf("1 1\n");
            continue;
        }
        int n = 0, m = 0;
        for (int p = 1; 1LL * p * p < x; p++) {
            if (x % p == 0 && (p + x / p) % 2 == 0 && x / p - p > 1) {
                int a = (p + x / p) / 2;
                int b = a / ((x / p - p) / 2);
                if (a / b == (x / p - p) / 2) {
                    n = a, m = b;
                    break;
                }
            }
        }
        if (n > 0) {
            printf("%d %d\n", n, m);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}

