#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, q; std::cin >> n >> q;
	std::vector<int> a(n);
	for (int &x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int x; std::cin >> x;
			auto it = std::lower_bound(a.begin(), a.end(), x);
			if (it == a.end()) a.emplace_back(x);
			else *it = x;
		}
		else {
			int l, r; std::cin >> l >> r;
			int ans = std::upper_bound(a.begin(), a.end(), r) - std::lower_bound(a.begin(), a.end(), l);
			std::cout << ans << '\n';
		}
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
