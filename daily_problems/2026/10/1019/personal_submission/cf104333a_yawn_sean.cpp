#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> c1(20, 0), c2(20, 0);

	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		for (int j = 0; j < 20; j ++) {
			c1[j] += x >> j & 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		for (int j = 0; j < 20; j ++) {
			c2[j] += x >> j & 1;
		}
	}

	int ans = 0, mod = 1e9 + 7;

	for (int i = 0; i < 20; i ++) {
		ans += (1ll * c1[i] * (n - c2[i]) + 1ll * c2[i] * (n - c1[i])) % mod * (1 << i) % mod;
		ans %= mod;
	}
	
	for (int i = 1; i < n; i ++) ans = 1ll * ans * i % mod;

	cout << ans;

	return 0;
}