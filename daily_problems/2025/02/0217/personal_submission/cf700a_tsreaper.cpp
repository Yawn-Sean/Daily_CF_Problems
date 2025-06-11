#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L, v1, v2, K; scanf("%d%d%d%d%d", &n, &L, &v1, &v2, &K);
    long double w = (n + K - 1) / K;
    long double t = (w - 1) * 2 * v1 / (v1 + v2) + 1;
    long double d = L / t;
    long double ans = d / v2 + (L - d) / v1;
    printf("%.12Lf\n", ans);
    return 0;
}
