#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	vector<long long> acc1(n + 1, 0), acc2(n + 1, 0);
	for (int i = 0; i < n; i ++) acc1[i + 1] = acc1[i] + v1[i];
	for (int i = 0; i < n; i ++) acc2[i + 1] = acc2[i] + v2[i];

	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		bool flg = true;
		long long diff = 0;

		for (int i = 0; i < n; i ++) {
			diff = min(acc1[i] - acc2[max(i - mid, 0)], diff);
			if (acc2[min(i + mid + 1, n)] - acc1[i + 1] + diff < 0) flg = false;
		}

		if (flg) r = mid - 1;
		else l = mid + 1;
	}

	cout << (l < n ? l : -1);

	return 0;
}