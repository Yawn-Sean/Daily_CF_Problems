#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	int i;
	for (i = 1; i <= n; ++i) cin >> a[i];

	int64_t ans = -1e18, t = -1e18;
	for (i = 1; i <= n - 1; ++i) {
		b[i] = abs(a[i] - a[i + 1]);
	}

	for (i = 1; i < n; ++i) {
		int64_t cur = b[i] * (i % 2 ? 1 : -1);
		if (t + cur > cur) {
			t += cur;									
		} else {
			t = cur;
		}
		ans = max(ans, t);
	}

	t = 0;
	for (i = 2; i < n; ++i) {
		int cur = b[i] * (i % 2 ? -1 : 1);
		if (cur + t > cur) {
			t += cur;
		} else {
			t = cur; 
		}
		ans = max(ans, t);
	}
	
	cout << ans << '\n';
}