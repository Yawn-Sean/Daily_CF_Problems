#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, X, Y;

int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 0; X * i <= n; i++) if ((n - X * i) % Y == 0) {
        int now = 1;
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < X; k++) printf("%d ", now + k);
            printf("%d ", now);
            now += X;
        }
        int t = (n - X * i) / Y;
        for (int j = 1; j <= t; j++) {
            for (int k = 1; k < Y; k++) printf("%d ", now + k);
            printf("%d ", now);
            now += Y;
        }
        printf("\n");
        return 0;
    }
    printf("-1\n");
    return 0;
}
