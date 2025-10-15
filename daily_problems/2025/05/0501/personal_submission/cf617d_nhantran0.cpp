/*
 https://codeforces.com/problemset/problem/617/D
 D. Polyline
 Solver: nhant
 2025-05-02 02:28:16
 https://codeforces.com/problemset/submission/617/318030178, 62 ms, 100 KB
*/
#include <bits/stdc++.h>

using namespace std;

bool out(int v, int p1, int p2) {
    return v <= min(p1, p2) || v >= max(p1, p2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int res = 3;
    if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
        res = 1;
    } else if ((x1 == x2 && out(y3, y1, y2)) || (x1 == x3 && out(y2, y1, y3)) || (x2 == x3 && out(y1, y2, y3))
            || (y1 == y2 && out(x3, x1, x2)) || (y1 == y3 && out(x2, x1, x3)) || (y2 == y3 && out(x1, x2, x3))) {
        res = 2;
    }
    cout << res << '\n';
}
