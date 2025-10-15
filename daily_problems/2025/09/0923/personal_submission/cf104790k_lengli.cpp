#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    long long cur_max = LLONG_MIN;

    // 64-bit 打包 (x,y) 作为 key，常数更小
    unordered_map<long long, int> saved;
    saved.reserve(1 << 20);
    saved.max_load_factor(0.7f);
    auto pack = [&](int x, int y)->long long {
        return ( (long long)x << 32 ) ^ (unsigned long long)y;
    };

    auto query = [&](int x, int y)->int {
        // 你的“幽灵边界”为 0 的策略保留
        if (x == 0 || x == n + 1) return 0;
        if (y == 0 || y == n + 1) return 0;

        long long k = pack(x, y);
        auto it = saved.find(k);
        if (it != saved.end()) return it->second;

        cout << "? " << x << ' ' << y << endl;
        cout.flush();

        int res;
        if (!(cin >> res)) exit(0);
        cur_max = max(cur_max, (long long)res);
        saved.emplace(k, res);
        return res;
    };

    function<void(int,int,int,int)> solve = [&](int xl, int xr, int yl, int yr) {
        if (xl > xr || yl > yr) return;

        int xm = (xl + xr) / 2;
        int ym = (yl + yr) / 2;

        int val = INT_MIN;
        int vx = xm, vy = ym;  // 确保已初始化

        // 扫三条横线：ym、yl-1、yr+1
        for (int x = xl; x <= xr; ++x) {
            int nval = query(x, ym);
            if (nval > val) { val = nval; vx = x; vy = ym; }

            nval = query(x, yl - 1);
            if (nval > val) { val = nval; vx = x; vy = yl - 1; }

            nval = query(x, yr + 1);
            if (nval > val) { val = nval; vx = x; vy = yr + 1; }
        }

        // 扫三条竖线：xm、xl-1、xr+1
        for (int y = yl; y <= yr; ++y) {
            int nval = query(xm, y);
            if (nval > val) { val = nval; vx = xm; vy = y; }

            nval = query(xl - 1, y);
            if (nval > val) { val = nval; vx = xl - 1; vy = y; }

            nval = query(xr + 1, y);
            if (nval > val) { val = nval; vx = xr + 1; vy = y; }
        }

        // 看 (vx,vy) 的四邻里是否有“在当前矩形内且更大”的点
        static const int dx[4] = {-1, 0, 1, 0};
        static const int dy[4] = { 0, 1, 0,-1};
        for (int k = 0; k < 4; ++k) {
            int nx = vx + dx[k], ny = vy + dy[k];
            if (nx >= xl && nx <= xr && ny >= yl && ny <= yr && query(nx, ny) > val) {
                // 按在中线 xm / ym 的相对位置切到象限（保持你的切分方式）
                if (nx > xm) {
                    if (ny > ym) { solve(xm + 1, xr, ym + 1, yr); return; }
                    else         { solve(xm + 1, xr, yl,      ym - 1); return; }
                } else {
                    if (ny > ym) { solve(xl,      xm - 1, ym + 1, yr); return; }
                    else         { solve(xl,      xm - 1, yl,      ym - 1); return; }
                }
            }
        }
        // 没有更大的内邻居时按你的设计“收尾”——直接返回，由外层统一输出 cur_max
        return;
    };

    solve(1, n, 1, n);

    // 统一输出最终见过的最大值
    cout << "! " << cur_max << '\n';
    cout.flush();
    return 0;
}
