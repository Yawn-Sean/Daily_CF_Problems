#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		最后一次操作一定是 (k, x), x<k的形式
		(x, y) -> (y, x-?y), x-?y< y
	*/
	int n;
	cin >> n;
	
	function<int(int,int)> dfs = [&](int x, int y)->int{
		if (x == 0) {
			return -1;
		}
		return y / x + dfs(y % x, x);
	};
	
	// baoli
	int ans = n;
	for (int i = 1; i <= n; i++) {
		// 开头需要互质
		if (gcd(i, n) == 1) {
			ans = min(ans, dfs(i, n));
		}
	}
	cout << ans;
	return 0;
}
