#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		auto f = [&] (int x) -> long long {
			if (x < 0) return 0;

			long long ans = 0;
			vector<int> last_0(m, -1), last_1(m, -1), vis(n, 0);

			int l = 0, cur = 0;

			for (int r = 0; r < n; r ++) {
				for (int i = 0; i < m; i ++) {
					{
						int pos = min(last_0[i], last_1[i]);
						if (pos >= l && pos <= r) cur --;
						if (pos >= 0) vis[pos] --;
					}

					if (nums[r] >> i & 1) last_1[i] = r;
					else last_0[i] = r;

					{
						int pos = min(last_0[i], last_1[i]);
						if (pos >= l && pos <= r) cur ++;
						if (pos >= 0) vis[pos] ++;
					}
				}

				while (cur > x) cur -= vis[l ++];
				ans += r - l + 1;
			}

			return ans;
		};

		cout << f(k) - f(k - 1) << '\n';
	}

	return 0;
}