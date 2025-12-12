#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<std::pair<long long, long long>> pts(n);
	for (auto &[x, y]: pts) std::cin >> x >> y;

	std::set<std::pair<long long, long long>> st(pts.begin(), pts.end());

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			auto &[x1, y1] = pts[i];
			auto &[x2, y2] = pts[j];
			long long dx = x2 - x1;
			long long dy = y2 - y1;

			if (st.count({x1 + dx - dy, y1 + dx + dy}) && st.count({x1 - dy, y1 + dx})) ans++;
			if (st.count({x1 + dy, y1 - dx}) && st.count({x1 + dx + dy, y1 + dy - dx})) ans++;
		}
	}
	std::cout << ans / 4;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
