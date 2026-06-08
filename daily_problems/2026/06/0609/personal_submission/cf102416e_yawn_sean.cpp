#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<array<int, 4>> balls(n);
	for (auto &[x, y, z, r]: balls) {
		cin >> x >> y >> z >> r;
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int v1, int v2) {return balls[v1][3] > balls[v2][3];});

	vector<int> ans;

	for (auto &i: order) {
		bool flg = true;
		
		for (auto &j: ans) {
			auto [x1, y1, z1, r1] = balls[i];
			auto [x2, y2, z2, r2] = balls[j];
			int dx = x1 - x2, dy = y1 - y2, dz = z1 - z2;
			int totr = r1 + r2;

			if (dx * dx + dy * dy + dz * dz < totr * totr) {
				flg = false;
			}
		}

		if (flg) ans.emplace_back(i);
	}

	cout << ans.size() << '\n';
	for (auto &x: ans) cout << x + 1 << ' ';

	return 0;
}