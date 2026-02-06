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

	auto query = [&] (int x, long long y) -> bool {
		cout << "? " << x << ' ' << y << endl;
		string s;
		cin >> s;
		return s[0] == 'b';
	};

	int w;
	long long h;
	cin >> w >> h;

	vector<int> to_check(w);
	iota(to_check.begin(), to_check.end(), 1);
	shuffle(to_check.begin(), to_check.end(), random_device());

	int idx = 1;
	long long cur_h = 0;

	for (auto &i: to_check) {
		if (cur_h < h && query(i, cur_h + 1)) {
			long long l = cur_h + 1, r = h;

			while (l <= r) {
				long long mid = (l + r) / 2;
				if (query(i, mid)) l = mid + 1;
				else r = mid - 1;
			}

			idx = i, cur_h = r;
		}
	}

	cout << "! " << idx << ' ' << cur_h;

	return 0;
}