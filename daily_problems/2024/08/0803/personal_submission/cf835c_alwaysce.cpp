#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q, c;
	std::cin >> n >> q >> c;
	
	std::vector<int> xs(n), ys(n), s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> xs[i] >> ys[i] >> s[i];
	}
	
	std::vector<std::vector<std::vector<int> > > preS((c + 1), std::vector<std::vector<int>>(101, std::vector<int>(101, 0)) );
	std::vector<std::vector<std::vector<int> > > mat((c + 1), std::vector<std::vector<int>>(101, std::vector<int>(101, 0)) );
	
	for (int t = 0; t <= c; t++) {
		for (int i = 0; i < n; i++) {
			int x = xs[i], y = ys[i];
			mat[t][x][y] += (s[i] + t) % (c + 1);
		}
	}
	
	for (int t = 0; t <= c; t++) {
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				preS[t][i][j] = preS[t][i][j - 1] + preS[t][i - 1][j] - preS[t][i - 1][j - 1] + mat[t][i][j];
			}
		}
	}
	
	for (int j = 0; j < q; j++) {
		int t, lx, ly, rx, ry;
		std::cin >> t >> lx >> ly >> rx >> ry;
		
		int ans = preS[t % (c + 1)][rx][ry] - preS[t % (c + 1)][rx][ly - 1] - preS[t % (c + 1)][lx - 1][ry] + preS[t % (c + 1)][lx - 1][ly - 1];
		std::cout << ans << '\n'; 
	}
	return 0;
}
