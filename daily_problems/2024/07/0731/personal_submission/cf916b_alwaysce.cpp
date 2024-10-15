#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n;
	int k;
	std::cin >> n >> k;
	
	if (__builtin_popcountll(n) > k) {
		std::cout << "No\n";
		return 0;
	}
	
	std::vector<int> ans;
	if (n < k) {
		int v = 63 - __builtin_clzll(k / n);
		for (int i = 0; i < (n << v); i++) {
			ans.push_back(-v);
		}
	} else {
		int l = 0, r = 63 - __builtin_clzll(n);
		while (l <= r) {
			int m = (l + r) / 2;
			i64 cur = n, cnt = 0;
			for (int i = m; i >= 0; i--) {
				i64 v = (cur >> i);
				cnt += v;
				cur -= (v << i);
			}
			if (cnt <= k) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		
		for (int i = l; i >= 0; i--) {
			i64 v = (n >> i);
			n -= (v << i);
			for (int _ = 0; _ < v; _++) {
				ans.emplace_back(i);
			}
		}
	}	
	
	while ((int)ans.size() <  k) {
		int u = ans.back();
		ans.pop_back();
		ans.emplace_back(u - 1);
		ans.emplace_back(u - 1);
	}
		
	std::cout << "Yes\n";
	for (auto& x: ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
