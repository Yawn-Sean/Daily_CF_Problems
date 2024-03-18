#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, X[MAXN], Y[MAXN];
double ans;

void gao(int a, int b, int c) {
    double A = Y[c] - Y[b];
    double B = X[b] - X[c];
    double C = 1.0 * X[c] * Y[b] - 1.0 * X[b] * Y[c];
    double d = fabs(A * X[a] + B * Y[a] + C) / sqrt(A * A + B * B);
    ans = min(ans, d / 2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &X[i], &Y[i]);

    ans = 1e300;
    for (int i = 0; i < n; i++) {
        int a = i, b = (i + 1) % n, c = (i + 2) % n;
        gao(a, b, c); gao(b, a, c); gao(c, a, b);
    }
    printf("%.9f\n", ans);
    return 0;
}
