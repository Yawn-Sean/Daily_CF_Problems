#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (auto& x: p) {
			cin >> x;
			x /= 100;
		}
		sort(p.rbegin(), p.rend());
		
		int x, a;
		int y, b;
		cin >> x >> a;
		cin >> y >> b;
		if (x > y) {
			swap(x, y);
			swap(a, b);
		}
		
		i64 k;
		cin >> k;
		
		auto check = [&](int L) {
			int cab = 0, ca = 0, cb = 0;
			for (int i = 1; i <= L; i++) {
				if (i % a == 0) {
					if (i % b == 0) {
						++cab;
					} else {
						++ca;
					}
				}
				else if (i % b == 0) {
					++cb;
				}
			}
			i64 cur = 0;
			for (int i = 0; i < n; i++) {
				if (cab) {
					cab--;
					cur = cur + 1ll * p[i] * (x + y);
				} else if (cb) {
					cb--;
					cur = cur + 1ll * p[i] * y;
				} else if (ca) {
					ca--;
					cur = cur + 1ll * p[i] * x;
				} else {
					break;
				}
			}
			return cur >= k;
		};
		
		// 二分长度L
		// 0..L-1上面 贪心的放最大的
		// cnt = (0, ..., L/a) + (0, ..., L/b) - (0, ..., L/lcm(a,b))
		// 按照x和y大小 放前cnt大的数字
		// 两种都试一下就行
		int left = 1, right = n + 1;
		int ans = -1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (not check(mid)) {
				left = mid + 1;
			} else {
				right = mid;
				ans = mid;
			}
		}
		cout << ans << '\n';
	}
	
	/*
		a 2a 3a ...
		b 2b 3b ...
		lcm(a,b), 2lcm(a,b), ...
	*/
	
	
	return 0;
}
