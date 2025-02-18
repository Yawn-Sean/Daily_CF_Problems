#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<i64> p(n), pre(n + 1);
	i64 ans = 0;
		
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		ans ^= p[i];
	}
	
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] ^ i;
	}
	
	for (int i = 1; i <= n; i++) {
		int rep = n / i;
		int rem = n % i;
		if (rep & 1) {
			// 奇数次
			// 0..rem] [rem+1.. i-1]
			ans ^= (pre[i - 1] ^ pre[rem]);
		} else {
			// 重复了偶数次
			// 0..rem]
			ans ^= pre[rem];
		}
	}
	cout << ans;
	
	return 0;
}
