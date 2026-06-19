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

	string s;
	cin >> s;

	string ans = "a";

	for (int i = 0; i < 2; i ++) {
		vector<string> tmp;
		if (i) tmp.emplace_back(s.substr(0, 1));

		for (int j = i; j < n; j += 2)
			tmp.emplace_back(s.substr(j, min(2, n - j)));

		sort(tmp.begin(), tmp.end());

		string tmp_ans;

		for (auto &x: tmp) {
			for (int i = 0; i < k; i ++) {
				tmp_ans += x;
			}
		}

		ans = min(ans, tmp_ans);
	}

	cout << ans;

	return 0;
}