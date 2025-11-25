#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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
		string s;
		cin >> s;

		bool flg = false;
		for (auto &c: s) {
			if (c == '0') {
				flg = true;
			}
		}

		if (!flg) cout << 0 << '\n';
		else {
			int n = s.size();

			vector<vector<int>> next_pos(10, vector<int>(n + 1, n));

			for (int i = n - 1; i >= 0; i --) {
				for (int j = 0; j < 10; j ++) {
					next_pos[j][i] = next_pos[j][i + 1];
				}
				next_pos[s[i] - '0'][i] = i;
			}

			vector<int> later_longest_full(n + 1, 0);
			later_longest_full[n] = -1;

			vector<int> cnt(10, 0);
			int cur = 0, res = 0;

			for (int i = n - 1; i >= 0; i --) {
				later_longest_full[i] = res;

				if (!cnt[s[i] - '0']) {
					cnt[s[i] - '0'] = 1;
					cur ++;
				}

				if (cur == 10) {
					cur = 0;
					res ++;
					for (int j = 0; j < 10; j ++) {
						cnt[j] = 0;
					}
				}
			}

			int pos = 0;

			while (pos <= n) {
				int mi = n + 5, choice = -1;

				for (int i = (pos ? 0 : 1); i < 10; i ++) {
					if (later_longest_full[next_pos[i][pos]] < mi) {
						mi = later_longest_full[next_pos[i][pos]];
						choice = i;
					}
				}

				cout << choice;
				pos = next_pos[choice][pos] + 1;
			}
			cout << '\n';
		}
	}

	return 0;
}