#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	i64 n, k;
	std::cin >> n >> k;
	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	i64 cur = a[0];
	i64 l = 1;
	k -= 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != cur) {
			if (l * n <= k) {
				k -= l * n;
			}
			else {
				k = (k ) / l;
				std::cout << cur << " " << a[k];
				return ;
			}
			cur = a[i];
			l = 1;
		}
		else {
			l++;
		}
	}
	k = (k) / l;
	std::cout << a[n - 1] << " " << a[k] << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
