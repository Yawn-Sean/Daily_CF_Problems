#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	long long k = 0;
	for (auto &v: nums) {
		k += v;
		v *= n;
	}

	cout << k - 1 << '\n';

	vector<int> v1(n), v2(n);
	vector<long long> w(n);

	for (int i = 0; i < n; i ++) {
		int mi_idx = -1;

		for (int j = 0; j < n; j ++) {
			if (nums[j] && (mi_idx == -1 || nums[j] < nums[mi_idx])) {
				mi_idx = j;
			}
		}

		if (nums[mi_idx] >= k) {
			v1[i] = mi_idx;
			v2[i] = mi_idx;
			w[i] = 0;
		}
		else {
			int to_pair = -1;

			for (int j = 0; j < n; j ++) {
				if (j != mi_idx && nums[j] && nums[mi_idx] + nums[j] >= k) {
					to_pair = j;
				}
			}

			v1[i] = mi_idx;
			v2[i] = to_pair;
			w[i] = nums[mi_idx];
		}

		nums[v1[i]] -= w[i];
		nums[v2[i]] -= k - w[i];
	}

	for (int i = 0; i < n; i ++)
		cout << v1[i] + 1 << " \n"[i == n - 1];
	for (int i = 0; i < n; i ++)
		cout << v2[i] + 1 << " \n"[i == n - 1];
	for (int i = 0; i < n; i ++)
		cout << w[i] << " \n"[i == n - 1];

	return 0;
}