#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
auto rng = std::mt19937_64(std::random_device()());
void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::set<int> b;
	std::set<int> c;
	while (b.size() < n) {
		int x = std::abs((int)(rng() % 1000000));
		if (b.count(x)) {
			continue;
		}
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (c.count(x + a[i])) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			b.insert(x);
			for (int i = 0; i < n; i++) {
				c.insert(x + a[i]);
			}
		}
	}
	std::cout << "YES" << endl;
	for (auto x : b) {
		std::cout << x << " ";
	}
	std::cout << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
