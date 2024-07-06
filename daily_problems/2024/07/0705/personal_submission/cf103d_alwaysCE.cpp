#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	
	int p;
	std::cin >> p;
	
	int bound = 500;
	std::vector<i64> ans(p), idxs;
	std::vector<std::vector<int> > q_idxs(bound);
	
	for (int j = 0; j < p; j++) {
		int a, b;
		std::cin >> a >> b;
		--a;
		// 步长比较长的情况直接暴力
		if (b >= bound) {
			for (int k = a; k < n; k += b) {
				ans[j] += arr[k];
			}
		} else {
			// 存下标
			q_idxs[b].push_back(j);
		}
		idxs.push_back(a);
	}
	// (n/k)q + nk, k为公差
	// n(k+q/k) >= 2nsqrt(q)
	std::vector<i64> acc(n);
	for (int i = 1; i < bound; i++) {
		if (q_idxs[i].size()) {
			for (int j = n - 1; j >= 0; j--) {
				// 这里有亿点巧妙
				acc[j] = (j + i < n ? acc[j + i] : 0) + arr[j];
			}
			for (auto& j: q_idxs[i]) {
				ans[j] = acc[idxs[j]];
			}
		}
	}
	
	for (auto& x: ans) {
		std::cout << x << '\n';
	}
	return 0;
}
