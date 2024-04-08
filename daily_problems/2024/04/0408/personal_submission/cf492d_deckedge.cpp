#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, x, y, t;
	cin >> n >> x >> y;
	while (n--) {
		int64_t l = 0, r = 1ll << 60, mid;
		cin >> t;
		while (l < r) {
			mid = l + r >> 1;
			if (mid / x + mid / y >= t) r = mid;
			else l = mid + 1;
		}
		if (l % x == 0 && r % y == 0) {
			cout << "Both\n";
		} else if (l % y == 0) {
			cout << "Vanya\n";
		} else {
			cout << "Vova\n";
		}
	}

	return 0;
}