#include <bits/stdc++.h>
using i64 = long long;

std::vector<int> dirs = {-1, 0, 1, 0, -1};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int n, t;
	std::cin >> n >> t;
	
	std::vector<std::vector<int>> pos(151, std::vector<int>(151));
	pos[75][75] = n;
	
	/*
	*/	
	while (true) {
		bool used = false;
		for (int i = 0; i <= 150; i++) {
			for (int j = 0; j <= 150; j++) {
				if (pos[i][j] >= 4) {
					int add = pos[i][j] / 4;
					pos[i][j] %= 4;
					
					for (int d = 0; d < 4; d++) {
						int dx = dirs[d], dy = dirs[d + 1];
						pos[i + dx][j + dy] += add;
						used = true;
					}
				}
			}
		}
		
		if (not used) {
			break;
		}
	}
	
	for (int i = 0; i < t; i++) {
		int qx, qy;
		std::cin >> qx >> qy;
		if (abs(qx) > 75 or abs(qy) > 75) {
			std::cout << 0 << '\n';
		} else {
			qx += 75;
			qy += 75;
			std::cout << pos[qx][qy] << '\n';
		}
	}
	
	return 0;
}
