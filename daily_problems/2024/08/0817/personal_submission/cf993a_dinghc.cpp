#include <bits/stdc++.h>

using namespace std;

int main() {
    array<pair<int, int>, 4> ps;
    for (int i = 0; i < 4; i++) {
        auto& [x, y] = ps[i];
        scanf("%d%d", &x, &y);
    }
    array<pair<int, int>, 4> qs;
    for (int i = 0; i < 4; i++) {
        auto& [x, y] = qs[i];
        scanf("%d%d", &x, &y);
    }
    auto check_square_contains_points = [] (array<pair<int, int>, 4>& ps, array<pair<int, int>, 4>& qs) {
        auto [x1, y1] = ps[0];
        auto [x2, y2] = ps[2];
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (auto&[x, y] : qs) {
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) return true;
        }
        auto [cx1, cy1] = qs[0];
        auto [cx2, cy2] = qs[2];
        auto [cx3, cy3] = qs[1];
        auto [cx4, cy4] = qs[3];
        int cx = cx1 == cx2 ? cx1 : cx3;
        int cy = cy1 == cy2 ? cy1 : cy3;
        if (cx >= x1 && cx <= x2 && cy >= y1 && cy <= y2) return true;
        return false;
    };
    if (check_square_contains_points(ps, qs)) {
        printf("YES\n");
    } else {
        // rotate around the origin pi/4 in counterclockwise direction
        for (auto&[x, y] : ps) {
            int tmp = x - y;
            y = x + y;
            x = tmp;
        }
        for (auto&[x, y] : qs) {
            int tmp = x - y;
            y = x + y;
            x = tmp;
        }
        if (check_square_contains_points(qs, ps)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

