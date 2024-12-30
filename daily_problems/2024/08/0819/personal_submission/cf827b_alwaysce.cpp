#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	int l = (n - 1) / k, m = (n - 1) % k;
	int ans = 2 * l + min(2, m);
	cout << ans << '\n';

	//   [1] - [2]
	//		 \ [3]
	// ...
	for (int i = 2; i <= k + 1; i++) {
		cout << 1 << ' ' << i << '\n';
	}
	// 剩下的均匀插在每个链上
	for (int i = k + 2; i <= n; i++) {
		cout << i - k << ' ' << i << '\n';
	}
	return 0;
}
