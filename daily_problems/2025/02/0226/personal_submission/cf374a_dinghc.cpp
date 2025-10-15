#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int INF = 1e9;

int main() {
    int n, m, i, j, a, b;
    scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
    auto f = [&] (int x1, int y1, int x2, int y2) -> int {
        int res = INF;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if ((x2 - x1) % a == 0 && (y2 - y1) % b == 0) {
            int p = (x2 - x1) / a;
            int q = (y2 - y1) / b;
            if ((p & 1) == (q & 1)) {
                if (x1 == x2 && y1 != y2) {
                    if (n - 1 >= a) {
                        res = max(p, q);
                    }
                } else if (x1 != x2 && y1 == y2) {
                    if (m - 1 >= b) {
                        res = max(p, q);
                    }
                } else {
                    res = max(p, q);
                }
            }
        }
        return res;
    };
    int ans = min({f(i, j, 1, 1), f(i, j, 1, m), f(i, j, n, 1), f(i, j, n, m)});
    if (ans < INF) {
        printf("%d\n", ans);
    } else {
        printf("Poor Inna and pony!\n");
    }
    return 0;
}

