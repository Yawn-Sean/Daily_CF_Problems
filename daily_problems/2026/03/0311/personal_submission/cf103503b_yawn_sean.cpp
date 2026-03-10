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

	int t;
	cin >> t;

	while (t --) {
		long long n, idx;
		cin >> n >> idx;

		long long ans = -1;

		long long l = 1, r = n, cur = 1, last_cnt = 0, cnt = 1;
		while (cnt <= n) {
			long long mid = l + (r - l) / 2;
			if (idx >= mid) last_cnt = last_cnt * 2 + 1;
			else last_cnt = last_cnt * 2;

			if (idx == mid) {
				ans = cur;
				break;
			}

			if (idx < mid) {
				r = mid - 1;
				cur = cur * 2;
			}
			else {
				l = mid + 1;
				cur = cur * 2 + 1;
			}

			cnt = cnt * 2 + 1;
		}

		if (ans == -1)
			ans = idx + cnt / 2 - last_cnt;

		cout << ans << ' ';
	}

	return 0;
}