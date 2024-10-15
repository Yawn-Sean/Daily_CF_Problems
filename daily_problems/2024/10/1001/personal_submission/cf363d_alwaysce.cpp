#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, a;
	cin >> n >> m >> a;
	vector<int> b(n), p(m);
	for (auto& x: b) { cin >> x; }
	for (auto& x: p) { cin >> x; }
	sort(p.begin(), p.end());	
	sort(b.begin(), b.end());

	int left = 0, right = min(n, m) + 1;
	int mx = 0;
	
	auto check = [&](int target) {
		i64 need = a;
		for (int i = target - 1; i >= 0; i--) {
			int bidx = n - (target - i);
			if (b[bidx] < p[i]) {
				need -= (p[i] - b[bidx]);
			}
		}
		return need >= 0;
	};
	
	while (left < right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			mx = mid;
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	if (mx == 0) {
		cout << 0 << ' ' << 0;
		return 0;
	}
	
	// 已知最多能借的数量
	// 现在求最少动用cost
	i64 need = a;
	i64 sumb = 0;
	for (int i = mx - 1; i >= 0; i--) {
		int bidx = n - (mx - i);
		if (b[bidx] < p[i]) {
			need -= (p[i] - b[bidx]);
			sumb += b[bidx];
		} else {
			sumb += p[i];
		}
	}
	// 剩下的是补完必须的之后多出来的
	// 可以抵消掉sum(b) - need这么多
	sumb -= need;
	cout << mx << ' ' << max(0ll, sumb);
	return 0;
}
