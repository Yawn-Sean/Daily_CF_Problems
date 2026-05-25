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

	int n, m;
	cin >> n >> m;

	vector<int> dp = {0}, diff = {0, 0};
	int cur = 0;

	auto update = [&] () -> void {
		cur ++;
		for (int i = 0; i < cur; i ++)
			diff[i + 1] += diff[i];
		for (int i = 0; i < cur; i ++)
			dp[i] += diff[i], diff[i] = 0;
	};

	while (n --) {
		int x;
		cin >> x;

		if (x == 0) {
			update();
			dp.emplace_back(0);
			diff.emplace_back(0);
			for (int i = cur; i > 0; i --)
				dp[i] = max(dp[i], dp[i - 1]);
		}
		else if (x > 0) {
			if (x <= cur) {
				diff[x] ++;
				diff[cur + 1] --;
			}
		}
		else {
			if (-x <= cur) {
				diff[0] ++;
				diff[cur + x + 1] --;
			}
		}
	}

	update();
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}