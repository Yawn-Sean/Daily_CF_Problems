#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((int) 1e9)
using namespace std;

int n, ans;
char s[MAXN + 5];

int f[MAXN + 5][3][2];
 
int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++) f[i][j][k] = -INF;
    f[1][0][s[1] - '0'] = f[1][1][(s[1] - '0') ^ 1] = 1;
    for (int i = 2; i <= n; i++) {
        int x = s[i] - '0';
        f[i][0][x] = f[i - 1][0][x ^ 1] + 1;
        f[i][1][x ^ 1] = max(f[i - 1][0][x], f[i - 1][1][x]) + 1;
        f[i][2][x] = max(f[i - 1][1][x ^ 1], f[i - 1][2][x ^ 1]) + 1;
        for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
    }
    for (int j = 1; j < 3; j++) for (int k = 0; k < 2; k++) ans = max(ans, f[n][j][k]);
    printf("%d\n", ans);
    return 0;
}
