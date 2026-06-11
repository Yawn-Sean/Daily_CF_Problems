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

	vector<vector<int>> cnt(3, vector<int>(3, 0));
	long long ans = 0;
	int cur1 = 0, cur2 = 0;

	cnt[0][0] = 1;

	while (n --) {
		int x;
		cin >> x;

		x %= 3;
		cur1 = (cur1 + x) % 3;
		cur2 = (cur2 + x * x) % 3;

		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				int v1 = (cur1 - i) % 3;
				int v2 = (cur2 - j) % 3;

				if ((v1 * v1 - v2) % 3 == 0) ans += cnt[i][j];
			}
		}

		cnt[cur1][cur2] ++;
	}

	cout << ans;

	return 0;
}