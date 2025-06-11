#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z, x1, y1, z1;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
    int a1, a2, a3, a4, a5, a6;
    scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);
    // x: a5<===>a6
    // y: a1<===>a2
    // z: a3<===>a4
    int ans = 0;
    if (x > x1) ans += a6;
    else if (x < 0) ans += a5;
    if (y > y1) ans += a2;
    else if (y < 0) ans += a1;
    if (z > z1) ans += a4;
    else if (z < 0) ans += a3;
    printf("%d\n", ans);
    return 0;
}

