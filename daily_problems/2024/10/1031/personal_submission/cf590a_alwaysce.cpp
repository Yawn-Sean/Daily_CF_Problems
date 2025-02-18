#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		res[i] = a[i];
	}
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			int last = i - 1;
			int L = 1;
			while (i < n and a[i] != a[i - 1]) {
				L++;
				i++;
			}
			
			i -= 1;
			if (L % 2) {
				// 奇数长度
				// 10101  01010
				for (int j = last; j <= i; j++) {
					res[j] = a[last];
				}
				ans = max(ans, L / 2);
			} else {
				// 偶数长度
				// 101010
				// => 110100
				// => 1   1100   0
				//    [last]    [i]
				// [1, 6] => [1,2,3] [4,5,6]
				for (int j = last; j <= (last + i) / 2; j++) {
					res[j] = a[last];
				}
				for (int j = (last + i) / 2 + 1; j <= i; j++) {
					res[j] = a[i];
				}
				ans = max(ans, L / 2 - 1);
			}
		}
	}
	
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}
