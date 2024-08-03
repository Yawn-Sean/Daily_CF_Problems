#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int red() {
	int x;
	cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = red(), m = red(), low, high;
	vector<int> a(n);
	generate(all(a), red);
	auto check = [&](int mid) {
		int mx = 0;
		for (int i = 0; i < n; i++) {
			int cur = a[i];
			if (cur < mx) {
				if (mx - cur > mid) {
					return false;
				}
			} else {
				if (m - cur + mx > mid) {
					mx = cur;
				}
			}
		}
		return true;
	};
	low = 0, high = m;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	cout << low << '\n';

	return 0;
}