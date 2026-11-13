#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> bills    = {1, 2, 5, 10, 20, 50, 100, 500, 200};
	vector<int> bounds   = {1, 4, 1,  1,  4,  1,   1,  20,  50};
	vector<int> suff_gcd = {1, 1, 5, 10, 10, 50, 100, 100, 200};

	if (n & 1) {
		cout << n << '\n';
		for (int i = 0; i < n; i ++) cout << 1 << " \n"[i == n - 1];
		return 0;
	}

	auto dfs = [&] (auto &self, int cur_value, int idx, vector<int> &tmp) -> void {
		if (cur_value % suff_gcd[idx]) return ;

		if (idx == 8) {
			auto saved = tmp;
			for (int i = 0; i < cur_value / 200; i ++) saved.emplace_back(200);

			vector<int> dp(n / 2 + 1, 0);
			dp[0] = 1;

			for (auto &x: saved) {
				for (int i = n / 2; i >= x; i --) {
					dp[i] |= dp[i - x];
				}
			}

			if (dp[n / 2] == 0) {
				int k = saved.size();

				cout << k << '\n';
				for (int i = 0; i < k; i ++) cout << saved[i] << " \n"[k == n - 1];

				exit(0);
			}

			return ;
		}

		int cnt = min(cur_value / bills[idx], bounds[idx]);
		self(self, cur_value, idx + 1, tmp);

		for (int i = 1; i <= cnt; i ++) {
			tmp.emplace_back(bills[idx]);
			self(self, cur_value - bills[idx] * i, idx + 1, tmp);
		}

		for (int i = 1; i <= cnt; i ++) tmp.pop_back();
	};

	vector<int> tmp;

	dfs(dfs, n, 0, tmp);

	cout << "splittable\n";

	return 0;
}