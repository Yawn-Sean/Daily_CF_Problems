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

	int n, m, k;
	cin >> n >> m >> k;

	if (n == m) cout << 1;
	else {
		int v = abs(n - m);

		auto add_val = [&] (vector<int> &v1, vector<int> &v2) -> vector<int> {
			vector<int> cur;
			int n1 = v1.size(), n2 = v2.size();

			int carry = 0;
			for (int i = 0; i < max(n1, n2); i ++) {
				if (i < n1) carry += v1[i];
				if (i < n2) carry += v2[i];
				cur.emplace_back(carry & 1);
				carry >>= 1;
			}

			if (carry) cur.emplace_back(carry);

			return cur;
		};

		vector<vector<int>> combs = {{1}};

		for (int i = 1; i <= k; i ++) {
			vector<vector<int>> ncombs(i + 1);
			ncombs[0] = {1};
			ncombs[i] = {1};

			for (int j = 1; j < i; j ++)
				ncombs[j] = add_val(combs[j - 1], combs[j]);
			
			combs.swap(ncombs);
		}

		vector<int> carry;
		int ans = 0;

		for (auto &x: combs) {
			x = add_val(x, carry);

			int val = min(v, (int)x.size());
			vector<int> ncarry;

			for (int i = 0; i < x.size(); i ++) {
				if (i < val) ans += x[i];
				else ncarry.emplace_back(x[i]);
			}

			carry.swap(ncarry);
		}

		for (auto &x: carry) ans += x;

		cout << ans;
	}

	return 0;
}