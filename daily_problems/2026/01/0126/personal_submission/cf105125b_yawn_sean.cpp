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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int op_total = 0, op_step2 = 0;

		for (auto &v: nums) {
			op_total += v;
			op_step2 += max(v - 1, 0);
		}

		if (op_total % 2 == 0) cout << "NO\n";
		else if (op_step2 < op_total - op_step2 - 1) cout << "NO\n";
		else {
			cout << "YES\n";

			vector<int> order;
			for (int i = 0; i < n; i ++) {
				if (nums[i]) {
					order.emplace_back(i);
				}
			}

			sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

			vector<int> ones;
			int pt = 0, flg = 1, k = order.size();

			while (op_total --) {
				while (pt < k && nums[order[pt]] == 1) {
					ones.emplace_back(order[pt]);
					pt ++;
				}

				if (flg && !ones.empty()) {
					int idx = ones.back(); ones.pop_back();
					nums[idx] --;
					cout << idx + 1 << ' ';
				}
				else {
					nums[order[pt]] --;
					cout << order[pt] + 1 << ' ';
				}
				flg ^= 1;
			}

			cout << '\n';
		}
	}

	return 0;
}