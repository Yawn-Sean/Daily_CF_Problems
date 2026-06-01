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

	map<int, int> mp;

	for (int i = 2; i <= 100000; i ++) {
		while (n % i == 0) {
			mp[i] ++;
			n /= i;
		}
		if (i * i > n) break;
	}

	if (n > 1) mp[n] ++;

	vector<pair<int, int>> items;
	for (auto &[x, y]: mp) items.emplace_back(x, y);

	sort(items.begin(), items.end(), [&] (pair<int, int> x, pair<int, int> y) {return x.second % 2 > y.second % 2;});

	if (items.size() == 1) {
		cout << 2 << '\n';
		cout << 1 << ' ' << items[0].first << '\n';
	}
	else {
		if (items[0].second & 1) {
			auto [x1, y1] = items[0];
			auto [x2, y2] = items[1];

			vector<int> ans = {1, x2};

			for (int i = 0; i <= y1; i ++) {
				for (int j = 0; j < y2 - 1; j ++) {
					if (i & 1) ans.emplace_back(ans.back() / x2);
					else ans.emplace_back(ans.back() * x2);
				}
				if (i < y1) ans.emplace_back(ans.back() * x1);
			}

			ans.emplace_back(ans.back() / x2);

			for (int i = 0; i < y1 - 1; i ++) ans.emplace_back(ans.back() / x1);

			for (int i = 2; i < items.size(); i ++) {
				auto [x, y] = items[i];
				vector<int> nans;

				for (int j = 0; j < ans.size(); j ++) {
					vector<int> tmp = {ans[j]};
					for (int k = 0; k < y; k ++) tmp.emplace_back(tmp.back() * x);

					if (j & 1) reverse(tmp.begin(), tmp.end());
					for (auto &v: tmp) nans.emplace_back(v);
				}

				ans.swap(nans);
			}

			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i ++)
				cout << ans[i] << " \n"[i + 1 == ans.size()];
		}
		else {
			auto [x1, y1] = items[0];
			auto [x2, y2] = items[1];

			vector<int> ans = {x2};

			for (int i = 0; i < y1 / 2; i ++) {
				ans.emplace_back(ans.back() * x1);
				ans.emplace_back(ans.back() / x2);
				ans.emplace_back(ans.back() * x1);
				ans.emplace_back(ans.back() * x2);
			}

			ans.emplace_back(ans.back() * x2);

			for (int i = 0; i < y2 / 2 - 1; i ++) {
				for (int j = 0; j < y1 - 1; j ++)
					ans.emplace_back(ans.back() / x1);
				ans.emplace_back(ans.back() * x2);
				for (int j = 0; j < y1 - 1; j ++)
					ans.emplace_back(ans.back() * x1);
				ans.emplace_back(ans.back() * x2);
			}

			for (int i = 0; i < y1; i ++) ans.emplace_back(ans.back() / x1);
			for (int i = 0; i < y2 - 2; i ++) ans.emplace_back(ans.back() / x2);

			for (int i = 2; i < items.size(); i ++) {
				auto [x, y] = items[i];
				vector<int> nans;

				for (int j = 0; j < ans.size(); j ++) {
					vector<int> tmp = {ans[j]};

					for (int idx = 0; idx < y; idx ++) {
						tmp.emplace_back(tmp.back() * x);

						if (!j) {
							if (idx & 1) tmp.emplace_back(tmp.back() * x2);
							else tmp.emplace_back(tmp.back() / x2);
						}
					}

					if (j & 1) reverse(tmp.begin(), tmp.end());
					for (auto &x: tmp) nans.emplace_back(x);
				}

				ans.swap(nans);
			}

			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i ++)
				cout << ans[i] << " \n"[i + 1 == ans.size()];
		}
	}

	return 0;
}