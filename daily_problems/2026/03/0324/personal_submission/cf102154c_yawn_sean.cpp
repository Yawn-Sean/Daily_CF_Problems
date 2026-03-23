#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> perm(n), help_perm(n);
	for (auto &x: perm) cin >> x;
	iota(help_perm.begin(), help_perm.end(), 1);

	vector<pair<int, int>> ops;

	auto op = [&] (int l, int r) -> void {
		ops.emplace_back(l + 1, r + 1);

		int half = (r - l + 1) / 2;
		vector<int> vals;

		for (int i = 0; i < half; i ++) {
			vals.emplace_back(help_perm[l + i + half]);
			vals.emplace_back(help_perm[l + i]);
		}

		for (int i = l; i <= r; i ++) help_perm[i] = vals[i - l];
	};

	for (int i = 0; i < 500; i ++) {
		int l = rng();
		int r = rng();

		l = abs(l) % n;
		r = abs(r) % n;

		if ((r - l) & 1)  {
			if (l > r) swap(l, r);
			op(l, r);
		}
	}

	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < i; j ++) {
			if (help_perm[j] == perm[i]) {
				int cur = j;
				while (cur != i) {
					int v = min(cur + 1, i - cur);
					op(cur - v + 1, cur + v);
					cur += v;
				}
			}
		}
	}

	reverse(ops.begin(), ops.end());

	cout << ops.size() << '\n';
	for (auto &[x, y]: ops) cout << x << ' ' << y << '\n';

	return 0;
}