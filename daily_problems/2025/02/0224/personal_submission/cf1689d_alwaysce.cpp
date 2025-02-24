#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        The result of a absolute function can be transformed into a maximum result of linear functions.

        曼哈顿距离坐标转为切比雪夫距离下的坐标

        (x,y) -> (x+y,x-y)

        黑色点坐标全部处理 然后得到(x', y')
        让最大距离最小 => 中位数?

        (0,0), (0,1)
        (1,0), (1,1)
        (2,0), (2,1)

        -> B: (0, 0), (3, 1)
        X方向中位数 = 1.5
        Y方向中位数 = 0.5
        max(midX, midY) = 2
        // x+y=1.5, x-y=0.5 -> (x=1),(y=0.5)

        (2, 0) / (2, 1)
        -> 原坐标体系 
        x+y=2 -> (1,1)
        x-y=0


        (0,2)(1,1)(2,0)
        ->(2,-2),(2,0),(2,2)
        -> mid = (2,0)
    */
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (auto&x: grid) { cin >> x; }
        vector<int> ptx, pty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    ptx.emplace_back(i + j);
                    pty.emplace_back(i - j);
                }
            }
        }

        sort(ptx.begin(), ptx.end());
        sort(pty.begin(), pty.end());
        // for (auto&x: ptx) { cout << x << ' '; }
        // cout << '\n';
        // for (auto&y: pty) { cout << y << ' '; }
        // cout << '\n';

        // 直接暴力遍历 不需要反过来考虑
        int ansD = 5000, x = -1, y = -1;
        int L = ptx.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = max(ptx[L - 1] - (i + j), (i + j) - ptx[0]);
                int tmp2 = max(pty[L - 1] - (i - j), (i - j) - pty[0]);
                tmp = max(tmp, tmp2);
                if (tmp < ansD) {
                    ansD = tmp;
                    x = i;
                    y = j;
                }
            }
        }
        cout << 1 + x << ' ' << 1 + y << '\n';
    }


    return 0;
}
