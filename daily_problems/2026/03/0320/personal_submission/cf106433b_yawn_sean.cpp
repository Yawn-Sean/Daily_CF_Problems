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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n), vis(n + 1, 0);
		for (auto &x: nums) cin >> x, vis[x] = 1;

		vector<int> mapping(n + 1, 0);
		int pt = 1;
		for (auto &x: nums) {
			if (!mapping[x]) mapping[x] = pt ++;
			cout << mapping[x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}