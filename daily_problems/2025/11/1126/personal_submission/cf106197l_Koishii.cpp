#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<std::vector<int>> ans(n, std::vector<int> (n, 1));

	for (int i = 0;i < n; i++) {
		for (int j = 0; j < i; j++) {
			ans[i][j] = 3;
		}
	}
	for (int i = n % 2; i < n; i++) {
		ans[n - 1][i]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << ans[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
