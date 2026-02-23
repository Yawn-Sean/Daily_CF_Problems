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

	auto check = [&] (long long x) -> long long {
		long long ans = 0;
		while (x) {
			ans += x;
			x /= 10;
		}
		return ans;
	};

	while (t --) {
		long long n;
		cin >> n;

		long long l = 1, r = n;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (check(mid) > n) r = mid - 1;
			else l = mid + 1;
		}

		cout << n - r << '\n';
	}

	return 0;
}