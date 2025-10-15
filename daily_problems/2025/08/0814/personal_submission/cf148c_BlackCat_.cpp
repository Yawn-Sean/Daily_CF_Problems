#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> ans;
	i64 sum = 1;
	ans.push_back(1);
	int sa = a;
	int sb = b;
	for (int i = 1; i < n; i++) {
		if (b != 0) {
			b--;
			ans.push_back(sum + 1);
			sum += ans.back();
		}
		else if (a != 0) {
			if (ans.back() + 1 > sum) {
				ans.push_back(ans.back());
				sum += ans.back();
				continue;
			}
			ans.push_back(ans.back() + 1);
			sum += ans.back();
			a--;
		}
		else {
			ans.push_back(ans.back());
			sum += ans.back();
		}
	}
	if (a != 0 || b != 0) {
		std::cout << -1 << endl;
		return ;
	}
	int a1 = 0;
	int b1 = 0;
	i64 sum1 = ans[0];
	for (int i = 1; i < n; i++) {
		if (ans[i] < 1 || ans[i] > 50000) {
			std::cout << -1 << endl;
			return ;
		}
		if (ans[i] > sum1) {
			b1++;
		}
		else if (ans[i] > ans[i - 1]) {
			a1++;
		}
		sum1 += ans[i];
	}
	// for (int i = 0; i < n; i++) {
	// 	std::cout << ans[i] << " \n"[i == n - 1];
	// }
	// std::cout << b1 << " " << a1 << endl;
	if (a1 == sa && b1 == sb) {
		for (int i = 0; i < n; i++) {
			std::cout << ans[i] << " \n"[i == n - 1];
		}
	}
	else {
		std::cout << -1 << endl;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
