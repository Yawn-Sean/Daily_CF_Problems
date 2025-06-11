#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n;
	cin >> n;
	
	bool ok = false;
	for (int i = 0; i < 60; i++) {
		i64 v = (1ll << i);
		i64 l = 0, r = min(1ll << 31, n / max(v - 1, 1ll));
		while (l < r) {
			i64 m = (l + r) / 2;
			if (m * (m - 1) / 2 + m * (v - 1) < n) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		if (l * (l - 1) / 2 + l * (v - 1) == n and l % 2 == 1) {
			cout << l * v << '\n';
			ok = true;
		}
	}
	
	if (!ok) {
		cout << -1 << '\n';
	}
	
	return 0;
}
