#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        (+-a, +-b)的位移向量
        初始在(i,j)
        问最少需要多少步能够到达
        (0,0), (0,m-1), (n-1,0), (n-1,m-1) 这些位置中的任意一个?
        至少要执行多少次操作?

        dx%a == 0 && dy % b == 0
        每走一步奇偶性同时改变 所以最终的dx方向/dy方向奇偶性需要完全一致
        */
    
    int n, m;
    cin >> n >> m;
    int i, j;
    cin >> i >> j;
    int a, b;
    cin >> a >> b;

    int inf = 1e9;
    auto check = [&](int dx, int dy) {
        if (dx % a || dy % b) {
            return inf;
        }
        dx /= a;
        dy /= b;
        if ((dx ^ dy) & 1) {
            return inf;
        }
        return max(dx, dy);
    };

    if ((i == 1 || i == n) && (j == 1 || j == m)) {
        cout << 0;
    } else if (n <= a || m <= b) {
        cout << "Poor Inna and pony!";
    } else {
        int ans = inf;
        for (auto&x: {1, n}) {
            for (auto&y : {1, m}) {
                ans = min(ans, check(abs(x - i), abs(y - j)));
            }
        }
        if (ans < inf) { cout << ans; }
        else {
            cout << "Poor Inna and pony!";
        }
    }
    return 0;
}
