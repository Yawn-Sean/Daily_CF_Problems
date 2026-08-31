#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		long long s, k;
		cin >> s >> k;

		if (!s && !k) break;

		k --;

		if (s * s <= k) {
			k -= s * s;

			int x = k / (2 * s), y = k % (2 * s);

			if (y % 2 == 0) {
				y /= 2;
				cout << (y ? y : s) << '\n';
			}
			else cout << s + 1 + x << '\n';
		}
		else {
			long long l = 0, r = s;

			while (l <= r) {
				long long mid = (l + r) / 2;

				long long x = 2 * s - 1, y = x - 2 * (mid - 1);

				if ((x + y) * mid / 2 > k) r = mid - 1;
				else l = mid + 1;
			}

			{
				long long x = 2 * s - 1, y = x - 2 * (r - 1);
				k -= (x + y) * r / 2;

				if (!k) cout << s << '\n';
				else {
					int x = (k - 1) / 2, y = (k - 1) % 2;

					if (!y) cout << r + 1 + x << '\n';
					else cout << r + 1 << '\n';
				}
			}
		}
	}

	return 0;
}