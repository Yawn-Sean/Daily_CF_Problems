#include <bits/stdc++.h>
#define MAXN ((int) 1e4)
#define EPS (1e-12)
using namespace std;
typedef long double db;

int n, VS, VP;
long long X[MAXN + 5], Y[MAXN + 5], Z[MAXN + 5];

db dis(int a, int b) {
    return sqrt(
        (X[a] - X[b]) * (X[a] - X[b]) +
        (Y[a] - Y[b]) * (Y[a] - Y[b]) +
        (Z[a] - Z[b]) * (Z[a] - Z[b])
    );
}

array<db, 4> tryy(int a, int b, db k, db tim) {
    db x = X[a] + k * (X[b] - X[a]);
    db y = Y[a] + k * (Y[b] - Y[a]);
    db z = Z[a] + k * (Z[b] - Z[a]);
    db d2 = (x - X[n + 1]) * (x - X[n + 1]) + (y - Y[n + 1]) * (y - Y[n + 1]) + (z - Z[n + 1]) * (z - Z[n + 1]);
    if (sqrt(d2) / VP < tim + EPS) return {1, x, y, z};
    else return {-1, 0, 0, 0};
}

array<db, 4> check(db lim) {
    db tot = 0;
    for (int i = 1; i <= n; i++) {
        db len = dis(i - 1, i);
        if (tot + len + EPS >= lim) return tryy(i - 1, i, (lim - tot) / len, lim / VS);
        tot += len;
    }
    return {-1, 0, 0, 0};
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);
    scanf("%d%d%lld%lld%lld", &VP, &VS, &X[n + 1], &Y[n + 1], &Z[n + 1]);

    db tot = 0;
    for (int i = 1; i <= n; i++) tot += dis(i - 1, i);
    if (check(tot)[0] < 0) { printf("NO\n"); return 0; }

    db head = 0, tail = tot / VS;
    for (int i = 0; i <= 100; i++) {
        db mid = (head + tail) / 2;
        if (check(mid * VS)[0] > 0) tail = mid;
        else head = mid;
    }
    printf("YES\n%.12Lf\n", tail);
    auto pos = check(tail * VS);
    printf("%.12Lf %.12Lf %.12Lf\n", pos[1], pos[2], pos[3]);
    return 0;
}
