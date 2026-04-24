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

	while (t --) {
		string s1, s2;
		cin >> s1 >> s2;

		int n = s1.size();
		vector<int> tmp;

		for (int i = 0; i < n; i ++) {
			if (i) tmp.emplace_back(-1);
			tmp.emplace_back(s1[i] * 1000 + s2[i]);
		}

		vector<int> manacher(2 * n - 1, 0), starting(2 * n, 0), ending(2 * n, 0);
		int j = 0;

		for (int i = 0; i < 2 * n - 1; i ++) {
			if (j + manacher[j] >= i)
				manacher[i] = min(manacher[2 * j - i], j + manacher[j] - i);
			while (i - manacher[i] - 1 >= 0 && i + manacher[i] + 1 < 2 * n - 1 && tmp[i - manacher[i] - 1] == tmp[i + manacher[i] + 1])
				manacher[i] ++;
			if (i + manacher[i] > j + manacher[j]) j = i;

			starting[i - manacher[i]] ++;
			starting[i + 1] --;

			ending[i] ++;
			ending[i + manacher[i] + 1] --;
		}

		for (int i = 1; i < 2 * n; i ++) {
			starting[i] += starting[i - 1];
			ending[i] += ending[i - 1];
		}

		long long ans = 0;

		for (int i = 0; i < n; i ++) {
			if (s1[i] != s2[n - 1 - i] || s2[i] != s1[n - 1 - i]) break;
			ans ++;
			if (i < n - 1) {
				ans += starting[2 * (i + 1)];
				ans += ending[2 * (n - i - 2)];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}