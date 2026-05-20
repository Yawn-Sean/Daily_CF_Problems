#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	int m;
	cin >> m;
	vector<i64> z1, z2;
	for (int i = 1; i <= m; i++) {
		i64 k, d;
		cin >> k >> d;
		if (d == 1) {
			z1.push_back(k);
		} else {
			z2.push_back(k);
		}
	}

	i64 ans = 0;
	if (bx >= ax == by >= ay) {
		if (bx <= ax && by <= ay) {
			swap(ax, bx);
			swap(ay, by);
		}

		for (const auto& v : z1) {
			i64 Ay = ax + v, By = bx + v;
			Ay = max(Ay, ay);
			By = min(By, by);

			ans = max(ans, By - Ay);
		}
	} else {
		if (bx >= ax && by <= ay) {
			swap(ax, bx);
			swap(ay, by);
		}
		for (const auto& v : z2) {
			i64 Ay = -ax + v, By = -bx + v;
			Ay = max(Ay, ay);
			By = min(By, by);

			ans = max(ans, By - Ay);
		}
	}

	cout << abs(ax - bx) + abs(ay - by) - ans;
	return 0;
}
