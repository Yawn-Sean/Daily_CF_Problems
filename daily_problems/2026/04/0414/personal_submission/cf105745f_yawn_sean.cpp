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

	string s;
	cin >> s;

	int n = s.size();

	auto possible_positions = [&] (string s) -> vector<int> {
		string tmp;
		for (int i = 0; i < n; i ++) {
			if (i) tmp += '*';
			tmp += s[i];
		}

		vector<int> manacher(2 * n - 1, 0);
		int idx = 0;

		for (int i = 1; i < 2 * n - 1; i ++) {
			if (idx + manacher[idx] > i)
				manacher[i] = min(idx + manacher[idx] - i, manacher[2 * idx - i]);
			while (i - manacher[i] - 1 >= 0 && i + manacher[i] + 1 < 2 * n - 1 && tmp[i - manacher[i] - 1] == tmp[i + manacher[i] + 1])
				manacher[i] ++;
			if (i + manacher[i] > idx + manacher[idx]) idx = i;
		}

		vector<int> ans(n + 1, 0);
		ans[0] = 1;

		int to_fill = 0;

		for (int i = 1; i < 2 * n - 1; i += 2) {
			if (i > to_fill && i - manacher[i] <= to_fill) {
				ans[(2 * i - to_fill) / 2 + 1] = 1;
				to_fill = 2 * i - to_fill + 2;
			}
		}

		return ans;
	};

	auto pre = possible_positions(s);
	reverse(s.begin(), s.end());
	auto suf = possible_positions(s);
	reverse(suf.begin(), suf.end());

	long long ans = 0;
	int cur = 0;

	for (int i = 0; i < n; i ++) {
		cur += pre[i];
		ans += cur * suf[i + 1];
	}

	cout << ans;

	return 0;
}