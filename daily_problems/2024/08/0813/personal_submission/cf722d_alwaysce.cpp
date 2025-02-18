#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<int> y(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> y[i];
		mx = std::max(mx, y[i]);
	}
	std::sort(y.begin(), y.end());

	/*
		二分答案 然后怎么测可行性
		xi =>[1, mx]里面
		Y集合的长度n决定了mx至少 mx >= n
		mx <= max(y) 因为y不动就是这样的
	*/
	int left = n, right = mx + 1;
	std::set<int> ans;
	while (left < right) {
		int mid = (left + right) / 2;
		
		std::set<int> st;
		bool fl = true;
		for (int i = 0; i < n and fl; i++) {
			int cur = y[i];
			if (cur <= mid and st.find(cur) == st.end()) {
				st.insert(cur);
			} else {
				bool ok = false;
				while (cur > 1) {
					cur /= 2;
					if (cur <= mid and st.find(cur) == st.end()) {
						st.insert(cur);
						ok = true;
						break;
					}
				}
				if (not ok) {
					fl = false;
				}
			}
		}
		
		if (not fl) {
			left = mid + 1;
		} else {
			ans = st;
			right = mid;
		}
	}
	// std::cout << left << '\n';
	for (auto& x: ans) { std::cout << x << ' '; }
	std::cout << '\n';
	return 0;
}
