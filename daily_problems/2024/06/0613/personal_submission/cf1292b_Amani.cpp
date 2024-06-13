#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    vector<pair<int, int>> points;
    // 起点最大为1e16，t最大为1e16，就算一直向右/上走，最大也只能到2e16，因为计算出的坐标都是正数，所以不用考虑负数情况
    while (x0 < 2e16+10 && y0 < 2e16+10) {
        points.emplace_back(x0, y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int xs, ys, t;
    cin >> xs >> ys >> t;
    int ans = 0, n = points.size();
    for (int i = 0; i < n; ++i) {  // 枚举起点
        for (int j = 0; j < n; ++j) {  // 枚举终点
            int time_start = abs(points[i].first - xs) + abs(points[i].second - ys);  // 出生点到路径起点的距离
            int time = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
            if (time_start + time <= t) {  // 可以走完整个路径
                ans = max(ans, abs(j - i) + 1);  // 计算点的数量
                // 在points数组中，前一个坐标的 x,y 都比后一个坐标的 x,y 小
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout << solve();
    return 0;
}