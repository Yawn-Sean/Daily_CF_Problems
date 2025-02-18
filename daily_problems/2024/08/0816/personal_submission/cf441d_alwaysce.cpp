#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int n;
	std::cin >> n;
	
	std::vector<int> perm(n), vis(n);
	for (auto& v: perm) { std::cin >> v; v--; }
	
	int swaps = n;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			swaps--;
			int j = i;
			while (!vis[j]) {
				vis[j] = 1;
				j = perm[j];
			}
		}
	}
	
	int target;
	std::cin >> target;
	
	std::cout << abs(swaps - target) << '\n';
	// 合并
	if (target > swaps) {
		for (int cnt = 0; cnt < target - swaps; cnt++) {
			for (int i = 0; i < n; i++) {
				vis[i] = 0;
			}
			int x = -1, y = -1;
			// 找两个下标最小的进行合并
			for (int i = 0; i < n; i++) {
				if (!vis[i]) {
					if (x == -1) {
						x = i;
					} else {
						y = i;
						break;
					}
					
					int j = i;
					while (!vis[j]) {
						vis[j] = 1;
						j = perm[j];
					}
				}
			}
			std::swap(perm[x], perm[y]);
			std::cout << x + 1 << ' ' << y + 1 << ' ';
		}
	} else {
		// 拆分
		for (int cnt = 0; cnt < swaps - target; cnt++) {
			for (int i = 0; i < n; i++) {
				vis[i] = 0;
			}
			for (int i = 0; i < n; i++) {
				// 找一个最小下标非自环
				if (perm[i] != i) {
					int x = i, y = n;
					while (!vis[i]) {
						vis[i] = 1;
						if (i != x) {
							y = std::min(y, i);
						}
						i = perm[i];
					}
					std::swap(perm[x], perm[y]);
					std::cout << x + 1 << ' ' << y + 1 << ' ';
					break;
				}
			}
		}
	}
	return 0;
}
