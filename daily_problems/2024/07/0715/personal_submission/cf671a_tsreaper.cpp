#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF 1e300
using namespace std;

int n, XA, YA, XB, YB, XT, YT, X[MAXN + 10], Y[MAXN + 10];

double dis(int xa, int ya, int xb, int yb) {
    return sqrt(1.0 * (xa - xb) * (xa - xb) + 1.0 * (ya - yb) * (ya - yb));
}

void update(double &a, double b) { a = min(a, b); }

int main() {
    scanf("%d%d%d%d%d%d%d", &XA, &YA, &XB, &YB, &XT, &YT, &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    double f[2][4];
    for (int j = 0; j < 4; j++) f[0][j] = INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) f[i & 1][j] = INF;
        for (int j = 0; j < 4; j++) {
            double da = dis(XA, YA, X[i], Y[i]);
            double db = dis(XB, YB, X[i], Y[i]);
            double dt = dis(XT, YT, X[i], Y[i]);
            update(f[i & 1][j], f[i & 1 ^ 1][j] + 2 * dt);
            if ((j & 1) == 0) update(f[i & 1][j | 1], f[i & 1 ^ 1][j] + dt + da);
            if ((j & 2) == 0) update(f[i & 1][j | 2], f[i & 1 ^ 1][j] + dt + db);
        }
    }

    double ans = INF;
    for (int j = 1; j < 4; j++) ans = min(ans, f[n & 1][j]);
    printf("%.12f\n", ans);
    return 0;
}
