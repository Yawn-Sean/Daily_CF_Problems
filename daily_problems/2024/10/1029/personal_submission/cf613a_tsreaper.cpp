#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, OX, OY, X[MAXN], Y[MAXN];

double dis(int xa, int ya, int xb, int yb) {
    return sqrt(1LL * (xa - xb) * (xa - xb) + 1LL * (ya - yb) * (ya - yb));
}

double dis(int x, int y) {
    return dis(OX, OY, x, y);
}

double calc(int xa, int ya, int xb, int yb) {
    double da = dis(xa, ya), db = dis(xb, yb);
    double ab = dis(xa, ya, xb, yb);
    double dc = (1LL * (OX - xa) * (xb - xa) + 1LL * (OY - ya) * (yb - ya)) / ab;
    if (dc < 0) return da;
    else if (dc > ab) return db;
    else return sqrt(da * da - dc * dc);
}

int main() {
    scanf("%d%d%d", &n, &OX, &OY);
    
    double mx = -1e300;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        mx = max(mx, dis(X[i], Y[i]));
    }

    double mn = 1e300;
    for (int i = 0; i < n; i++) mn = min(mn, calc(X[i], Y[i], X[(i + 1) % n], Y[(i + 1) % n]));

    printf("%.12f\n", acos(-1) * (mx * mx - mn * mn));
    return 0;
}
