#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> xs(n), ys(n);
		for (int i = 0; i < n; i++) {
			cin >> xs[i] >> ys[i];
			if (xs[i] > ys[i]) {
				swap(xs[i], ys[i]);
			}
		}
		
		vector<int> order(n), ans(n, -2);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j) {
			return (xs[i] < xs[j] ? true : (xs[i] == xs[j] and ys[i] > ys[j]));
		});
		
		int cur = 1e9 + 1, idx = -1;
		for (auto& x: order) {
			// 相同的x y从大到小排序
			if (ys[x] <= cur) {
				cur = ys[x];
				idx = x;
			} else {
				ans[x] = idx;
			}
		}
		for (auto& x: ans) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
 	}

	
	return 0;
}
