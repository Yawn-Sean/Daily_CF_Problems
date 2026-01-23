#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<long long> vals = {k + 1}, cnt = {1};

	while (vals.back() < n && vals.size() < k) {
		vals.emplace_back(vals.back() * k + 1);
		cnt.emplace_back(cnt.back() * k + 1);
	}

	int ans = max(n - vals.back(), 0ll);
	n -= ans;

	for (int i = vals.size() - 1; i >= 0; i --) {
		ans += n / vals[i] * cnt[i];
		n %= vals[i];
	}

	cout << ans;

	return 0;
}