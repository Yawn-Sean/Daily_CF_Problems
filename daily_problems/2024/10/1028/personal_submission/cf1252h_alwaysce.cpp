#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	// 长边放l
	i64 ans = 0;	
	vector<i64> l(n), w(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> w[i];
		if (l[i] < w[i]) {
			swap(l[i], w[i]);
		}
		ans = max(ans, 1ll * l[i] * w[i]);
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return l[i] > l[j];
	});
	
	priority_queue<i64> wpq;
	// 用两个地块
	wpq.push(w[order[0]]);
	
	for (int i = 1; i < n; i++) {
		i64 curL = l[order[i]];
		i64 curW = w[order[i]];
		// cout << wpq.top() << '\n';
		if (!wpq.empty()) {
			curW = min(curW, wpq.top());
		}
		ans = max(ans, 2ll * curL * curW);
		wpq.push(w[order[i]]);
	}
	
	// cout << ans1D << ' ' << ans2 << '\n';
	cout << ans / 2 << '.' << (ans % 2) * 5;
	return 0;
}
