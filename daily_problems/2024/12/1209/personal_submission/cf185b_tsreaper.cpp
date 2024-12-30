#include <bits/stdc++.h>
#define TRIES 300
using namespace std;
typedef long double db;
typedef pair<db, db> pdd;

int s, a, b, c;

db calc(db x, db y) {
    db z = s - x - y;
    return (a > 0 ? a * log(x) : 0) + (b > 0 ? b * log(y) : 0) + (c > 0 ? c * log(z) : 0);
}

pdd calc(db x) {
    db head = 0, tail = s - x;
    for (int i = 0; i < TRIES; i++) {
        db mid1 = head + (tail - head) / 3;
        db mid2 = head + (tail - head) / 3 * 2;
        if (calc(x, mid1) < calc(x, mid2)) head = mid1;
        else tail = mid2;
    }
    db y = (head + tail) / 2;
    return {calc(x, y), y};
}

int main() {
    scanf("%d%d%d%d", &s, &a, &b, &c);
    db head = 0, tail = s;
    for (int i = 0; i < TRIES; i++) {
        db mid1 = head + (tail - head) / 3;
        db mid2 = head + (tail - head) / 3 * 2;
        if (calc(mid1).first < calc(mid2).first) head = mid1;
        else tail = mid2;
    }

    db x = (head + tail) / 2, y = calc(x).second, z = s - x - y;
    printf("%.12Lf %.12Lf %.12Lf\n", x, y, z);
    return 0;
}
