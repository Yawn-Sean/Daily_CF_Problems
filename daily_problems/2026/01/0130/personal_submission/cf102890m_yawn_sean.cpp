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

	vector<int> cnt(10);
	for (int i = 1; i < 10; i ++) cin >> cnt[i];

	int n = s.size();

	vector<vector<int>> acc(10, vector<int>(n + 1, 0)), next_pos(10, vector<int>(n + 1, n));

	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < 10; j ++) {
			next_pos[j][i] = next_pos[j][i + 1];
			acc[j][i] = acc[j][i + 1];
		}
		next_pos[s[i] - '0'][i] = i;
		acc[s[i] - '0'][i] ++;
	}

	for (auto &c: s) cnt[c - '0'] --;

	int total = 0;
	for (int i = 0; i < 10; i ++) {
		cnt[i] = -cnt[i];
		total += cnt[i];
	}

	int pt = 0;
	while (total --) {
		for (int i = 9; i > 0; i --) {
			int npt = next_pos[i][pt];
			bool flg = true;

			for (int j = 0; j < 9; j ++) {
				if (acc[j][npt] < cnt[j]) {
					flg = false;
				}
			}

			if (flg && cnt[i]) {
				cout << i;
				cnt[i] --;
				pt = npt + 1;
				break;
			}
		}
	}

	return 0;
}