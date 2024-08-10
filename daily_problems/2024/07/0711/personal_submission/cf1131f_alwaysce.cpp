#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> fa(n), nxt(n, -1), R(n);
	std::iota(fa.begin(), fa.end(), 0);
	std::iota(R.begin(), R.end(), 0);

	auto find = [&](int x) {
		while (x != fa[x]) {
			fa[x] = fa[fa[x]];
			x = fa[x];
		}	
		return x;
	};
	
	for (int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		--x; --y;
		
		x = find(x);
		y = find(y);
		nxt[R[x]] = y;
		R[x] = R[y];
		fa[y] = x;
	}
	
	int rt = find(0);
	for (int i = 0; i < n; i++) {
		std::cout << rt + 1 << ' ';
		rt = nxt[rt];
	}
	return 0;
}
