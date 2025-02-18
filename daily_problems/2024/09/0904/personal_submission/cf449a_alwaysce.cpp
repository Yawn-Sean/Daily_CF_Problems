#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, m, k;
	cin >> n >> m >> k;
	
	auto f = [&](i64 x) {
		// n / (p + 1) = x
		// p最大值等于多少?
		// n / (p + 1) = x
		// p = n / x - 1
		return x * (m / max(1ll, (k - (n / x - 1) + 1)));
	};
	i64 ans = 0;
	for (i64 i = 1; i <= n and i * i <= 1e9; i++) {
		// x = |n / (i + 1)|
		// 取值有sqrt(n)种
		// 枚举边长 = i 或者 n / i
		ans = max(ans, f(i));
		ans = max(ans, f(n / i));
	}
	cout << (ans == 0 ? -1 : ans) << '\n';
    return 0;
    
}
