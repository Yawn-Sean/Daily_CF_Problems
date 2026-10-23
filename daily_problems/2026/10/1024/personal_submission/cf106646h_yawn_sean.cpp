#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v1(2 * n), v2(2 * n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	long long ans = 0;
	priority_queue<int> pq;

	for (int i = 0; i < 2 * n; i ++) {
		ans -= v2[i];
		pq.push(v1[i] + v2[i]);
		if (i % 2 == 0) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}