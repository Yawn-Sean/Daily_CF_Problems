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

	int n;
	cin >> n;

	map<int, int> mp;
	mp[4] = 1, mp[8] = 2, mp[15] = 3, mp[16] = 4, mp[23] = 5, mp[42] = 6;

	vector<int> cnt(7, 0);
	cnt[0] = n;

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;

		x = mp[x];
		if (cnt[x - 1]) cnt[x - 1] --, cnt[x] ++;
	}

	cout << n - 6 * cnt[6];

	return 0;
}