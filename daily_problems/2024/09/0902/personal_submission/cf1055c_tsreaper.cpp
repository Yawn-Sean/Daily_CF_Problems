#include <bits/stdc++.h>
using namespace std;

int ceil(int a, int b) {
    if (a < 0) return a / b;
    else return (a + b - 1) / b;
}

int main() {
    int la, ra, ta; scanf("%d%d%d", &la, &ra, &ta);
    int lb, rb, tb; scanf("%d%d%d", &lb, &rb, &tb);
    int g = gcd(ta, tb);
    int ans = 0;

    int w = la % tb;
    int x = ceil(lb - w, g) * g + w;
    ans = max(ans, min(ra - la + 1, rb - x + 1));

    w = lb % ta;
    x = ceil(la - w, g) * g + w;
    ans = max(ans, min(rb - lb + 1, ra - x + 1));

    printf("%d\n", ans);
    return 0;
}
