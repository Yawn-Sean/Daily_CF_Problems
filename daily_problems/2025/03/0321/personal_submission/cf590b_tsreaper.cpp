#include <bits/stdc++.h>
using namespace std;
typedef long double db;

int X[4], Y[4], V, T;

bool check(db tim) {
    db x, y;
    if (tim <= T) {
        x = X[1] - X[2] * tim;
        y = Y[1] - Y[2] * tim;
    } else {
        x = X[1] - X[2] * T - X[3] * (tim - T);
        y = Y[1] - Y[2] * T - Y[3] * (tim - T);
    }
    return sqrt((x - X[0]) * (x - X[0]) + (y - Y[0]) * (y - Y[0])) / V <= tim;
}

int main() {
    for (int i = 0; i < 2; i++) scanf("%d%d", &X[i], &Y[i]);
    scanf("%d%d", &V, &T);
    for (int i = 2; i < 4; i++) scanf("%d%d", &X[i], &Y[i]);

    db head, tail;
    if (check(T)) head = 0, tail = T;
    else head = T, tail = 1e9;
    for (int i = 1; i <= 100; i++) {
        db mid = (head + tail) / 2;
        if (check(mid)) tail = mid;
        else head = mid;
    }
    printf("%.12Lf\n", head);
    return 0;
}
