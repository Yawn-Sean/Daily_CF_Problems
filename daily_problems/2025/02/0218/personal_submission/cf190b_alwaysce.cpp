#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        考虑两个圆圈的位置
        存在相交 - r = 0
        不相交
        - 嵌套
        - 分离    
    */
    i64 x1, y1, r1;
    i64 x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    i64 d = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    long double ans = 0.0;

    if(d < (r1 - r2) * (r1 - r2)) {
        // 嵌套在一起
        ans = fabs(r1 - r2) - sqrt(d);
        ans /= 2.0;
    } else if(d > (r1 + r2) * (r1 + r2)) {
        ans = sqrt(d) - fabs(r1 + r2);
        ans /= 2.0;
    }
    cout << fixed << setprecision(15) << ans;
    
    return 0;
}
