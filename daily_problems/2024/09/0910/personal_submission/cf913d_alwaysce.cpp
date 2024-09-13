#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, t;
	cin >> n >> t;
	
	vector<int> val(n), ts(n);
	for (int i = 0; i < n; i++) {
		cin >> val[i] >> ts[i];
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return val[a] > val[b];
	});
	
	
	priority_queue<int> pq;
	i64 tot = 0;
	int ans = 0;
	for (auto& i: order) {
		pq.push(ts[i]);
		tot += ts[i];
		if (tot > t) {
			tot -= pq.top();
			pq.pop();
		}
		ans = max(ans, min(val[i], (int)pq.size()));
	}
	
	cout << ans << '\n';
	cout << ans << '\n';
	sort(order.begin(), order.end(), [&](int a, int b) {
		return ts[a] < ts[b];
	});
	
	int cnt = 0;
	for (auto& i: order) {
		if (val[i] >= ans and cnt < ans) {
			cnt++;
			cout << i + 1 << ' ';
		}
	}
    return 0;
}
