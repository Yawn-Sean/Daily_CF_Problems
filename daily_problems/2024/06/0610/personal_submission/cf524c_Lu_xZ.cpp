#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 5005, K = 25, V = 2e8;

int n, k, q, a[N];
bitset<10000005> mp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		mp[a[i]] = 1;
	}
	cin >> q;				//20
	while(q --) {
		int x; cin >> x;
		int ans = k + 1;
		for(int i = 1; i <= n; ++ i) {
			if(x % a[i] == 0) {
				ans = min(ans, x / a[i]);
			}
			for(int j = 1; j < k; ++ j) {
				int y = x - a[i] * j;
				if(y <= 0) {
					break;
				}
				for(int l = 1; l + j <= k; ++ l) {
					if(y % l == 0 && y / l <= a[n] && mp.test(y / l)) {
						ans = min(ans, l + j);
					}
				}
			}
		}
		if(ans > k) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}
