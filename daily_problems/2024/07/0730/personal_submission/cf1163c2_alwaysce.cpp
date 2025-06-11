#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	
	std::vector<int> xs(n), ys(n);
	for (int i = 0; i < n; i++) {
		std::cin >> xs[i] >> ys[i];
	}
	
	std::set<std::array<int,3> > lines;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int dx = xs[i] - xs[j];
			int dy = ys[i] - ys[j];
			int g = std::gcd(dx, dy);
			dx /= g; dy /= g;
			if (dx < 0 or (dx == 0 and dy < 0)) {
				dx = -dx;
				dy = -dy;
			}
			std::array<int,3> tmp = {dx, dy, xs[i] * dy - ys[i] * dx};
			lines.emplace(tmp);
		}
	}
	i64 k = (i64)lines.size();
	i64 ans = k * (k - 1) / 2;
	std::map<std::pair<int,int>, int> mp;
	
	for (auto& v: lines) {
		ans -= mp[{v[0], v[1]}];
		mp[{v[0], v[1]}]++;
	}
	std::cout << ans << '\n';
	return 0;
}
