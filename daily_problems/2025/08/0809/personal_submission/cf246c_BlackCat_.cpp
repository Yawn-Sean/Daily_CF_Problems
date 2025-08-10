#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			std::cout << i + 1 << " ";
			for (int l = 0; l < i; l++) {
				std::cout << a[l] << " ";
			}
			std::cout << a[j] << endl;

			k--;
			if (k == 0) {
				return ;
			}
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
