#include <bits/stdc++.h>
using namespace std;

int X[8], Y[8];

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        X[i] *= 2; Y[i] *= 2;
    }

    int xa = 0, ya = 0;
    for (int i = 0; i < 4; i++) xa += X[i], ya += Y[i];
    xa /= 4; ya /= 4;

    int xb = 0, yb = 0;
    for (int i = 4; i < 8; i++) xb += X[i], yb += Y[i];
    xb /= 4; yb /= 4;

    int lim = abs(X[4] - xb) + abs(Y[4] - yb);
    for (int i = 0; i < 4; i++) {
        int d = abs(X[i] - xb) + abs(Y[i] - yb);
        if (d <= lim) { printf("YES\n"); return 0; }
    }
    int d = abs(xa - xb) + abs(ya - yb);
    if (d <= lim) { printf("YES\n"); return 0; }

    int D = ya - abs(Y[0] - ya), U = ya + abs(Y[0] - ya);
    int L = xa - abs(X[0] - xa), R = xa + abs(X[0] - xa);
    for (int i = 4; i < 8; i++) {
        if (X[i] >= L && X[i] <= R && Y[i] >= D && Y[i] <= U) { printf("YES\n"); return 0; }
    }
    if (xb >= L && xb <= R && yb >= D && yb <= U) { printf("YES\n"); return 0; }

    printf("NO\n"); return 0;
}
