#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n), b(n), v;
	for (int &x : a) std::cin >> x;
	for (int &x : b) std::cin >> x;

	for (int i = 0; i < n; i++) {
		v.emplace_back(std::max(a[i], b[i]));
		v.emplace_back(std::min(a[i], b[i]));
	}

	std::vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		auto it = std::lower_bound(ans.begin(), ans.end(), v[i]);
		if (it == ans.end()) ans.emplace_back(v[i]);
		else *it = v[i];
	}
	std::cout << ans.size();
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
