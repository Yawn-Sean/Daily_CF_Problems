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

	int n, k;
	cin >> n >> k;

	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i ++) cin >> nums[i];

	vector<int> idxs1, idxs2;
	for (int i = 1; i <= n; i ++) {
		if (i & 1) idxs1.emplace_back(i);
		else idxs2.emplace_back(i);
	}

	sort(idxs1.begin(), idxs1.end(), [&] (int i, int j) {return nums[i] < nums[j];});
	sort(idxs2.begin(), idxs2.end(), [&] (int i, int j) {return nums[i] < nums[j];});

	auto output = [&] (int x) -> void {
		cout << x << endl;
		int v; cin >> v;
	};

	for (int i = 0; i < k; i ++) {
		int v;
		cin >> v;

		if (v == 1) {
			int resid = k - i;
			if (nums[idxs1.back()] >= nums[idxs2.end()[-resid]]) {
				int idx = idxs1.back(); idxs1.pop_back();
				output(idx);
			}
			else {
				int idx = idxs2.back(); idxs2.pop_back();
				output(idx);
			}
		}
		else {
			int idx = idxs2.back(); idxs2.pop_back();
			output(idx);
		}
	}

	return 0;
}