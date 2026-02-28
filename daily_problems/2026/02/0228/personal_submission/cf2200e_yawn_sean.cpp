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

	int M = 1e6;
	vector<int> pr(M + 1), cnt(M + 1, 0);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
				cnt[j] ++;
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		auto check = [&] () -> bool {
			for (int i = 1; i < n; i ++)
				if (nums[i] < nums[i - 1]) return false;
			return true;
		};

		if (check()) cout << "Bob\n";
		else {
			bool flg = false;
			for (auto &x: nums) {
				if (cnt[x] > 1) flg = true;
				x = pr[x];
			}

			if (flg) cout << "Alice\n";
			else cout << (check() ? "Bob\n" : "Alice\n");
		}
	}

	return 0;
}