#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MAXP 10
using namespace std;

int n, A[MAXN + 10];
char OP[MAXN + 10][5];

bool flag[MAXP];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s%d", OP[i], &A[i]);

    for (int p = 0; p < MAXP; p++) flag[p] = true;
    int zero = (1 << MAXP) - 1, one = 0, x = 0;
    for (int i = n; i > 0; i--) {
        if (OP[i][0] == '^') x ^= A[i];
        else if (OP[i][0] == '&') {
            for (int p = 0; p < MAXP; p++) if (flag[p]) if (A[i] >> p & 1 ^ 1) {
                int t = x >> p & 1;
                if (t) one ^= 1 << p;
                else zero ^= 1 << p;
                flag[p] = false;
            }
        } else {
            for (int p = 0; p < MAXP; p++) if (flag[p]) if (A[i] >> p & 1) {
                int t = x >> p & 1 ^ 1;
                if (t) one ^= 1 << p;
                else zero ^= 1 << p;
                flag[p] = false;
            }
        }
    }

    printf("3\n^ %d\n& %d\n| %d", x, zero, one);
    return 0;
}
