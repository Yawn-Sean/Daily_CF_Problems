#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 m;
	cin >> m;
	
	i64 left = 1, right = 8 * m + 1;
	
	auto check = [&](i64 x) {
		i64 tmp = 0;
		for (i64 k = 2; x / k / k / k > 0; k++) {
			tmp += (x / k / k / k);
		}
		return tmp;
	};
	
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (check(mid) < m) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	cout << (check(left) == m ? left : -1) << '\n';
	return 0;
}
