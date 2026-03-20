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


	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> lottery(n);
	for (auto &[v, w]: lottery) cin >> v >> w;

	sort(lottery.begin(), lottery.end());

	vector<long long> acc_total = {0}, acc_weights = {0};
	for (auto &[v, w]: lottery) {
		acc_total.emplace_back(acc_total.back() + 1ll * v * w);
		acc_weights.emplace_back(acc_weights.back() + w);
	}

	long double ans = (long double)acc_total.back() / acc_weights.back();

	while (k) {
		int l, r;

		l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (lottery[mid].first > ans) r = mid - 1;
			else l = mid + 1;
		}

		int cur = l;
		long double prob = (long double)acc_weights[cur] / acc_weights[n];
		long double to_add = (long double)(acc_total[n] - acc_total[cur]) / acc_weights[n];
		long double v = to_add / (1 - prob);

		l = 1, r = k;
		while (l <= r) {
			int mid = (l + r) / 2;
			long double nans = powl(prob, mid) * (ans - v) + v;
			if (nans > lottery[cur].first) r = mid - 1;
			else l = mid + 1;
		}

		cur = min(l, k);
		k -= cur;
		ans = powl(prob, cur) * (ans - v) + v;
	}

	cout << fixed << setprecision(15) << ans;

	return 0;
}