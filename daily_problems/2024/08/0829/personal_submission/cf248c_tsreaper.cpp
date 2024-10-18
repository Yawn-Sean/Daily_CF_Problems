#include <bits/stdc++.h>
#define EPS 1e-12
#define TRIES 200
using namespace std;
typedef long double ldb;

int D, U, W, XB, YB, R;

ldb calc(ldb M) {
    ldb k = (W - R - YB) / (XB - M);
    return W - R - M * k;
}

bool check(ldb M) {
    ldb Y = calc(M);
    if (Y > U - R - EPS) return false;
    ldb A = W - R - Y, B = -M, C = M * Y;
    return abs(B * U + C) / sqrt(A * A + B * B) > R + EPS;
}

int main() {
    scanf("%d%d%d%d%d%d", &D, &U, &W, &XB, &YB, &R);
    ldb head = 0, tail = XB;
    for (int t = 1; t <= TRIES; t++) {
        ldb mid = (head + tail) / 2;
        if (calc(mid) > D + R + EPS) head = mid;
        else tail = mid;
    }
    ldb ans = (head + tail) / 2;
    if (check(ans)) printf("%.12Lf\n", ans);
    else printf("-1\n");
    return 0;
}
