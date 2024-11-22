#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*	
		二次函数 x 和 y 分开求解
	*/
	int n, m;
	cin >> n >> m;
	i64 pf = 0, c = 0, d = 0, cost = 0;
	
	for (int i = 2; i < 4 * n; i += 4) {
		for (int j = 2; j < 4 * m; j += 4) {
			int x;
			cin >> x;
			pf += x; // 二次项系数完全一致的
			c += 2ll * x * i; // x维度的一次项
			d += 2ll * x * j; // y维度的一次项
			cost += 1ll * x * (i * i + j * j); // 常数项
		}
	}
	
	// 二次函数顶点
	auto check = [&](i64 x, i64 y) -> i64 {
		if (x == 0) { return 0; }
		i64 top = (y / x) / 8ll;
		bool fl = (abs(8ll * top * x - y) <= abs(8ll * (top + 1ll) * x - y));
		if (fl) {
			return top;
		}
		return top + 1ll;
	};
	
	i64 x = check(pf, c) * 4ll;
	i64 y = check(pf, d) * 4ll;
	cout << pf * (x * x + y * y) - c * x - d * y + cost << '\n';
	cout << x / 4 << ' ' << y / 4 << '\n';
	return 0;
}

