#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> ls(n), rs(n);
	for (int i = 0; i < n; i++) {
		std::cin >> ls[i] >> rs[i];
	}
	std::vector<int> id(n);
	std::iota(id.begin(), id.end(), 0);
	
	std::sort(id.begin(), id.end(), [&](int i, int j) {
		return ls[i] < ls[j];
	});
	
	int ans = -1, chosen = -1;
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	for (auto& i: id) {
		pq.push(rs[i]);
		if ((int)pq.size() > k) pq.pop();
		if ((int)pq.size() == k and pq.top() - ls[i] > ans) {
			ans = pq.top() - ls[i];
			chosen = ls[i];
		}
	}
	
	if (ans == -1) {
		std::cout << ans + 1 << '\n';
		for (int i = 1; i <= k; i++) {
			std::cout << i << ' ';
		}
	} else {
		std::cout << ans + 1 << '\n';
		for (int i = 0; i < n; i++) {
			if (k > 0 and ls[i] <= chosen and rs[i] >= chosen + ans) {
				k--;
				std::cout << i + 1 << ' ';
			}
		}
	}
	std::cout << '\n';
	return 0;
}
