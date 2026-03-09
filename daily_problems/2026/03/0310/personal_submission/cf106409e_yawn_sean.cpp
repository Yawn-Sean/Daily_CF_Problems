#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

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

	int t;
	cin >> t;

	while (t --) {
		string s;
		cin >> s;

		int n = s.size();

		vector<int> cnt(26, 0);
		for (auto &c: s) cnt[c - 'a'] ++;

		for (auto &x: cnt) x /= 2;

		long long ans = 0;
		vector<int> former, latter;

		for (int i = 0; i < n; i ++) {
			if (cnt[s[i] - 'a']) {
				cnt[s[i] - 'a'] --;
				former.emplace_back(s[i] - 'a');
				ans += i;
			}
			else latter.emplace_back(s[i] - 'a');
		}

		ans -= 1ll * (n / 2) * (n / 2 - 1) / 2;

		vector<vector<int>> pos1(26), pos2(26);

		for (int i = 0; i < n / 2; i ++) {
			pos1[former[i]].emplace_back(i);
			pos2[latter[i]].emplace_back(i);
		}

		vector<int> tmp(n / 2);
		for (int i = 0; i < 26; i ++) {
			for (int j = 0; j < pos1[i].size(); j ++) {
				tmp[pos1[i][j]] = pos2[i][j];
			}
		}

		atcoder::fenwick_tree<int> fen(n / 2);

		for (int i = 0; i < n / 2; i ++) {
			ans += fen.sum(tmp[i] + 1, n / 2);
			fen.add(tmp[i], 1);
		}

		cout << ans << '\n';
	}

	return 0;
}