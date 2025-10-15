#include <bits/stdc++.h>
#define MAXS 32000
#define MAXY 30
using namespace std;

int X, Y, n;
int f[MAXS + 5][MAXY + 1];

int dp(int x, int y) {
    if (y == 1 && 1LL * x * x >= n) return (n - x) & 1 ? -1 : 1;
    long long t = 1;
    for (int i = 1; i <= y; i++) {
        t *= x;
        if (t >= n) return 1;
    }
    int &ret = f[x][y];
    if (ret != 0) return ret;

    if (dp(x + 1, y) == -1) return ret = 1;
    if (dp(x, y + 1) == -1) return ret = 1;
    return ret = -1;
}

int main() {
    scanf("%d%d%d", &X, &Y, &n);
    if (X == 1) {
        for (int i = Y; (1 << i) < n; i++) if (dp(2, i) == -1) {
            if ((i - Y) & 1) printf("Stas\n");
            else printf("Masha\n");
            return 0;
        }
        printf("Missing\n");
    } else {
        if (dp(X, Y) == 1) printf("Masha\n");
        else printf("Stas\n");
    }
    return 0;
}
