#include <bits/stdc++.h>
#define MAXN 26
#define MAXA 50
using namespace std;

int a, b, c, d, n;
char MAP[MAXA + 5][MAXA * 2 + 5];

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    for (int i = 1; i <= b || i <= d; i++) for (int j = 1; j <= a + c; j++) MAP[i][j] = '.';

    int i, j, k;
    if (a & 1) {
        i = b; j = 1; k = -1;
    } else {
        i = 1; j = 1; k = 1;
    }

    for (int t = 1; t <= n; t++) {
        int x; scanf("%d", &x);
        while (x--) {
            MAP[i][j] = t - 1 + 'a';
            i += k;
            if (i == 0) i = 1, j++, k = 1;
            if (j <= a && i > b) i = b, j++, k = -1;
            if (j > a && i > d) i = d, j++, k = -1;
        }
    }

    printf("YES\n");
    for (int i = 1; i <= b || i <= d; i++) printf("%s\n", MAP[i] + 1);
    return 0;
}
