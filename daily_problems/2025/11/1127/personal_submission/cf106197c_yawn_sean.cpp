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

	int n;
	cin >> n;

	auto query = [&] (int x, int y) -> int {
		cout << "? " << x << ' ' << y << endl;
		int val;
		cin >> val;
		return val;
	};

	int pos1 = 1;

	for (int i = 2; i <= n; i ++) {
		if (query(pos1, i) != pos1) {
			pos1 = i;
		}
	}

	vector<int> cur, ans;

	for (int i = 1; i <= n; i ++) {
		if (i != pos1) {
			cur.emplace_back(i);
		}
	}

	while (!cur.empty()) {
		vector<int> ncur;
		int prime_val = cur[0];

		for (int i = 1; i < cur.size(); i ++) {
			int val = query(prime_val, cur[i]);

			if (val == cur[i]) prime_val = val;
			else if (val == pos1) ncur.emplace_back(cur[i]);
		}

		cur.swap(ncur);
		ans.emplace_back(prime_val);
	}

	cout << "! " << ans.size();

	for (auto &x: ans) cout << ' ' << x;

	return 0;
}