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
	
	std::vector<int> s(n, 0);
		
	std::function<int(void)> query = [&]() -> int {
		std::cout << '?' << ' ';
		for (auto& c: s) { std::cout << c; }
		std::cout << '\n';
		std::cout.flush();
		int ans;
		std::cin >> ans;
		return ans;
	};
	
	int x = query();
	s[n - 1] = 1;
	int y = query();
	
	int pos0, pos1;
	if (x < y) {
		// 最后一个位置是0
		pos0 = n - 1;
		for (int i = 0; i < n; i++) {
			s[i] = 1;
		}
		// 全1 找1
		// 二分找第一个1前面有多少(假设为cnt)个0
		int benchmark = query();
		int l = 0, r = n - 2;
		while (l <= r) {
			int mid = (l + r) / 2;
			// 000 | 1111
			for (int i = 0; i < n; i++) {
				s[i] = (i <= mid ? 0: 1);
			}
			// mid个0+1个1是相同的 减少=mid+1 此时mid较小(mid <= cnt)
			if (benchmark - query() == mid + 1) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		pos1 = l;
	} else {
		pos1 = n - 1;
		// 全0
		int benchmark = x;
		int l = 0, r = n - 2;
		while (l <= r) {
			int mid = (l + r) / 2;
			// 111 | 0000
			for (int i = 0; i < n; i++) {
				s[i] = (i <= mid ? 1: 0);
			}
			// mid个1+1个0是相同的 减少=mid+1 此时mid较小(mid <= cnt)
			if (benchmark - query() == mid + 1) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		pos0 = l;
	}
	std::cout << "! " << pos0 + 1 << ' ' << pos1 + 1 << '\n';
	std::cout.flush();
	return 0;
}
