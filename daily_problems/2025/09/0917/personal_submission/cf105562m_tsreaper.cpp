#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q;
struct Point { long long x, y; } P[MAXN];

__int128 fx[MAXN], fy[MAXN];

long long cross(Point &a, Point &b) {
    return a.x * b.y - b.x * a.y;
}

__int128 sum(__int128 *f, int l, int r) {
    if (l <= r) return f[r] - (l ? f[l - 1] : 0);
    else return f[n - 1] - (l ? f[l - 1] : 0) + f[r];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &P[i].x, &P[i].y);

    fx[0] = P[0].x; fy[0] = P[0].y;
    for (int i = 1; i < n; i++) {
        fx[i] = fx[i - 1] + P[i].x;
        fy[i] = fy[i - 1] + P[i].y;
    }

    __int128 prod = 0, xj = 0, yj = 0, xk = 0, yk = 0;
    for (int j = 1; j + 1 < n; j++) {
        prod += sum(fy, j + 1, n - 1) * P[j].x - sum(fx, j + 1, n - 1) * P[j].y;
        xj += 1LL * (n - 1 - j) * P[j].x;
        yj += 1LL * (n - 1 - j) * P[j].y;
    }
    for (int k = 2; k < n; k++) {
        xk += 1LL * (k - 1) * P[k].x;
        yk += 1LL * (k - 1) * P[k].y;
    }

    __int128 ans = prod + P[0].x * (yj - yk) + P[0].y * (xk - xj);
    for (int i = 1; i < n; i++) {
        prod -= P[i].x * sum(fy, (i + 1) % n, (i - 2 + n) % n);
        prod += P[i].y * sum(fx, (i + 1) % n, (i - 2 + n) % n);
        prod += sum(fx, (i + 1) % n, (i - 2 + n) % n) * P[i - 1].y;
        prod -= sum(fy, (i + 1) % n, (i - 2 + n) % n) * P[i - 1].x;

        xj -= 1LL * (n - 2) * P[i].x;
        yj -= 1LL * (n - 2) * P[i].y;
        xj += sum(fx, (i + 1) % n, (i - 2 + n) % n);
        yj += sum(fy, (i + 1) % n, (i - 2 + n) % n);

        xk -= sum(fx, (i + 1) % n, (i - 2 + n) % n);
        yk -= sum(fy, (i + 1) % n, (i - 2 + n) % n);
        xk += 1LL * (n - 2) * P[i - 1].x;
        yk += 1LL * (n - 2) * P[i - 1].y;

        ans += prod + P[i].x * (yj - yk) + P[i].y * (xk - xj);
    }

    __int128 d = 0;
    for (int i = 0; i < n; i++) d += cross(P[i], P[(i + 1) % n]);
    printf("%.12Lf\n", (long double) ans / 3 / d);
    return 0;
}
