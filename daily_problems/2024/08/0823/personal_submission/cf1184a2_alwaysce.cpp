#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<int> cnt(n), check(n + 1);
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			for (int j = 0; j < n; j++) {
				cnt[j % i] ^= (s[j] - '0');
			}
			check[i] = 1;
			for (int j = 0; j < i; j++) {
				if (cnt[j]) {
					cnt[j] = 0;
					check[i] = 0;
				}
			}
		}
		ans += check[__gcd(i, n)];
	}
	cout << ans;
	return 0;
}
