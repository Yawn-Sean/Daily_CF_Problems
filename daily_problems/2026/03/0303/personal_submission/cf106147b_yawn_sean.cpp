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

	auto query = [&] (vector<int> &vals) -> int {
		cout << "? " << vals.size();
		for (auto &v: vals) cout << ' ' << v;
		cout << endl;
		int x; cin >> x;
		return x;
	};

	vector<int> primes = {2, 3, 5, 7};
	vector<int> saved_vals(4);

	for (int i = 0; i < 4; i ++) {
		vector<int> vals = {1};
		while (vals.back() * primes[i] <= 30000)
			vals.emplace_back(vals.back() * primes[i]);
		saved_vals[i] = query(vals);
	}

	vector<int> candidates;
	
	for (int x = 1; x <= 30000; x ++) {
		bool flg = true;
		for (int i = 0; i < 4; i ++) {
			int v = x, cur = 0;
			while (v) {
				cur += v % primes[i];
				v /= primes[i];
			}
			if (cur != saved_vals[i]) flg = false;
		}
		if (flg) candidates.emplace_back(x);
	}

	int l = 0, r = candidates.size() - 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		vector<int> vals = {1};
		while (vals.back() * 2 <= candidates[mid])
			vals.emplace_back(vals.back() * 2);
		for (int i = mid; i <= r; i ++) {
			if (__popcount(candidates[i]) != 1) {
				vals.emplace_back(candidates[i]);
			}
		}
		if (query(vals) == 1) l = mid + 1;
		else r = mid - 1;
	}

	cout << "! " << candidates[r];

	return 0;
}