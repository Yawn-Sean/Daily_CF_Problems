#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18, mod = 998244353, N = 150;
ll x, y, ax, ay, bx, by, sx, sy, t;

void solve(){

    cin >> x >> y >> ax >> ay >> bx >> by >> sx >> sy >> t;

    // 先预处理从每个点出发到其他更多的点所需要的最小距离, 注意这里走的时候要选连续的一段
    // 再枚举从哪个点出发
    auto gain = [&](ll x1, ll x2, ll y1, ll y2)->ll{
        return abs(x1-x2) + abs(y1-y2);
    };

    vector <array<ll,2>> dot(1);
    dot.push_back({x, y});
    {
        int j = 1;
        ll px, py;
        while ((px=ax*dot[j][0]+bx)-sx + (py=ay*dot[j][1]+by) - sy <= t) dot.push_back({px, py}), ++ j;
        // 保证sx,sy在右上角时，左下角可以被选完
    }

    int n = dot.size()-1;
    int res = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = i; k <= n; ++k) {
                ll mins = min(gain(dot[i][0], dot[j][0], dot[i][1], dot[j][1]), gain(dot[i][0], dot[k][0], dot[i][1], dot[k][1]));
                if (mins > t) continue;
                if (gain(sx, dot[i][0], sy, dot[i][1]) + gain(dot[j][0], dot[k][0], dot[j][1], dot[k][1]) + mins <= t)
                    res = max(res, k - j + 1);
            }
        }
    }

    cout << res << "\n";
}
