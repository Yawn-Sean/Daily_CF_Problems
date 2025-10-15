#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const double PI = acos(-1.0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	*/
	
	int n, rx, ry;
	cin >> n >> rx >> ry;
	
	vector<i64> px(n), py(n);
	__int128_t min_dist = 1e18, min_dist2 = 1, max_dist = 0;
	for (int i = 0; i < n; i++) {
		cin >> px[i] >> py[i];
		px[i] -= rx;
		py[i] -= ry;
		
		__int128_t v = 1ll * px[i] * px[i] + 1ll * py[i] * py[i];
		if (v < min_dist) { min_dist = v; }
		if (v > max_dist) { max_dist = v; }
	}
	
	for (int i = 0; i < n; i++) {
		__int128_t x1 = px[i], y1 = py[i];
		__int128_t x2 = px[(i + 1) % n], y2 = py[(i + 1) % n];
		
		__int128_t v1 = x1 * x1 + y1 * y1;
		__int128_t v2 = x2 * x2 + y2 * y2;
		__int128_t v = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		if (v1 + v > v2 and v2 + v > v1) {
			// o-x1-x2
			__int128_t a = (x1 * y2 - x2 * y1) * (x1 * y2 - x2 * y1);
			if (a * min_dist2 < v * min_dist) {
				min_dist = a;
				min_dist2 = v;
			}
		}
	}
	// 外侧半径R^2
	// 内侧距离r = 三角形面积 除以 AB 的长度
    double ans = PI * (max_dist * min_dist2 - min_dist) / min_dist2;
    
    // 输出结果，保留至少6位小数
    cout << fixed << setprecision(10) << ans;
    
	return 0;
}
