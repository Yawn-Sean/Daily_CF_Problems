#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n, p, x;
	cin >> n >> p >> x;
	vector<int> a(p);
	for (auto& x : a) {
		cin >> x;
	}

	auto check = [&](int mid)->bool{
		int h = 0, w = 0;
		for (auto& y : a) {
			if (y > mid) {
				w += (y - mid);
				h += w / (n - mid);
				w %= (n - mid);
			}
		}

		if (h > x || (h == x && w > 0)) {
			return 0;
		}
		return 1;
	};

	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << l << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}