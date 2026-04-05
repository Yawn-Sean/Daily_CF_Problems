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

	int n, q;
	cin >> n >> q;

	vector<pair<int, int>> intervals(n);
	vector<int> seps;

	for (auto &[l, r]: intervals) {
		cin >> l >> r;
		seps.emplace_back(l);
		seps.emplace_back(r + 1);
	}

	sort(seps.begin(), seps.end());

	int k = seps.size();
	vector<int> diff(k, 0);

	for (auto [l, r]: intervals) {
		diff[lower_bound(seps.begin(), seps.end(), l) - seps.begin()] ++;
		diff[lower_bound(seps.begin(), seps.end(), r + 1) - seps.begin()] --;
	}

	for (int i = 1; i < k; i ++) diff[i] += diff[i - 1];

	vector<long long> acc(k, 0);
	for (int i = 0; i < k - 1; i ++)
		acc[i + 1] = acc[i] + 1ll * diff[i] * (seps[i + 1] - seps[i]);

	while (q --) {
		long long x;
		cin >> x; x --;

		int p = upper_bound(acc.begin(), acc.end(), x) - acc.begin() - 1;
		cout << seps[p] + (x - acc[p]) / diff[p] << '\n';
	}

	return 0;
}