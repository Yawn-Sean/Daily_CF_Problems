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

	int t;
	cin >> t;

	vector<string> ans_str = {"2", "1.5", "1"};

	while (t --) {
		int n;
		long long T, total = 0;

		cin >> n >> T;

		vector<pair<long long, int>> tmp;

		for (int i = 0; i < n; i ++) {
			long long x;
			cin >> x;
			tmp.emplace_back(x / 3, i);
			tmp.emplace_back(x / 6, i);
			total += x / 2;
		}

		sort(tmp.begin(), tmp.end());

		int score = 50 * n;

		vector<int> ans(n, 0);

		for (auto &[x, i]: tmp) {
			if (total + x <= T) {
				total += x;
				score += 25;
				ans[i] ++;
			}
		}

		cout << score << '\n';
		for (int i = 0; i < n; i ++)
			cout << ans_str[ans[i]] << " \n"[i == n - 1];
	}

	return 0;
}