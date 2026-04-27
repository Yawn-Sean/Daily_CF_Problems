#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	auto query = [&] (int l, int r) -> int {
		cout << "? " << l + 1 << ' ' << r + 1 << endl;
		int x; cin >> x;
		return x;
	};

	auto answer = [&] (int x) -> void {
		cout << "! " << x + 1;
	};

	if (query(0, 0)) answer(0);
	else {
		int block = 1, l_bound = 1, r_bound = 1;

		for (int i = 1; i < 30; i ++) {
			int r = 1 << i;
			int l = r / 2;

			if (r >= n) {
				r_bound = n - 1;
				break;
			}

			block = r - l;
			if (query(l, r - 1)) {
				r_bound = r - 1;
				break;
			}

			l_bound = r;
		}

		int l = l_bound, r = r_bound;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(mid - block + 1, mid)) r = mid - 1;
			else l = mid + 1;
		}

		answer(l);
	}

	return 0;
}
