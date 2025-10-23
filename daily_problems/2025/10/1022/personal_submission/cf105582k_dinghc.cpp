#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> points;
    points.emplace_back(0, 0);
    int x = 0, y = 25;
    for (int i = 0; i < n / 2 - 1; i++) {
        points.emplace_back(x, y);
        x += 25;
        points.emplace_back(x, y);
        y += 25;
    }
    x = max(x, 25);
    points.emplace_back(x, 0);
    if (n & 1) {
        points.emplace_back(x / 25 * 9, -x / 25 * 12);
    }
    int dx = 5, dy = 12;
    for (auto [x, y] : points) {
        printf("%d %d\n", x * dx + y * dy, -x * dy + y * dx);
    }
    return 0;
}
