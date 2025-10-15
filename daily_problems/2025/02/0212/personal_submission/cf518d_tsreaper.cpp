#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<int, int> pii;

int n, K;
double P;

double f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%lf%d", &n, &P, &K);
    for (int i = K - 1; i >= 0; i--) {
        f[i][0] = f[i + 1][0];
        for (int j = 1; j <= n; j++) f[i][j] += (f[i + 1][j - 1] + 1) * P + f[i + 1][j] * (1 - P);
    }
    printf("%.12f\n", f[0][n]);
    return 0;
}
