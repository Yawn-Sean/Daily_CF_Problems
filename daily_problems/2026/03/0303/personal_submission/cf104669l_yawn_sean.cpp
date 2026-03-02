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
		long long a, b;
		cin >> a >> b;

		long long total = 1ll * (2 * a + b - 1) * b / 2;

		auto check = [&] (long long x) -> bool {
			for (long long i = 1; i < b; i ++) {
				long long l = a * i + i * (i - 1) / 2;
				long long r = a * i + (2 * b - 1 - i) * i / 2;
				if (r / x * x >= l) return true;
			}
			return false;
		};

		long long ans = 0;

		for (long long i = 1; i * i <= total; i ++) {
			if (total % i == 0) {
				if (check(i)) ans = max(ans, i);
				if (check(total / i)) ans = max(ans, total / i);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}