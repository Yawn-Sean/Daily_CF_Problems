#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	std::cout << "? " << x << ' ' << y << std::endl;
	int res; std::cin >> res;
	return res;
}

void soviet() {
	int n; std::cin >> n;
	int pos1 = 1;

	for (int i = 2; i <= n; i++) {
		if (query(pos1, i) != pos1) {
			pos1 = i;
		}
	}
	std::vector<int> cur, ans;
	for (int i = 1; i <= n; i++) {
		if (i != pos1) {
			cur.emplace_back(i);
		}
	}
	while (cur.size()) {
		std::vector<int> ncur;
		int prime_val = cur[0];
		for (int i = 1; i < cur.size(); i++) {
			int val = query(prime_val, cur[i]);

			if (val == pos1) ncur.emplace_back(cur[i]);
			else prime_val = val;
		}

		cur = ncur;
		ans.emplace_back(prime_val);
	}

	std::cout << "! " << ans.size();
	for (int &x: ans) {
		std::cout << ' ' << x;
	}
}

int main() {
	int M_T = 1; //std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
