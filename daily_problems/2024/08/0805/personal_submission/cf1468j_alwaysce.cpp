#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		
		std::vector<std::array<int,3>> edges(m);
		std::vector<int> used(m, 0);
		DSU d(n);
		
		for (int i = 0; i < m; i++) {
			int x, y, s;
			std::cin >> x >> y >> s;
			x--; y--;
			edges[i] = {x, y, s};
		}
		
		std::sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		
		int mx = 0;
		i64 ans = 0;
		for (int i = 0; i < m; i++) {
			int u = edges[i][0], v = edges[i][1];
			if (!d.same(u, v)) {
				d.merge(u, v);
				used[i] = 1;
				
				mx = std::max(mx, edges[i][2]);
				if (edges[i][2] > k) {
					ans += edges[i][2] - k;
				}
			}
		}
		
		if (mx < k) {
			ans = k - mx;
			for (int i = 0; i < m; i++) {
				if (!used[i]) {
					i64 t1 = abs(edges[i][2] - k);
					ans = std::min(ans, t1);
				}
			}
		}
		
		std::cout << ans << '\n';
	}
	
	return 0;
}
